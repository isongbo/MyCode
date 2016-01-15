//测试程序
#include <stdio.h>

int main(void)
{
		int* pi = (int*)0xbf86095c;
		//段错误,这里是新的程序，还没有建立内存映射
		printf("*pi = %d\n",*pi);
		return 0;
}
