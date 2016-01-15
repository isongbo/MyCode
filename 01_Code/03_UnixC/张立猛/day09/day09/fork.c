#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
}
int main(){
  //pid_t pid = fork();//子进程自定义
  signal(SIGINT,fa);
  if(signal(SIGQUIT,SIG_IGN)==SIG_ERR)
    perror("signal"),exit(-1);
  pid_t pid = fork();//通过继承改信号处理
  if(pid == 0){//子进程执行的分支
    printf("pid=%d\n",getpid());
	while(1);
  }//练习：测试一下vfork()+execl()的效果
  printf("父进程结束\n");
  return 0;
}

