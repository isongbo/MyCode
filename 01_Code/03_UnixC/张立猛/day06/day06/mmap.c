#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(){
  int fd = open("em.dat",
	O_RDWR|O_CREAT|O_TRUNC,0666);
  if(fd == -1) perror("open"),exit(-1);
  ftruncate(fd,10);//给文件足够的大小
  void* p=mmap(0,10,PROT_READ|PROT_WRITE,
	//MAP_SHARED,//其他进程可以察看文件
	MAP_PRIVATE,//其他进程从文件中看不到
 	fd,0);// 权限小于等于fd的权限
  char* s = p; strcpy(s,"zhangfei");
  printf("%s\n",(char*)p);
  munmap(p,10); close(fd);
}


