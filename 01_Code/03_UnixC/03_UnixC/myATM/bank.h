//客户端和服务器端共用的帐户头文件
#ifndef BANK_H
#define BANK_H

//定义两个key值，处理消息队列
extern const int key1;//客户端向服务器发送的消息队列键值
extern const int key2;//服务器向客户端发送的消息队列键值

//消息类型
#define M_OPEN 1 //开户
#define M_DESTROY 2 //销户
#define M_SAVE 3 //存钱
#define M_TAKE 4 //取钱
#define M_QUERY 5 //查询
#define M_TRANSF 6 //转帐
#define M_SUCESS 7 //处理成功
#define M_FAILED 8 //处理失败

//帐户的结构体
struct Account
{
	int id;//帐号
	char name[10]; //用户名
	char password[10]; //密码
	double balance; //金额
};

//消息的结构体
struct Msg
{
	int mtype;//消息的类型
	struct Account acc;
};

#endif
