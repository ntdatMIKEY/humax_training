#include <stdio.h>

void f(int (*x)(int));
int myfoo(int);
int (*fooptr)(int);
int((*foo(int)))(int);

int((*foo(int i)))(int)
{
	return myfoo;
}

int myfoo(int i)
{
	printf("%d\n", i + 1);
}
int main()
{
	int i = 10;
	// your code goes here
	//one level access
	fooptr = myfoo;
	fooptr(i);

	//two level access
	fooptr = foo(100); // assign fooptr = myfoo
	fooptr(i);				 // now fooptr(i) = myfoo(i);

	return 0;
}
