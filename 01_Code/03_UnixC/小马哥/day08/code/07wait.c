//wait函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	//创建一个子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	if(0 == pid) //子进程
	{
		printf("子进程%d开始运行，将休眠10秒\n",getpid());
		sleep(10);
		printf("子进程运行结束\n");
		exit(100);
	}
	//下面的代码由父进程执行
	printf("开始等待子进程...\n");
	int status = 0;
	int res = wait(&status);
	printf("等待进程结束\n");
	printf("status = %d,res = %d\n",status,res);
	if(WIFEXITED(status))
	{
		printf("进程正常结束\n");
	}
	printf("子进程结束的退出码是：%d\n",WEXITSTATUS(status));
	return 0;
}
