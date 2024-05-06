#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/jiffies.h>
#include <asm/param.h>

#define BUFFER_SIZE     256
#define PROC_NAME       "seconds"

ssize_t proc_read(struct file *file, char __user *user_buf, size_t count, loff_t *off);