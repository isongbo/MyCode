#include <stdio.h>
#include <unistd.h>

int main(){
  pid_t pid = fork();
  if(pid==0){//父子进程都会判断,子进程进
    printf("我是子进程%d,父进程是%d\n",
	getpid(),getppid());
  }else{//父子进程都有,父进程进
    printf("我是父进程%d,子进程是%d\n",
	getpid(),pid);
  }
  //printf("over\n");
  return 0;
}

