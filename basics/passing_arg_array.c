#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int arg_count;
static int param_array[10];
module_param_array(param_array,int,&arg_count,S_IWUSR| S_IRUSR);

static int args_init(void)
{
    for( int i = 0; i < arg_count; i++ )
    {
        printk("%d:\t%d\n", i, param_array[i]);
    }
    return 0;
}

static void args_exit(void)
{
    printk("Exiting \n");
}

module_init(args_init);
module_exit(args_exit);

