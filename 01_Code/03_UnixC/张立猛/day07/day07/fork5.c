#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
  //pid_t pid = fork();//新建
  int fd = open("a.txt",
    O_CREAT|O_RDWR|O_TRUNC,0666);
  if(fd == -1) perror("open"),exit(-1);
  pid_t pid = fork();//复制
  if(pid == 0){//子进程执行的分支
	printf("c:fd=%d\n",fd);
    write(fd,"abcd",4);
	close(fd);//关闭子进程的fd
	exit(0); }
  printf("f:fd=%d\n",fd);
  write(fd,"1234",4);
  close(fd);//关闭父进程的fd
}


