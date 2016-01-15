#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct emp{
  int id;
  char name[20];
  double sal; };
struct msg{
  long mtype;
  struct emp em; };
int main(){
  key_t key = ftok(".",100);
  int msgid = msgget(key,0);
  if(msgid==-1)perror("msgget"),exit(-1);
  struct msg m1;
  msgrcv(msgid,&m1,sizeof(m1.em),-2,0);
  printf("%d,%s,%lf\n",m1.em.id,
	m1.em.name,m1.em.sal);
}


