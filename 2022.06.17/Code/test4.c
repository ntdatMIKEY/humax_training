#include <stdio.h>
#include <stdlib.h>

#define MAX_MEM 64000000

unsigned long getAvalableMemory()
{
	unsigned long ret = 0;
	// your code goes here
	unsigned long _mem = MAX_MEM / 2;
	unsigned int *ptr;

	while (1)
	{
		ptr = (int *)malloc(ret + _mem);

		// van cap phat duoc
		if (ptr != NULL)
		{
			ret += _mem;
			free(ptr);
		}
		else
		{
			if (_mem == 1)
			{
				break;
			}
			_mem /= 2;
		}
	}
	return ret;
}

unsigned long getAvalableMemoryT()
{
	unsigned long ret = 0;
	// your code goes here
	unsigned long _mem = 1;
	unsigned int *ptr;
	unsigned int *last_ptr;
	while (1)
	{
		ptr = (int *)malloc(_mem);
		
		// van cap phat duoc
		if (ptr != NULL)
		{
			// if(last_ptr != ptr)
			// {
			// 	printf("%p\n", ptr);
			// 	last_ptr = ptr;
			// }
			free(ptr);
			_mem++;
		}
		else
		{
			break;
		}
	}

	ret = _mem;
	return ret;
}

int main()
{
	printf("abc\n");
	//printf("%ld\n", getAvalableMemory());
	
	printf("%ld\n", getAvalableMemoryT());
	//printf("%ld\n", getAvalableMemory());
	int *a = malloc(100*sizeof(int));
	printf("%ld\n", getAvalableMemoryT());
	//printf("%ld\n", getAvalableMemory());
}