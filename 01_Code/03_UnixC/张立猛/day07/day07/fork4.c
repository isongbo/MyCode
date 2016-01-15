#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int i1 = 10;//全局区
int i2;//bss段
int main(){
  int i3 = 10;//栈
  int* pi = malloc(4);//堆
  *pi = 10;
  pid_t pid = fork();
  if(pid == 0){//子进程执行的分支
    i1 = 20; i2 = 20; i3= 20; *pi = 20;
	printf("child:i1=%d,i2=%d,i3=%d,"
	  "*pi=%d\n",i1,i2,i3,*pi);//20
	printf("child:&i1=%p,&i2=%p,&i3=%p,"
	  "pi=%p\n",&i1,&i2,&i3,pi);
	exit(0);//子进程到此结束
  }//"abc""d" == "abcd"
  sleep(1);//子进程先运行
  printf("father:i1=%d,i2=%d,i3=%d,"
	"*pi=%d\n",i1,i2,i3,*pi);//10
  printf("father:&i1=%p,&i2=%p,&i3=%p,"
	"pi=%p\n",&i1,&i2,&i3,pi);
}

