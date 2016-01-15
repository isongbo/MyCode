#include <stdio.h>
#include <signal.h> //1

void fa(int signo){//2
  printf("捕获了信号%d\n",signo);
}
int main(){
  signal(SIGINT,fa);//3 信号2到来执行fa
  signal(SIGQUIT,SIG_IGN);//信号3被忽略
  signal(SIGKILL,fa);//signal信号9 无效
  printf("pid=%d\n",getpid());
  while(1);
}

