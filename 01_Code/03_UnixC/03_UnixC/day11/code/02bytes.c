//小端系统和大端系统的概念
#include <stdio.h>

typedef union
{
	int x;
	char buf[4];
}Un;

int main(void)
{
	Un un;
	un.x = 0x12345678;
	int i = 0;
	for(i = 0; i < 4; i++)
	{
		printf("%#x[%p] ",un.buf[i],&un.buf[i]);
	}
	printf("\n");
	printf("&x = %p\n",&un.x);
	printf("buf = %p\n",un.buf);
	return 0;
}



