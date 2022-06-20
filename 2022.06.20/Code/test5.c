#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int (*fp)(char *);
	if (argc != 2)
	{
		printf("insert 0xaddress\n");
		exit(-1);
	}
	// read input address
	// assign it to fp
	// ok, check the pointer
	if ((int (*)(char *)) & puts == fp)
	{
		fp("Well done! You had 'puts'. Excecuted it for you :)");
	}
	else
	{
		exit(-1);
	}
	eit(1);
}