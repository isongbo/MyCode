//客户端
#include <stdio.h>
#include "bank.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

//获取消息队列
static int msgid1;
static int msgid2;
void getId()
{
	msgid1 = msgget(key1,0);
	if(msgid1 == -1)
	{
		perror("获取消息队列一失败");
		exit(-1);
	}
	msgid2 = msgget(key2,0);
	if(msgid2 == -1)
	{
		perror("获取消息队列二失败");
		exit(-1);
	}
}

//开户的函数
void createUser()
{
	struct Account acc;
	printf("请输入用户名：\n");
	scanf("%s",acc.name);
	printf("请输入密码:\n");
	scanf("%s",acc.password);
	printf("请输入金额：\n");
	scanf("%lf",&acc.balance);
	struct Msg msg = {M_OPEN,acc};
	//获取消息队列
	getId();
	//将消息发送到消息队列一中
	msgsnd(msgid1,&msg,sizeof(msg.acc),0);
	//接受消息队列二中的消息
	msgrcv(msgid2,&msg,sizeof(msg.acc),0,0);
	if(msg.mtype == M_SUCESS)
	{
		printf("开户成功\n");
	}
	else
	{
		printf("开户失败\n");
	}
}
//销户的函数
void destroyUser()
{
	struct Account acc;
	printf("请输入用户的帐号：\n");
	scanf("%d",&acc.id);
	struct Msg msg = {M_DESTROY,acc};
	//获得消息队列
	getId();
	//通过消息队列一向服务器发送消息
   msgsnd(msgid1,&msg,sizeof(msg.acc),0);
	//通过消息队列二接受来自服务器的消息
	msgrcv(msgid2,&msg,sizeof(msg.acc),0,0);
	if(msg.mtype == M_SUCESS)
	{
		printf("销户成功\n");
	}
	else
	{
		printf("销户失败，此帐户不存在\n");
	}
}

//存钱的函数
void saveMoney()
{
	struct Account acc,accTemp;
	printf("请输入帐号：\n");
	scanf("%d",&acc.id);
	printf("请输入存入的金额:\n");
	scanf("%lf",&acc.balance);
	struct Msg msg = {M_SAVE,acc};
	//获取消息队列的id
	getId();
	//发送消息
	msgsnd(msgid1,&msg,sizeof(msg.acc),0);
	//接受消息
	msgrcv(msgid2,&msg,sizeof(msg.acc),0,0);
	if(msg.mtype == M_SUCESS)
	{
		printf("存入成功\n");
		printf("当前余额是：%lf\n",msg.acc.balance);
	}
	else
	{
		printf("存入失败\n");
	}
}
//取钱的实现
void getMoney()
{
	struct Account acc;
	printf("请输入帐号：\n");
	scanf("%d",&acc.id);
	printf("请输入取款金额：\n");
   scanf("%lf",&acc.balance);
	struct Msg msg = {M_TAKE,acc};
	//获取消息队列
	getId();
   //通过消息队列一向服务器发送消息
	msgsnd(msgid1,&msg,sizeof(msg.acc),0);
	//通过消息队列二接受服务器的消息
	//接受存钱后的结果
	msgrcv(msgid2,&msg,sizeof(msg.acc),0,0);
   if(msg.mtype == M_SUCESS)
	{
		printf("取钱成功\n");
		printf("当前余额是:%lf\n",msg.acc.balance);
	}
	else
	{
		printf("余额不足，请先核对帐户余额\n");
	}
}

//查询的实现
void checkMoney()
{
	struct Account acc;
	printf("请输入帐号：\n");
	scanf("%d",&acc.id);
   struct Msg msg = {M_QUERY,acc};
	//获取消息队列
	getId();
	//将消息发送到消息队列一中
	msgsnd(msgid1,&msg,sizeof(msg.acc),0);
	//接受处理的结果
	msgrcv(msgid2,&msg,sizeof(msg.acc),0,0);
	if(msg.mtype == M_SUCESS)
	{
		printf("查询成功\n");
		printf("当前帐户的余额是：%lf\n",msg.acc.balance);
	}
	else
	{
		printf("查询失败,此帐户不存在\n");
	}
}
//转帐的实现
void moveMoney()
{
	//转出帐户的处理
	struct Account acc;
	printf("请输入转出帐号：\n");
	scanf("%d",&acc.id);
	printf("请输入转出金额：\n");
	scanf("%lf",&acc.balance);
	struct Msg msg = {M_TRANSF,acc};
   //获取消息队列
	getId();
	//发送包含转出帐号的消息
	msgsnd(msgid1,&msg,sizeof(msg.acc),0);
	//转入帐户的处理
	printf("请输入转入帐号：\n");
	scanf("%d",&acc.id);
	msg.acc = acc;
   //发送转入帐户的信息
	msgsnd(msgid1,&msg,sizeof(msg.acc),0);
	//接受处理结果
	msgrcv(msgid2,&msg,sizeof(msg.acc),0,0);
	if(msg.mtype == M_SUCESS)
	{
		printf("转帐成功，你的帐户余额为：%lf\n",msg.acc.balance);
	}
	else
	{
		printf("转帐失败，请先核对你的帐户余额\n");
	}
}
//客户端的界面
void mainPage()
{
	while(1)
	{
		//system("clear");
	   printf("     欢迎使用迷你ATM机\n");
	   printf("--------------------------\n");
	   printf("[1] 开户");
	   printf("        [2] 销户\n");
	   printf("[3] 存钱");
	   printf("        [4] 取钱\n");
	   printf("[5] 查询");
	   printf("        [6] 转帐\n");
	   printf("[0] 退出\n");
	   printf("-------------------------\n");
	   printf("请选择:\n");
	   int num = 0;
	   scanf("%d",&num);
	   switch(num)
	   {
			case 1:createUser();
		  		   break;
		   case 2:destroyUser();
				    break;
	      case 3:saveMoney();
				    break;
		   case 4:getMoney();
				    break;
	      case 5:checkMoney();
				    break;
		   case 6:moveMoney();
				    break;
		   case 0:printf("谢谢使用，再见\n");
				    return;
		   default:printf("输入错误\n");
 	   }
	}
}

int main()
{
	mainPage();
	return 0;
}
