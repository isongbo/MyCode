#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
  int* p1 = sbrk(4);
  double* p2 = sbrk(8);
  char* p3 = sbrk(10);
  *p1 = 10;
  *p2 = 12.3;
  strcpy(p3,"abcd");
  printf("%d,%lf,%s\n",*p1,*p2,p3);
  printf("p1=%p\n",p1);
  //brk(p3); brk(p2);
  brk(p1);
  printf("pid=%d\n",getpid());
  while(1);
}


