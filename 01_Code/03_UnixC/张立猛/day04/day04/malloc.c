#include <stdio.h>
#include <stdlib.h>

int main(){
  int a,b,c;//栈区
  printf("a=%p,b=%p,c=%p\n",&a,&b,&c);
  int* p1 = malloc(4);//分配地址并映射
  int* p2 = malloc(4);//分配地址 不映射
  int* p3 = malloc(4);
  printf("p1=%p,p2=%p,p3=%p\n",p1,p2,p3);
  printf("pid=%d\n",getpid());
  *p1 = 100;
  *(p1-1) = 0;//破坏了p1的附加数据
  printf("*p1=%d\n",*p1);
  free(p1); while(1);
}

