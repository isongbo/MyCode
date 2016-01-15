#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  void* p = sbrk(4);//分配4字节,映射1页
  printf("p=%p\n",p);
  int* p2 = sbrk(4);//连续分配
  printf("p2=%p\n",p2); *p2 = 100;
  void* p3 = sbrk(4);
  void* p4 = sbrk(4);
  sbrk(-8); sbrk(-4);//只移位置,不删数据
  void* p5 = sbrk(0);
  printf("p5=%p\n",p5);//04
  printf("*p2=%d\n",*p2);
  printf("pid=%d\n",getpid());
  while(1);
}

