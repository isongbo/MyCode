#include <stdio.h>
#include <stdlib.h>

int i1 = 10;//全局
int i2;//bss段
const int i3 = 10;//只读常量区
static int i4 = 10;//全局
void fa(int i5){//i5栈, fa在代码区
  int i6 = 10;//栈
  const int i7 = 10;//栈
  static int i8 = 10;//全局
  int* pi = malloc(4);//堆
  char* s1 = "abc";//指向只读常量区
  char s2[] = "abc";//指向栈
  printf("i5=%p\n",&i5);
  printf("i6=%p\n",&i6);
  printf("i7=%p\n",&i7);
  printf("i8=%p\n",&i8);
  printf("pi=%p\n",pi);
  printf("s1=%p\n",s1);
  printf("s2=%p\n",s2);
}
int main(){
  printf("i1=%p\n",&i1);
  printf("i2=%p\n",&i2);
  printf("i3=%p\n",&i3);
  printf("i4=%p\n",&i4);
  fa(1);
  printf("fa=%p\n",fa);
  printf("pid=%d\n",getpid());
  while(1);
}//cat /proc/pid/maps

