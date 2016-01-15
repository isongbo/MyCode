#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  pid_t pid = fork();
  if(!pid){
    printf("子进程%d启动\n",getpid());
	sleep(2);
	printf("子进程%d结束\n",getpid());
    exit(100);  }//0-255有效
  int sta;
  pid_t wpid = wait(&sta);
  printf("父进程%d等待\n",getpid());
  printf("wpid=%d,status=%d\n",wpid,sta);
  if(WIFEXITED(sta)){//子进程是否正常退出
    printf("子进程的退出是正常的\n");
	printf("exit=%d\n",WEXITSTATUS(sta));
  }
}  


