#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd=open("a.txt",O_RDWR|O_CREAT,
	0666);
  if(fd == -1) perror("open"),exit(-1);
  write(fd,"hello",5);
  close(fd);//写文件的代码
  int fd1 = open("a.txt",O_RDONLY);//读
  if(fd1 == -1) perror("open"),exit(-1);
  char buf[100] = {};
  int res = read(fd1,buf,sizeof(buf));
  if(res == -1) perror("read"),exit(-1);
  printf("读了%d字节,内容%s\n",res,buf);
  close(fd1);
}

