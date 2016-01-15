//sbrk函数 和 brk函数的搭配使用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	int* pi = (int*)sbrk(sizeof(int));
	*pi = 100;
	double* pd =(double*)sbrk(sizeof(double));
	*pd = 3.14;
	char* pc = (char*)sbrk(10);
	strcpy(pc,"hello");

	printf("*pi = %d,*pd = %lf,pc = %s\n",*pi,*pd,pc);
	//释放所有内存
	brk(pi);
	return 0;
}
