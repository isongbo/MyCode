#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  pid_t pid = vfork();
  if(pid == 0){//vfork()确保子进程先运行
    printf("子进程%d运行\n",getpid());
	sleep(2);
	printf("子进程结束\n");
	exit(0);
  }
  printf("父进程%d继续运行\n",getpid());
}

