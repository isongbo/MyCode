//system函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	//int res = system("ls -l");
	int res = system("./pro");
	if(-1 == res)
	{
		perror("system"),exit(-1);
	}
	return 0;
}
