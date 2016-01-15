#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("a.txt",
	O_RDWR|O_CREAT|O_TRUNC,0666);
  if(fd==-1) perror("open"),exit(-1);
  int fd2 = dup(fd);
  printf("fd=%d,fd2=%d\n",fd,fd2);//3 4
  int fd3 = dup2(fd,100);
  printf("fd3=%d\n",fd3);//100
  write(fd,"abc",3);//复制了描述符
  write(fd2,"123",3);//没复制文件表(公用)
  int fd4 = open("b.txt",O_RDWR|O_CREAT,
	0666);
  if(fd4==-1) perror("openb"),exit(-1);
  int fd5 = dup2(fd,fd4);
  printf("fd4=%d,fd5=%d\n",fd4,fd5);
  write(fd4,"456",3);//传入的是5
  close(fd);
}


