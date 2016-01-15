#include <stdio.h>
#define VERSION 3
#if(VERSION<3)
  #error "版本低"
#elif(VERSION>3)
  #warning "版本高"
#endif
#pragma GCC dependency "hello.c"
#pragma GCC poison goto
#pragma pack(1)
int main(){
  //goto ok;
  printf("hello c\n");
ok:printf("test\n");
  struct s{
    char c1;
	int i;
	char c2; };//不符合编程规范的缩进
  printf("size=%d\n",sizeof(struct s));
}

