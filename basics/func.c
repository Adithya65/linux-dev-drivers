#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>

MODULE_LICENSE("GPL");

int major_minor_num_func_test(void)
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


