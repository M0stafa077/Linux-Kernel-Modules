#include <linux/init.h>
#include <linux/module.h>
#include <linux/hash.h>
#include <linux/gcd.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mstafa Asaad");
MODULE_DESCRIPTION("My first linux kernel module :)");

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello from Mostafa :)\n");
	printk(KERN_INFO "Golden Ratio Prime Macro is %llu\n", GOLDEN_RATIO_PRIME);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO "Greatest Common Divisor of %d and %d is %.2lu\n", 3300, 24, gcd(3300, 24));
	printk(KERN_INFO "Good Bye Kernel ')\n");
}

module_init(hello_init);
module_exit(hello_exit);
