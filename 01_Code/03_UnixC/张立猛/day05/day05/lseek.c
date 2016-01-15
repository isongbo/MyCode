#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("a.txt",O_RDWR);
  if(fd==-1) perror("open"),exit(-1);
  char ch;
  read(fd,&ch,1);printf("%c\n",ch);//a
  read(fd,&ch,1);printf("%c\n",ch);//b
  lseek(fd,3,SEEK_SET);
  read(fd,&ch,1);printf("%c\n",ch);//d 
  lseek(fd,0,SEEK_SET);//回到开头
  write(fd,"1",1); //a->1
  lseek(fd,2,SEEK_CUR);write(fd,"2",1);
  lseek(fd,-2,SEEK_CUR);write(fd,"3",1); 
  lseek(fd,-2,SEEK_END);write(fd,"4",1);
  close(fd);
}


