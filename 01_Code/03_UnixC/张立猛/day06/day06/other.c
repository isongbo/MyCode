#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  mode_t old = umask(0022);//屏蔽两个
  int fd = open("c.txt",O_RDWR|O_CREAT,
	0666);
  close(fd);
  umask(old);//恢复了之前的权限屏蔽
  fd = open("d.txt",O_RDWR|O_CREAT,
	0666);
  close(fd);
  truncate("c.txt",100);
  //remove("d.txt");  
}


