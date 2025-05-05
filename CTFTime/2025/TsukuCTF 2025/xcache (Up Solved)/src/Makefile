obj-m := vuln.o
KERNEL_DIR := ~/buildroot-2024.02.11/output/build/linux-6.14.2
CROSS_COMPILE := ~/buildroot-2024.02.11/output/host/bin/x86_64-buildroot-linux-gnu- 

all:
	CROSS_COMPILE=$(CROSS_COMPILE) $(MAKE) -C $(KERNEL_DIR) M=$(shell pwd) modules

clean:
	CROSS_COMPILE=$(CROSS_COMPILE) $(MAKE) -C $(KERNEL_DIR) M=$(shell pwd) clean