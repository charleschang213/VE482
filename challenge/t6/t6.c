#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include <linux/string.h>
#include "t6.h"

struct tmisc_dev{
	struct miscdevice misc;
	char *data;
	char *yes;
	char *no;
	char *readdata;
};

struct tmisc_dev *tmisc_devp;

int tmisc_open(struct inode *inode,struct file *filep){
	filep->private_data = tmisc_devp;
	return 0;
}

int tmisc_release(struct inode *inode,struct file *filep){
	return 0;
}

long tmisc_ioctl(struct file *filep,unsigned int cmd,unsigned long arg){
	int ret = 0;
	struct tmisc_dev *devp = (struct tmisc_dev*)(filep->private_data);
	switch(cmd){
		case T6_READ:
			ret = raw_copy_to_user((unsigned char*)arg,(unsigned char*)devp->data,strlen(devp->data));
			break;
		case T6_WRITE:
			ret = strncpy_from_user((unsigned char*)devp->readdata,(unsigned char*)arg,100);
			if (strcmp(devp->data,devp->readdata)==0)
				ret = raw_copy_to_user((unsigned char*)arg,(unsigned char*)devp->yes,strlen(devp->yes));
			else
				ret = raw_copy_to_user((unsigned char*)arg,(unsigned char*)devp->no,strlen(devp->no));
			break;
		default:
			return -EINVAL;
	}
	return ret;
}

static const struct file_operations tmisc_fops = {
	.owner = THIS_MODULE,
	.open = tmisc_open,
	.release = tmisc_release,
	.unlocked_ioctl = tmisc_ioctl,
};

static const struct miscdevice tmisc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "hobby",
	.fops = &tmisc_fops,
};

static int tmisc_init(void){
	printk("tmisc_init\n");
	tmisc_devp = kmalloc(sizeof(struct tmisc_dev),GFP_KERNEL);
	tmisc_devp->data = "ve482hobby!";
	tmisc_devp->yes = "correct value";
	tmisc_devp->no = "invalid value";
	tmisc_devp->misc = tmisc;
	tmisc_devp->readdata = kmalloc(100*sizeof(char),GFP_KERNEL);
	return misc_register(&(tmisc_devp->misc));
}

static void tmisc_exit(void){
	kfree(tmisc_devp->readdata);
	misc_deregister(&(tmisc_devp->misc));
	kfree(tmisc_devp);
	printk("tmisc_exit\n");
}

MODULE_LICENSE("GPL");
module_init(tmisc_init);
module_exit(tmisc_exit);
	
