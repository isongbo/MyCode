//使用消息队列进行进程间的通信
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

typedef struct 
{
	long mtype;
	char buf[20];
}Msg;

int msgid;

void fa(int signo)
{
	int res = msgctl(msgid,IPC_RMID,NULL);
	if(-1 == res)
	{
		perror("msgid"),exit(-1);
	}
	printf("删除消息队列成功\n");
	exit(0);//终止进程
}

int main(void)
{
	signal(2,fa);
	//1.获取key值
	key_t key = ftok(".",200);
	if(-1 == key)
	{
		perror("ftok"),exit(-1);
	}
	printf("key = %#x\n",key);
	//2.获取消息队列的ID
	msgid = msgget(key,0);
	if(-1 == msgid)
	{
		perror("msgget"),exit(-1);
	}
	printf("msgid = %d\n",msgid);
	//3.读取消息队列中的数据
	Msg m = {};
	//表示每次都读取消息队列中的第一个消息
	//int res = msgrcv(msgid,&m,sizeof(m.buf),0,0);
	//读取队列中第一个类型为2的消息
	//int res = msgrcv(msgid,&m,sizeof(m.buf),2,0);
	// 读取队列中 <=2的消息，优先读取类型1消息
	int res = msgrcv(msgid,&m,sizeof(m.buf),-2,0);
	if(-1 == res)
	{
		perror("msgrcv"),exit(-1);
	}
	printf("读取到的消息类型是：%ld,消息内容是：%s\n",m.mtype,m.buf);
	
	Msg m2;
	msgrcv(msgid,&m2,sizeof(m2.buf),-2,0);
	printf("读取到的消息类型是：%ld,消息内容是：%s\n",m2.mtype,m2.buf);

	//4.删除消息队列
	printf("删除消息队列，请按ctrl+c...\n");
	while(1);
	return 0;
}
