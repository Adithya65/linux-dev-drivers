savedcmd_/home/adithya/Projects/linux/linux-dev-drivers/basics/hello.mod := printf '%s\n'   basics/hello.o | awk '!x[$$0]++ { print("/home/adithya/Projects/linux/linux-dev-drivers/"$$0) }' > /home/adithya/Projects/linux/linux-dev-drivers/basics/hello.mod
