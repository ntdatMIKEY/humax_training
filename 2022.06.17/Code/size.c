#include <stdio.h>

struct A
{
	int a:2;
	char b;
};

union Au
{
	struct{
		int a:2;
	}as;
	char b;
};

int main()
{
	struct A x;
	union Au y;
	printf("addr of a: %p\n", &y.as);
	printf("addr of b: %p\n", &y.b);
	return 0;
}
