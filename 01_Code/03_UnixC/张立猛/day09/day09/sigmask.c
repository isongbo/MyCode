#include <stdio.h>
#include <signal.h>

void fa(int signo){
  printf("捕获了信号%d\n",signo);
}
int main(){
  signal(SIGINT,fa);//不可靠信号,处理1次
  signal(45,fa);//可靠信号,处理n次
  printf("pid=%d\n",getpid());
  printf("执行普通代码，信号未屏蔽\n");
  sleep(15);
  printf("执行关键代码，信号屏蔽\n");
  sigset_t set,old;
  sigemptyset(&set);
  sigaddset(&set,2);sigaddset(&set,45);
  sigprocmask(SIG_SETMASK,&set,&old);
  sleep(15);
  sigset_t pend;
  sigpending(&pend);//把来过的信号放入
  if(sigismember(&pend,2)==1)
	 printf("信号2来过\n");
  if(sigismember(&pend,45)==1)
	 printf("信号45来过\n");
  printf("关键代码执行完毕，解除屏蔽\n");
  sigprocmask(SIG_SETMASK,&old,0);
  sleep(15);
}

