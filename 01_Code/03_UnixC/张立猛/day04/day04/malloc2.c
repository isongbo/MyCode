#include <stdio.h>
#include <stdlib.h>

int main(){
  int* pi = malloc(4);//分4字节,映射33页
  *(pi+100) = 100;//在33个内存页内的
  printf("%d\n",*(pi+100));
  *(pi+1) = 100;//能用但可能被覆盖
  int* p2 = malloc(4);*p2 = 100;//不覆盖
  free(p2); free(pi);
  printf("pi=%p\n",pi);
  printf("all free\n");
  printf("pid=%d\n",getpid());
  while(1); 
}

