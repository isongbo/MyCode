//execl和vfork搭配使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid = vfork();
	if(0 == pid)//子进程
	{
		printf("子进程%d开始运行\n",getpid());
		//sleep(5);
		//相当于子进程跳转出去执行
		//execl("/bin/ls","ls","-l",NULL);
		execl("./pro","pro",NULL);
		printf("子进程结束\n");
		//如果没有exit,子进程执行return 0之后，可能会造成死循环，结果不可预知
		exit(0);
	}
	printf("父进程开始运行\n");
	printf("父进程结束\n");
	return 0;
}
