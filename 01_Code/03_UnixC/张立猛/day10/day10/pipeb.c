#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("a.pipe",//管道不要用读写
	O_RDONLY);//权限
  if(fd == -1) perror("open"),exit(-1);
  for(;;){
	int x;
    int res = read(fd,&x,sizeof(x));
    if(res<=0) break;
	printf("x=%d\n",x);
  }
  close(fd);
}

