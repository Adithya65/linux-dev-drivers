#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int print_hello_init(void)
{
    printk(KERN_INFO"%s: In init \n",__func__);
    return 0;
}

static void print_hello_exit(void)
{
    printk(KERN_INFO"%s: In exit \n",__func__);
}

module_init( print_hello_init );
module_exit( print_hello_exit );
