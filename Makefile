#obj-m := basics/hello.o basics/extract_major_minor_num.o basics/func.o
#linux-objs := basics/linux.o
#basics/extract_major_minor_num-objs := basics/func.o 

obj-m := basics/mymodule.o basics/passing_arg.o basics/passing_arg_array.o module_export/caller.o module_export/add.o char_dev_drivers/dev_drivers.o
basics/mymodule-objs :=  basics/extract_major_minor_num.o basics/func.o

all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

