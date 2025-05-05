#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("r1ru");
MODULE_DESCRIPTION("xcache - TsukuCTF 2025");

#define CMD_ALLOC   0xf000
#define CMD_WRITE   0xf001
#define CMD_FREE    0xf002

#define OBJ_MAX     0x200
#define OBJ_SIZE    0x200

typedef struct {
    int id;
    size_t size;
    char *data;
} request_t;

struct obj {
    char buf[OBJ_SIZE];
};

static struct obj *objs[OBJ_MAX];
static struct kmem_cache *obj_cachep;
static DEFINE_MUTEX(module_lock);

static long obj_alloc(int id) {
    if (objs[id] != NULL) {
        return -1;
    }
    objs[id] = kmem_cache_zalloc(obj_cachep, GFP_KERNEL);
    if (objs[id] == NULL) {
        return -1;
    }
    return 0;
}

static long obj_write(int id, char *data, size_t size) {
    if (objs[id] == NULL || size > OBJ_SIZE) {
        return -1;
    }
    if (copy_from_user(objs[id]->buf, data, size) != 0) {
        return -1;
    }
    return 0;
}

static long obj_free(int id) {
    kmem_cache_free(obj_cachep, objs[id]);
    return 0;
}

static long module_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    request_t req;
    long ret;
    if (copy_from_user(&req, (void *)arg, sizeof(req)) != 0) {
        return -1;
    }
    if (req.id < 0 || req.id > OBJ_MAX - 1) {
        return -1;
    }
    mutex_lock(&module_lock);
    switch(cmd) {
        case CMD_ALLOC:
            ret = obj_alloc(req.id);
            break;
        case CMD_WRITE:
            ret = obj_write(req.id, req.data, req.size);
            break;
        case CMD_FREE:
            ret = obj_free(req.id);
            break;
        default:
            ret = -1;
            break;
    }
    mutex_unlock(&module_lock);
    return ret;
}

static struct file_operations module_fops = {
    .unlocked_ioctl = module_ioctl,
};

static struct miscdevice vuln_dev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = "vuln",
    .fops = &module_fops
};

static int __init module_initialize(void) {
    if (misc_register(&vuln_dev) != 0) {
        return -1;
    }
    obj_cachep = KMEM_CACHE(obj, 0);
    if (!obj_cachep) {
        return -1;
    }
    return 0;
}

static void __exit module_cleanup(void) {
    misc_deregister(&vuln_dev);
    mutex_destroy(&module_lock);
}

module_init(module_initialize);
module_exit(module_cleanup);