#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
  void* p = sbrk(0);//取当前位置
  brk(p+4);//分配4字节
  brk(p+8);//分配4字节
  brk(p+4);//回收4字节
  int* p1 = p; *p1 = 100;
  double* p2 = sbrk(0);//取当前位置
  brk(p2+1); *p2 = 12.3;
  char* p3 = sbrk(0);
  brk(p3+10); strcpy(p3,"abcd");
  //p3 = "abcd";//字符串不能改指向
  printf("%d,%lf,%s\n",*p1,*p2,p3);
  brk(p3); brk(p2); brk(p1);
}


