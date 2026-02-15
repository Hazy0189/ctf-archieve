void sub_400010(void)
{
    __x86_return_thunk();
    return;
}

typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    unsigned long long field_0;
} struct_2;

extern unsigned long long g_400ac0;

void sub_400020(void)
{
    if (g_400ac0)
    {
        if (!*((int *)(g_400ac0 + 16)) && *((long long *)g_400ac0))
            __free_pages(*((long long *)g_400ac0), 0);
        kfree();
        g_400ac0 = 0;
    }
    __x86_return_thunk();
    return;
}

typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

extern char g_400ac0;

void sub_400080(unsigned long a0, unsigned long long *a1)
{
    if (*((long long *)&g_400ac0) && !*((int *)(*((long long *)&g_400ac0) + 16)) && *((long long *)*((long long *)&g_400ac0)) && a1[1] - *(a1) <= 0x1000)
    {
        if (!(int)remap_pfn_range())
            __x86_return_thunk();
        else
            __x86_return_thunk();
        return;
    }
    __x86_return_thunk();
    return;
}

typedef struct struct_0 {
    char padding_0[16];
    unsigned int field_10;
} struct_0;

typedef struct struct_1 {
    unsigned long long field_0;
} struct_1;

typedef struct struct_2 {
    char padding_0[16];
    unsigned int field_10;
} struct_2;

typedef struct struct_3 {
    unsigned long long field_0;
    struct struct_4 *field_8;
    unsigned int field_10;
} struct_3;

typedef struct struct_4 {
    unsigned long long field_0;
    char padding_8[4080];
    unsigned long long field_ff8;
} struct_4;

extern unsigned long long g_400ac0;
extern char g_500050;
extern char page_offset_base;
extern char vmemmap_base;

void sub_400100(unsigned long a0, unsigned int a1)
{
    unsigned long long *addr;  // rax
    unsigned long long v2;  // rax
    struct_3 *ptr;  // rdi
    unsigned long long v4;  // rcx
    unsigned long long p[512];  // rcx
    unsigned long long cur;  // rdi
    unsigned long long v7;  // rcx

    if (a1 != 1259265)
    {
        if (a1 == 1259266 && g_400ac0 && !*((int *)(g_400ac0 + 16)))
        {
            __free_pages(*((long long *)g_400ac0), 0);
            *((unsigned int *)(g_400ac0 + 16)) = 1;
            __x86_return_thunk();
            return;
        }
        __x86_return_thunk();
        return;
    }
    else if (!g_400ac0)
    {
        addr = kmalloc_trace(*((long long *)&g_500050), 3520, 24);
        g_400ac0 = addr;
        if (!g_400ac0)
        {
            __x86_return_thunk();
            return;
        }
        v2 = alloc_pages(3264, 0);
        ptr = g_400ac0;
        *(addr) = v2;
        if (!ptr->field_0)
        {
            kfree();
            g_400ac0 = 0;
            __x86_return_thunk();
            return;
        }
        v4 = ptr->field_0 - *((long long *)&vmemmap_base);
        ptr->field_10 = 0;
        p = (v4 >> 6) * 0x1000 + *((long long *)&page_offset_base);
        ptr->field_8 = p;
        cur = &p[1] & 18446744073709551608;
        p[0] = 4702111234474983745;
        p[511] = 4702111234474983745;
        for (v7 = (unsigned int)(unsigned long long [512])((char *)p - cur) + 0x1000 >> 3; v7; cur += 8)
        {
            v7 -= 1;
            *((unsigned long *)cur) = 4702111234474983745;
        }
        __x86_return_thunk();
        return;
    }
    else
    {
        __x86_return_thunk();
        return;
    }
}

extern char g_4005c0;

void init_module(void)
{
    misc_register(&g_4005c0);
    return;
}

extern char g_4005c0;

void cleanup_module(void)
{
    misc_deregister(&g_4005c0);
    return;
}

