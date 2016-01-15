#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
  //exit(0);
}
int main(){
  pid_t pid = fork();
  if(pid == 0){
    signal(SIGINT,fa);//确保signal先执行
	printf("cpid=%d\n",getpid());
    while(1);
  }
  sleep(1);
  kill(pid,SIGINT);
  printf("main over\n");
  kill(pid,SIGQUIT);//kill子进程
  return 0;
}

