#include <stdio.h>
#include <signal.h> //1

void fa(int signo){//2
  printf("变型金刚4很好看\n");
}
int main(){
  signal(SIGALRM,fa);
  printf("pid=%d\n",getpid());
  while(1);
}

