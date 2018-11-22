// SPDX-License-Identifier: GPL-2.0
#define DEBUG
#include <linux/module.h>
#include <linux/kernel.h>

int init_t4_module(void)
{
	pr_debug("Good morning ve482!\n");
	return 0;
}

void exit_t4_module(void)
{
	pr_debug("Good night ve482!\n");
}

MODULE_LICENSE("GPL");
module_init(init_t4_module);
module_exit(exit_t4_module);
