#include <linux/module.h>
#include <linux/kernel.h>

int init_t1_module(void){
	printk("Good morning ve482!\n");
	return 0;
}

void exit_t1_module(void){
	printk("Good night ve482!\n");
}

MODULE_LICENSE("GPL");
module_init(init_t1_module);
module_exit(exit_t1_module);
