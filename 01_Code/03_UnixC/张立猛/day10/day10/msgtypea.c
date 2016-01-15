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
  int msgid = msgget(key,IPC_CREAT|0666);
  if(msgid==-1)perror("msgget"),exit(-1);
  struct emp em1={1,"zhangfei",12000.0};
  struct emp em2={2,"guanyu",20000.0};
  struct msg m1 = {1,em1};
  struct msg m2 = {2,em2};
  msgsnd(msgid,&m1,sizeof(m1.em),0);
  msgsnd(msgid,&m2,sizeof(m2.em),0);
  printf("send ok\n");
  while(1);//这个进程不退出(msgctl())
}//练习：用信号退出进程，同时删除消息队列


