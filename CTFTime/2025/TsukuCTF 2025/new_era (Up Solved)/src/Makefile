obj-m := vuln.o
KERNEL_DIR := ~/linux-6.13.9
LLVM_PATH = ~/llvm-project/build/bin/

all:
	$(MAKE) -C $(KERNEL_DIR) M=$(shell pwd) LLVM=$(LLVM_PATH) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(shell pwd) clean