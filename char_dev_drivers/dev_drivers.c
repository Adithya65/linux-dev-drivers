#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <linux/cdev.h>

dev_t dev;
struct class *class1;
struct cdev cdev;

MODULE_LICENSE("GPL");

static int device_open(struct inode *inode, struct file *file)
{
    pr_info("%s\n", __func__);
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    pr_info("%s\n", __func__);
    return 0;
}

static ssize_t device_read(struct file *file, char __user *user_buffer,
        size_t count, loff_t *offset)
{
    pr_info("%s\n", __func__);
    return 0;
}

static ssize_t device_write(struct file *file, const char __user *user_buffer,
        size_t count, loff_t *offset)
{
    pr_info("%s\n", __func__);
    return count;
}

struct file_operations device_fops = {
    .read = device_read,
    .write = device_write,
    .open = device_open,
    .release = device_release
};

static int driver_test_init(void)
{
    class1 = class_create("TestClass1");
    if(!alloc_chrdev_region(&dev,0 ,1, "driver1"))
    {
        device_create(class1,NULL,dev,NULL,"driver1");
    }
    cdev_init(&cdev, &device_fops);
    cdev_add(&cdev, dev, 1);
    pr_info("Driver loaded\n");
    return 0;
}

static void driver_exit(void)
{ 
    unregister_chrdev_region(dev, 1);
    device_destroy(class1, dev);
    cdev_del(&cdev);
    class_destroy(class1);
}

module_init(driver_test_init);
module_exit(driver_exit);

