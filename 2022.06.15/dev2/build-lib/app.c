#include <stdio.h>
#include <foo.h>

int main() {
	printf("Init foo = %d\n", getFoo());
	setFoo(5);
	printf("New foo = %d\n", getFoo());
	return 0;
}
