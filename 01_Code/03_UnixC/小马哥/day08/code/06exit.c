//各种exit函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void show(void)
{
	printf("let me give you some color to see see\n");
}

int main(void)
{
	atexit(show);
	printf("主函数开始...\n");
	//立即终止当前进程
	//_Exit(0);
	//_exit(0);
	exit(0);
	printf("主函数结束\n");
	return 0;
}
