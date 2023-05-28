#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>
#include<linux/stat.h>


MODULE_LICENSE("GPL");

static int argument = 0;
module_param(argument,int,S_IRUSR |S_IWUSR);
MODULE_PARM_DESC(argument,"test int parameter");

int __init startFun(void)
{
	printk(KERN_INFO "Hello world %d",argument);
	return 0;
}

void __exit endFun(void)
{
	printk(KERN_INFO "bye world");
}

module_init(startFun);
module_exit(endFun);
