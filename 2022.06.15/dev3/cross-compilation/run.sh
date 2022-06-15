gcc hello.c -o hello_native
./hello_native

aarch64-linux-gnu-gcc hello.c -o hello_arm
qemu-aarch64 -L /usr/aarch64-linux-gnu/ ./hello_arm
