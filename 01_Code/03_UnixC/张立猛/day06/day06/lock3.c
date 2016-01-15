#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int fd = open("a.txt",O_RDWR);
  if(fd==-1) perror("open"),exit(-1);
  struct flock lock;
  lock.l_type = F_RDLCK;//读锁
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 20;
  lock.l_pid = -1;//其实不用
  int res=fcntl(fd,F_SETLK,&lock);//读锁
  if(res==-1) perror("fcntl"),exit(-1);
  printf("lock success\n");
  sleep(15);//15秒之内保持锁定
  printf("数据已经读完，解除锁定\n");
  lock.l_type = F_UNLCK;//类型改为解锁
  fcntl(fd,F_SETLK,&lock);//释放锁
  sleep(10);
  printf("main over\n");
  close(fd);//lock2.c去掉sleep()
}


