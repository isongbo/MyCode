//消息队列的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

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
	//2.根据key值获取消息队列的id
	int msgid = msgget(key,0);
	if(-1 == msgid)
	{
		perror("msgget"),exit(-1);
	}
	//3.接受消息队列中的消息
	Msg msg;
	int i = 0;
	for(i = 0; i < 2; i++)
	{
		//消息类型为0表示接受消息队列中第一个消息
		//int res = msgrcv(msgid,&msg,sizeof(msg)-4,0,0);
		//读取类型为2的消息
		//int res = msgrcv(msgid,&msg,sizeof(msg)-4,2,0);
		//读取类型 <= 2 的消息
		int res = msgrcv(msgid,&msg,sizeof(msg)-4,-2,0);
		if(-1 == res)
		{
			perror("msgrc"),exit(-1);
		}
		printf("第%d次接受到的消息是：%s\n",i+1,msg.buf);
	}
	//4.删除消息队列
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}
