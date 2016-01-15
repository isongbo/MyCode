#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main(){
  void* p = mmap(0,4,
	PROT_READ|PROT_WRITE,
	MAP_PRIVATE|MAP_ANONYMOUS,
	0,0);
  if(p==MAP_FAILED)
    perror("mmap"),exit(-1);
  int* pi = p;
  *pi = 100;
  printf("*pi=%d\n",*pi);
  munmap(p,4);
}

