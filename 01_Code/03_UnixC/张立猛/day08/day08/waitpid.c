#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  pid_t pid1,pid2;
  pid1 = fork();
  if(pid1 > 0) pid2 = fork();
  if(pid1 == 0){
    printf("pid1=%d\n",getpid());
	sleep(2);
	printf("pid1 over\n"); exit(10); }
  if(pid2 == 0){
    printf("pid2=%d\n",getpid());
	sleep(5);
	printf("pid2 over\n"); exit(20); }
  int sta;//WNOHANG
  pid_t wpid=waitpid(pid2/*-1*/,&sta,0);
  printf("等到了子进程%d结束\n",wpid);
  if(WIFEXITED(sta))
    printf("exit=%d\n",WEXITSTATUS(sta));
  
}


