#include <stdio.h>
#include "bar.h"

void callback() {
	printf("Callback in APP!\n");
}

void main() {
	run();
}
