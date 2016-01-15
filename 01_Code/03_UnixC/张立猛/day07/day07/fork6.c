#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  pid_t pid = fork();
  if(!pid){//子进程执行的分支
    printf("子进程%d的父进程是%d\n",
	  getpid(),getppid());
	sleep(3);
    printf("子进程%d的父进程是%d\n",
	  getpid(),getppid());
	exit(0); }
  sleep(1);
  printf("父进程%d结束\n",getpid());
}


