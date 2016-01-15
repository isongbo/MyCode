//waitpid函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	//创建2个子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	pid_t pid2;
	if(0 != pid)//父进程
	{
		pid2 = fork();
	}
	if(0 == pid) //子进程1
	{
		printf("子进程一开始运行,PID = %d\n",getpid());
		sleep(3);
		printf("子进程一结束运行\n");
		exit(100); //子进程结束
	}
	if(0 == pid2) //子进程2
	{
		printf("子进程二开始运行,PID = %d\n",getpid());
		sleep(5);
		printf("子进程二结束运行\n");
		exit(200); //子进程结束
	}
	//父进程
	printf("父进程开始等待...\n");
	int status = 0;
	//等待任意一个子进程结束
	int res = wait(&status);
	//表示等待任意一个子进程结束
	//int res = waitpid(-1,&status,0);
	//等待子进程二结束
	//int res = waitpid(pid2,&status,0);
	//等待子进程一结束,与等待任意一个子进程的效果相同
	//int res = waitpid(pid,&status,0);
	if(-1 == res)
	{
		perror("waitpid"),exit(-1);
	}
	if(WIFEXITED(status))
	{
		printf("进程%d总算结束了,退出状态信息是：%d\n",res,WEXITSTATUS(status));
	}
	return 0;
}
