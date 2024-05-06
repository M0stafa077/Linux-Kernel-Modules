#include "hello.h"

static struct proc_ops proc_ops =
{
    .proc_read = proc_read,
};

int proc_init(void)
{
    proc_create(PROC_NAME, 0666, NULL, &proc_ops);
    printk(KERN_INFO "Loading proc module\n");

    return 0;
}

void proc_exit(void)
{
    remove_proc_entry(PROC_NAME, NULL);
    printk(KERN_INFO "Removing proc module\n");
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
    rv = snprintf(buffer, BUFFER_SIZE, "Hello World from Mostafa_Asaad\n");

    copy_to_user(user_buf, buffer, rv);

    return rv;
}

module_init(proc_init);
module_exit(proc_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("HELLO WORLD");
MODULE_AUTHOR("Mostafa_Asaad");
