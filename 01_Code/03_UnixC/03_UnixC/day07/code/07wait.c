//wait函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	//1.创建子进程
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork"),exit(-1);
	}
	//2.分别处理父子进行
	if(0 == pid) //子进程
	{
		printf("子进程%d开始执行\n",getpid());
		sleep(5);
		printf("子进程结束\n");
		exit(-100); //取低8位
	}
	printf("父进程开始等待...\n");
	int status = 0;
	int res = wait(&status);
	if(-1 == res)
	{
		perror("wait"),exit(-1);
	}
	printf("子进程%d总算结束了,status = %d,res = %d\n",pid,status,res);

	printf("结果是：%d\n",WIFEXITED(status));
	//判断子进程是否正常终止
	if(WIFEXITED(status))
	{
		//获取exit函数参数的低8位
		printf("子进程终止时的退出码是：%d\n",WEXITSTATUS(status));
	}
	return 0;
}



