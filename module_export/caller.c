#include <linux/kernel.h>
#include <linux/module.h>

extern int  myAdd(int a , int b);
extern int var_export;

MODULE_LICENSE("GPL");

static int caller_init(void)
{
    printk(KERN_INFO "the value is %d \n",myAdd(1,2));
    printk(KERN_INFO "the value of exported symbol is %d\n",var_export);
    return 0;
}

static void  caller_exit(void)
{
}

module_init(caller_init);
module_exit(caller_exit);
