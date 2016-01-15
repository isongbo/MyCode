#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  printf("pid=%d\n",getpid()); 
  void* p1 = sbrk(4);
  if(p1==(void*)-1) 
    perror("sbrk"),exit(-1);//1条语句
  sbrk(4093);
  printf("p1=%p\n",p1);
  printf("分配完毕\n");//超过一页
  sleep(15);
  sbrk(-1); printf("free 1\n");//回到1页
  sleep(15);
  sbrk(-4096);printf("free all\n");
  while(1);
}

