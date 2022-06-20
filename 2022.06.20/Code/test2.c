#include <stdio.h>
void main()
{
	char showMe[] = "HUMAX";
	int foo = 0;
	int bar = 0;

	// // Your code goes here
	// printf("showMe:\t\t %p\n", &showMe);
	// printf("foo addr:\t %p\n", &foo);
	// printf("bar addr:\t %p\n", &bar);	
//	printf("%d\t%d\t%d\n", sizeof(showMe), sizeof(bar), sizeof(foo));

	printf("%s\n", (char*)&bar + 6);

}                                                  
