#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  printf("begin\n");//有\n子进程不打印
  fork();//没有\n子进程会复制输出缓冲区
  printf("end\n");
}

