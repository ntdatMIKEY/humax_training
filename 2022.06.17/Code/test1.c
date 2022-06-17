#include <stdio.h>

#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80
union _register
{
	struct _bits
	{
		unsigned char BIT_7 : 1;
		unsigned char BIT_6 : 1;
		unsigned char BIT_5 : 1;
		unsigned char BIT_4 : 1;
		unsigned char BIT_3 : 1;
		unsigned char BIT_2 : 1;
		unsigned char BIT_1 : 1;
		unsigned char BIT_0 : 1;
	} bits;
	unsigned char value;
};
void setVaue(union _register *reg, unsigned char bit, unsigned char value)
{
	reg->value = value ? reg->value | (1 << bit) : reg->value & ~(1 << bit);
}

int main()
{
	union _register REG_A;
	printf("%d\n", REG_A.value);
	// your code goes here to test implemented function
	setVaue(&REG_A, BIT1, 1);
	printf("%d\n", REG_A.value);

	setVaue(&REG_A, BIT1, 0);
	printf("%d\n", REG_A.value);

	return 0;
}
