//进程的终止
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fa(void)
{
	printf("恭喜你踩到地雷了\n");
}

int main(void)
{
	//注册一个函数
	atexit(fa);
	printf("main开始执行\n");
	//_exit(0);//立即终止
	//_Exit(0); //立即终止
	exit(0); //调用注册函数
	printf("main函数结束\n");
	return 0;
}
