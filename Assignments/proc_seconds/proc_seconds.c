#include "proc_seconds.h"

static unsigned long start_jiffies = 0;

static struct proc_ops proc_ops =
{
    .proc_read = proc_read,
};

int proc_init(void)
{
    proc_create(PROC_NAME, 0666, NULL, &proc_ops);
    printk(KERN_INFO "Loading proc/seconds module\n");

    start_jiffies = jiffies;

    return 0;
}

void proc_exit(void)
{
    remove_proc_entry(PROC_NAME, NULL);

    unsigned long time;
    time = (jiffies - start_jiffies) / HZ;

    printk(KERN_INFO "Time elapsed since the module is loaded %ld\n", time);
    printk(KERN_INFO "Removing proc/seconds module\n");
}

ssize_t proc_read(struct file *file, char __user *user_buf, size_t count, loff_t *off)
{
    int rv = 0;
    char buffer[BUFFER_SIZE];
    static int completed = 0;

    if (completed)
    {
        completed = 0;
        return 0;
    }

    completed = 1;

    unsigned long time_since_loaded;
    time_since_loaded = (jiffies - start_jiffies) / HZ;

    rv = snprintf(buffer, BUFFER_SIZE, "Time elapsed since the module is loaded %ld\n", time_since_loaded);

    copy_to_user(user_buf, buffer, rv);

    return rv;
}

module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("seconds");
MODULE_AUTHOR("Mostafa_Asaad");
