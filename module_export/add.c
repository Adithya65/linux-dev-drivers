#include <linux/kernel.h>
#include <linux/module.h>

int var_export = 6;
MODULE_LICENSE("GPL");

int myAdd(int a , int b)
{
    return a + b;
}

EXPORT_SYMBOL(myAdd);
EXPORT_SYMBOL(var_export);

static int export_init(void)
{
    return 0;
}

static void export_exit(void)
{
}

module_init(export_init);
module_exit(export_exit);
