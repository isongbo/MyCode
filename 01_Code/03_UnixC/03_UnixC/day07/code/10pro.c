//execl执行的文件
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	printf("pid = %d\n",getpid());
	int i = 0;
	for(i = 0; i < 10; i++)
	{
		printf("使用execl函数就是任性\n");
		sleep(1);
	}
	return 0;
}
