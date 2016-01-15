#include <stdio.h>

int main(void)
{
	int* pi = (int*)0xbf8b547c;
	printf("pi = %p,*pi = %d\n",pi,*pi);
	return 0;
}
