//使用消息队列进行进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//定义消息的数据类型
typedef struct
{
	long mtype;//消息类型 >0
	char buf[20];//消息内容
}Msg;

int main(void)
{
	//1.获取key值,使用ftok函数
	key_t key = ftok(".",200);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.创建消息队列，获取ID,使用msgget函数
	int msgid = msgget(key,IPC_CREAT|IPC_EXCL|0666);
	if(-1 == msgid)
	{
		perror("msgget"),exit(-1);
	}
	printf("msgid = %d\n",msgid);
	//3.向消息队列中发送消息
	Msg m1,m2;
	m1.mtype = 1;
	strcpy(m1.buf,"hello1");
	m2.mtype = 2;
	strcpy(m2.buf,"hello2");

	int res = msgsnd(msgid,&m1,sizeof(m1.buf),0);
	if(-1 == res)
	{
		perror("msgsnd"),exit(-1);
	}
	res = msgsnd(msgid,&m2,sizeof(m2.buf),0);
	if(-1 == res)
	{
		perror("msgsnd"),exit(-1);
	}
	printf("发送消息成功\n");
	return 0;
}
