obj-m := t1.o
CROSS_COMPILE = 
KERNELDIR ?= /usr/src/linux-headers-$(shell uname -r)
PWD := $(shell pwd)

all: modules

modules: 
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.o *~ core .depend *.symvers .*.cmd *.ko *.mod.c .tmp_versions $(TARGET)
