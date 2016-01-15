//access函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	if(0 == access("a.txt",R_OK))
	{
		printf("该文件可读\n");
	}
	if(0 == access("a.txt",W_OK))
	{
		printf("该文件可写\n");
	}
	if(0 == access("a.txt",X_OK))
	{
		printf("该文件可执行\n");
	}
	if(0 == access("a.txt",F_OK))
	{
		printf("该文件确实存在\n");
	}
	return 0;
}
