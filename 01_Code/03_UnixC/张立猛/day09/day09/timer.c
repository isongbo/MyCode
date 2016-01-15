#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
  printf("想干啥都行\n"); }
int main(){
  signal(SIGALRM,fa);
  struct itimerval it;
  it.it_interval.tv_sec=1;//间隔秒数
  it.it_interval.tv_usec=100000;//微秒
  it.it_value.tv_sec = 3;//开始秒数
  it.it_value.tv_usec = 0;
  setitimer(ITIMER_REAL,&it,0);
  while(1);
}

