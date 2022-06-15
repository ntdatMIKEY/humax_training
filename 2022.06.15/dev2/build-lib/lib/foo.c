#include <stdio.h>
#include "foo.h"

int __foo;

void __attribute__ ((constructor)) constructorFoo();
void __attribute__ ((destructor )) destructorFoo();

void constructorFoo() {
	printf("Foo is Loaded!\n");
}

void destructorFoo() {
	printf("Foo is Unloaded!\n"); 
}

void setFoo(int f) {
	__foo = f;
}

int getFoo() {
	return __foo;
}
