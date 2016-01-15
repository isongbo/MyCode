#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd = open("a.txt",O_RDWR);
  if(fd==-1) perror("open"),exit(-1);
  struct flock lock;
  lock.l_type = F_WRLCK;//F_RDLCK;//读锁
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 20;
  lock.l_pid = -1;//其实不用
  int res=fcntl(fd,F_SETLK,&lock);//读锁
  if(res == -1) printf("上锁失败\n");
  else printf("上锁成功\n");
  close(fd);
}


