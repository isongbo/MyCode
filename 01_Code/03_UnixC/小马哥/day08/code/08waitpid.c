//waitpid函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	//练习：要求创建两个子进程，加上父进程一共三个进程
	pid_t pid1,pid2;
	//创建一个子进程
	pid1 = fork();
	if(-1 == pid1)
	{
		perror("fork"),exit(-1);
	}
	//再创建一个子进程
	if(0 != pid1)
	{
		pid2 = fork();
	}
	//printf("test\n");
	if(0 == pid1) //子进程1
	{
		printf("子进程%d开始运行，即将进入睡眠...\n",getpid());
		sleep(10);
		printf("子进程%d结束\n",getpid());
		exit(100);
	}
	if(0 == pid2) //子进程2
	{
		printf("子进程%d开始运行...\n",getpid());
		sleep(5);
		printf("子进程%d结束\n",getpid());
		exit(200);
	}
	//下面由父进程执行
	printf("父进程开始等待...\n");
	int status = 0;
	//表示等待任意一个子进程，等待子进程2
	//int res = waitpid(-1,&status,0);
	//表示指定等待进程号为pid1的进程,子进程1
	//int res = waitpid(pid1,&status,0);
	//表示指定等待进程号为pid2的进程，子进程2
	int res = waitpid(pid2,&status,0);
	if(WIFEXITED(status))
	{
		printf("进程%d正常结束，退出码是：%d\n",res,WEXITSTATUS(status));
	}
	return 0;
}


