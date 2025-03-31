#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

char* name = "Hello";
int loop_count = 1;

module_param(name,charp,S_IRUGO);
module_param(loop_count,int,S_IRUGO);

static int args_init(void)
{
    for( int i = 0; i < loop_count; i++ )
    {
        printk(KERN_INFO "Loop Count:%d\n",loop_count);
        printk(KERN_INFO "Name is %s\n",name);
    }
    return 0;
}

static void args_exit(void)
{
    printk("Exiting \n");
}

module_init(args_init);
module_exit(args_exit);

