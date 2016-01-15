#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  pid_t pid = vfork();
  if(pid == 0){
	printf("子进程开始运行\n");
    execl("/bin/ls","ls",NULL);
	exit(0);//要写，execl出错时要退出
  }
  printf("父进程继续运行\n");
}


