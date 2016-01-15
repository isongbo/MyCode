#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void fa(int signo){
  printf("偷了XX的菜园子\n"); }
int main(){
  signal(SIGALRM,fa);
  alarm(3);//3秒后产生一个SIGALRM信号
  printf("main()继续执行\n");
  sleep(2);
  alarm(5);//会替换掉以前的闹钟2+5
  sleep(1); alarm(0);
  while(1);
}

