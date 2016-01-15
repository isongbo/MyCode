//消息队列实现进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

//定义消息类型
typedef struct Msg
{
	long mtype;//消息类型
	char buf[20];//消息内容
}Msg;

int main(void)
{
	//1.获取key值
	key_t key = ftok(".",100);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.根据key值获取消息队列的id
	int msgid = msgget(key,IPC_CREAT|IPC_EXCL|0666);
	if(-1 == msgid)
	{
		perror("msgid"),exit(-1);
	}
	printf("msgid = %d\n",msgid);
	//3.发送消息到消息队列
	Msg msg1;
	msg1.mtype = 1;
	strcpy(msg1.buf,"hello1");
	Msg msg2;
	msg2.mtype = 2;
	strcpy(msg2.buf,"hello2");
	int res = msgsnd(msgid,&msg1,sizeof(msg1)-4,0);
	if(-1 == res)
	{
		perror("msgsnd"),exit(-1);
	}
	res = msgsnd(msgid,&msg2,sizeof(msg2)-4,0);
	if(-1 == res)
	{
		perror("msgsnd2"),exit(-1);
	}



	return 0;
}
