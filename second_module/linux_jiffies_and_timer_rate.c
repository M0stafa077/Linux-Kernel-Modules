#include <linux/init.h>
#include <linux/module.h>
#include <asm/param.h>
#include <linux/jiffies.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mostafa Asaad");
MODULE_DESCRIPTION("Second Linux Kernel Module");

static int __init init_simple(void)
{
	printk(KERN_INFO "Hello Kernel from Mostafa\n");
	printk(KERN_INFO "The Value of HZ is %d\n", HZ);
	printk(KERN_INFO "The Value of jiffies on init is %ld\n", jiffies);
	return 0;
}

static void __exit exit_simple(void)
{
	printk(KERN_INFO "The Value of jiffies on exit is %ld\n", jiffies);
	printk(KERN_INFO "Good Bye Kernel from Mostafa\n");
}

module_init(init_simple);
module_exit(exit_simple);
