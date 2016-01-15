#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
  key_t key = ftok(".",100);//可以用相同
  int msgid = msgget(key,IPC_CREAT|0666);
  if(msgid==-1)perror("msgget"),exit(-1);
  int res = msgsnd(msgid,"hello",5,0);
  if(res == -1)perror("msgsnd"),exit(-1);
  printf("send ok\n");
}//练习：写msgb.c 从消息队列中取出hello


