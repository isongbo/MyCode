#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
}
int main(){
  signal(SIGINT,fa);
  int res = sleep(10);//可以被信号打断
  printf("res=%d\n",res);
  printf("main()\n");
}

