#include <stdio.h>
#include <stdlib.h>

void fa(){
  printf("call fa\n");
}
int main(){
  atexit(fa);//注册了fa,在进程退出时调用
  printf("begin\n");
  //exit(0);//会调用fa
  //_Exit(0);//不会调用fa,立即结束
  printf("end\n");
  return 0;//会调用fa
}


