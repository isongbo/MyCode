#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
}
int main(){
  signal(SIGINT,fa);
  if(signal(SIGQUIT,SIG_IGN)==SIG_ERR)
    perror("signal"),exit(-1);
  pid_t pid=vfork();
  if(pid == 0){//子进程执行的分支
    printf("pid=%d\n",getpid());
	execl("./b.out","b.out",NULL);
	perror("execl");
	exit(-1);
  }
  printf("父进程结束\n");
  return 0;
}

