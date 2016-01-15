#include "emp.h"

int main(){
  int fd = open("em.dat",O_RDONLY);
  if(fd==-1) perror("open"),exit(-1);
  struct emp em;
  while(1){
    int res = read(fd,&em,sizeof(em));
	if(res==-1) perror("read"),exit(-1);
	if(!res) break;
	printf("%d,%s,%lf\n",em.id,em.name,
	  em.sal);
  }
  close(fd);
}

