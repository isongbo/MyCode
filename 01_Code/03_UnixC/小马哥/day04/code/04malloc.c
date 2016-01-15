//使用malloc分配内存的大小
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
		//表示调用getpid()函数来获取当前的进程号
		printf("pid = %d\n",getpid());
		int* pi = malloc(4);
		*pi = 118;
		printf("*pi = %d,pi = %p\n",*pi,pi);
		//接受一个字符 scanf("%c",&c);
		getchar();
		*(pi + 1000) = 250;
		printf("*(pi+1000) = %d\n",*(pi+1000));
		
		printf("------------------------\n");
		//此时可能引发段错误，超过33个内存页
		//*(pi + 33*4096) = 500;
		while(1);
		return 0;
}
