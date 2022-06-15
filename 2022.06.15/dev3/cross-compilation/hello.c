#include <sys/utsname.h>
#include <stdio.h>

int main() {
    struct utsname name;
    uname(&name);
    printf("Hello from %s\n",name.machine);
    return 0;
}
