//开户的文件
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "bank.h"

int main()
{
	int msgid1 = msgget(key1,0);
	if(msgid1 == -1)
	{
		perror("获取消息队列一失败");
		printf("服务启动失败\n");
		exit(-1);
	}
	int msgid2 = msgget(key2,0);
	if(msgid2 == -1)
	{
		perror("获取消息队列二失败");
		printf("服务启动失败\n");
		exit(-1);
	}
   //开始接受消息
	while(1)
	{
		struct Msg msg;
		struct Account accMove,accResult;
		if(msgrcv(msgid1,&msg,sizeof(msg.acc),0,0) <= 0)
		{
			 continue;
		}
		if(msg.mtype == M_OPEN)
		{
		   int id = generator_id();
		   accMove = msg.acc;
		   accMove.id = id;
		   if(createUser(accMove) == -1)
		   {
			    printf("开户失败\n");
				  msg.mtype = M_FAILED;
		   }
		   else
		   {
			   printf("开户成功\n");
				 msg.mtype = M_SUCESS;
			}
			msgsnd(msgid2,&msg,sizeof(msg.acc),0);
		}
		else if(msg.mtype == M_DESTROY)
		{
          if(destoryUser(msg.acc) == -1)
			 {
				 printf("销户失败\n");
				 msg.mtype = M_FAILED;
			 }
			 else
		    {
				 printf("销户成功\n");
				 msg.mtype = M_SUCESS;
			 }
			 msgsnd(msgid2,&msg,sizeof(msg.acc),0);
		}
		else if(msg.mtype == M_SAVE)
		{
         if(saveMoney(msg.acc, &accResult) == -1)
			{
				printf("存钱失败\n");
				msg.mtype = M_FAILED;
			}
			else
			{
				printf("存钱成功\n");
				msg.mtype = M_SUCESS;
			}
			//发送是否存钱成功的标志
			msg.acc.balance = accResult.balance;
			msgsnd(msgid2,&msg,sizeof(msg.acc),0);
		}
		else if(msg.mtype == M_TAKE)
		{
			 if(getMoney(msg.acc,&accResult) == -1)
			 {
				  printf("取钱失败\n");
				  msg.mtype = M_FAILED;
			 }
			 else
			 {
				  printf("取钱成功\n");
				  msg.mtype = M_SUCESS;
			 }
			 //将服务器处理的结果发送给客户端
			 msg.acc.balance = accResult.balance;
			 msgsnd(msgid2,&msg,sizeof(msg.acc),0);
		}
		else if(msg.mtype == M_QUERY)
		{
			 if(checkMoney(msg.acc,&accResult) == -1)
			 {
				  printf("查询失败\n");
				  msg.mtype = M_FAILED;
			 }
			 else
			 {
				 printf("查询成功\n");
				 msg.mtype = M_SUCESS;
			 }
			 //发送查询出的余额
			 msg.acc.balance = accResult.balance;
			 msgsnd(msgid2,&msg,sizeof(msg.acc),0);
		}
		else if(msg.mtype == M_TRANSF)
		{
			 //定义一个消息结构体，来接受转入的帐号
			 struct Msg msgTemp;
			 msgrcv(msgid1,&msgTemp,sizeof(msgTemp.acc),0,0);
			 if(moveMoney(msg.acc,msgTemp.acc,&accResult) == -1)
			 {
				 printf("转入失败\n");
				 msg.mtype = M_FAILED;
			 }
			 else
			 {
				 printf("转入成功\n");
				 msg.mtype = M_SUCESS;
			 }
			 msg.acc.balance = accResult.balance;
			 printf("转帐之后的结果是：%lf\n",msg.acc.balance);
			 //发送处理结果到客户端
			 msgsnd(msgid2,&msg,sizeof(msg.acc),0);
		}
	}
   return 0;
}
