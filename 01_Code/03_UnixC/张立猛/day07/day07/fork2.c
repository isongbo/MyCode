#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  printf("fpid=%d\n",getpid());
  pid_t pid = fork();//父进程返回子进程的
  if(pid==-1) perror("fork"),exit(-1);
  printf("pid=%d\n",pid);//PID,子进程返0
}//练习：用if/else让父子进程执行不同的
//代码，父进程中打印我是父进程xx,子进程是
//xx,子进程中打印我是子进程xx,父进程是xx
//xx就是进程的pid

