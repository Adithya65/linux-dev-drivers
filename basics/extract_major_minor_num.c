#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>

MODULE_LICENSE("GPL");

static int major_minor_num_init(void)
{
    dev_t devicenumber;
    printk("Major Number :%d \n",MAJOR(devicenumber));
    printk("Minor Number :%d \n",MINOR(devicenumber));

    devicenumber = MKDEV(120,30);
    printk("Device Number :%ld\n",devicenumber);
    printk("Major Number:%d\n",MAJOR(devicenumber));
    printk("Minor Number:%d\n",MINOR(devicenumber));

    return 0;
}


static void major_minor_num_exit(void)
{
}


module_init(major_minor_num_init);
module_exit(major_minor_num_exit);
