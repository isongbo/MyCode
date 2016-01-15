// #pragma 的使用
#include <stdio.h>

//让当前文件依赖于 01hello.c
#pragma GCC dependency "01hello.c"

int main(void)
{
	printf("Good Good Study,Day Day Up!\n");
	return 0;
}
