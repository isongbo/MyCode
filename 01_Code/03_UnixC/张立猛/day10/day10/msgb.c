#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(){
  key_t key = ftok(".",100);//可以用相同
  int msgid = msgget(key,0);
  if(msgid==-1)perror("msgget"),exit(-1);
  char buf[100] = {};
  int res = msgrcv(msgid,buf,sizeof(buf),
	0,IPC_NOWAIT);//非阻塞方式
  if(res==-1)perror("msgrcv"),exit(-1);
  printf("读到%d字节,内容:%s\n",res,buf);
}


