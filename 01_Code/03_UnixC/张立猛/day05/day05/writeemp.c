#include "emp.h"

int main(){
  struct emp em;
  printf("请输入员工编号 姓名和工资\n");
  scanf("%d%s%lf",&em.id,em.name,
    &em.sal);
  int fd = open("em.dat",
	O_RDWR|O_CREAT|O_APPEND,0666);
  if(fd==-1) perror("open"),exit(-1);
  int res = write(fd,&em,sizeof(em));
  if(res==-1) perror("write"),exit(-1);
  printf("append ok\n");
  close(fd);
}

