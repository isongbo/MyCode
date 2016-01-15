#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fdr = open("a.txt",O_RDONLY);
  if(fdr==-1) perror("open a"),exit(-1);
  int fdw = open("b.txt",//新建文件时，有
  O_RDWR|O_CREAT|O_TRUNC,0666);//权限屏蔽
  if(fdw==-1) perror("open b"),exit(-1);
  char buf[1024] = { };
  while(1){
    int res = read(fdr,buf,sizeof(buf));
	if(res==-1){ perror("read"); break; }
	if(!res) break;
	write(fdw,buf,res);
  }
  close(fdw); close(fdr);
}


