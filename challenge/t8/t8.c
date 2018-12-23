#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/cred.h>
#include <linux/slab.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include <linux/string.h>
#include <linux/debugfs.h>
#include <linux/jiffies.h>
#include "t8.h"


struct tmisc_dev{
	struct miscdevice misc;
	char *data;
	char *yes;
	char *no;
	char *readdata;
};

char jiffies_out[32];

char info_data[1024];
struct tmisc_dev *tmisc_devp;

int tmisc_open(struct inode *inode,struct file *filep){
	filep->private_data = tmisc_devp;
	return 0;
}

int tmisc_release(struct inode *inode,struct file *filep){
	return 0;
}

struct dentry *myroot,*myfile1,*myfile2,*myfile3;

long tmisc_ioctl(struct file *filep,unsigned int cmd,unsigned long arg){
	int ret = 0;
	struct tmisc_dev *devp = (struct tmisc_dev*)(filep->private_data);
	switch(cmd){
		case T8_READ:
			ret = raw_copy_to_user((unsigned char*)arg,(unsigned char*)devp->data,strlen(devp->data));
			break;
		case T8_WRITE:
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


long info_ioctl(struct file *filep,unsigned int cmd,unsigned long arg){
	int ret = 0;
	switch(cmd){
		case T8_READ:
			ret = raw_copy_to_user((unsigned char*)arg,(unsigned char*)info_data,strlen(info_data));
			break;
		case T8_WRITE:
			if (current_uid().val==0)
				ret = strncpy_from_user((unsigned char*)info_data,(unsigned char*)arg,1024);
			break;
		default:
			return -EINVAL;
	}
	return ret;
}

long jiffies_ioctl(struct file *filep,unsigned int cmd,unsigned long arg){
	int ret = 0;
	long unsigned int js;
	switch(cmd){
		case T8_READ:
			js = jiffies;
			snprintf(jiffies_out,32,"%lu",js);
			ret = raw_copy_to_user((unsigned char*)arg,(unsigned char*)jiffies_out,strlen(jiffies_out)+1);
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

static const struct file_operations jiffies_fops = {
	.owner = THIS_MODULE,
	.open = tmisc_open,
	.release = tmisc_release,
	.unlocked_ioctl = jiffies_ioctl,
};


static const struct file_operations info_fops = {
	.owner = THIS_MODULE,
	.open = tmisc_open,
	.release = tmisc_release,
	.unlocked_ioctl = info_ioctl,
};

static int tmisc_init(void){
	myroot = debugfs_create_dir("ve482hobby",NULL);
	myfile1 = debugfs_create_file("hobby",0777,myroot,NULL,&tmisc_fops);
	myfile2 = debugfs_create_file("jiffies",0444,myroot,NULL,&jiffies_fops);
	myfile3 = debugfs_create_file("info",0777,myroot,NULL,&info_fops);
	printk("tmisc_init\n");
	tmisc_devp = kmalloc(sizeof(struct tmisc_dev),GFP_KERNEL);
	tmisc_devp->data = "ve482hobby!";
	tmisc_devp->yes = "correct value";
	tmisc_devp->no = "invalid value";
	tmisc_devp->readdata = kmalloc(100*sizeof(char),GFP_KERNEL);
	return 0;
}

static void tmisc_exit(void){
	debugfs_remove_recursive(myroot);
	kfree(tmisc_devp->readdata);
	kfree(tmisc_devp);
	printk("tmisc_exit\n");
}

MODULE_LICENSE("GPL");
module_init(tmisc_init);
module_exit(tmisc_exit);
	
