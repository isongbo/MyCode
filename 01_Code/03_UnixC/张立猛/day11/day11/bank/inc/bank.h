#ifndef _BANK_H
#define _BANK_H
#include <sys/types.h>
#define KEY_REQUEST 0x12345678 //请求队列
#define KEY_RESPOND 0x87654321 //响应队列
#define TYPE_OPEN     8001 // 开户
#define TYPE_CLOSE    8002 // 清户
#define TYPE_SAVE     8003 // 存款
#define TYPE_WITHDRAW 8004 // 取款
#define TYPE_QUERY    8005 // 查询
#define TYPE_TRANSFER 8006 // 转帐
// 账户
typedef struct tag_Account {
	int    id;        // 帐号
	char   name[256]; // 户名
	char   passwd[9]; // 密码
	double balance;   // 余额
}	ACCOUNT;
// 开户请求
typedef struct tag_OpenRequst {
	long   type;      // 业务类型
	pid_t  pid;       // 进程标识
	char   name[256]; // 户名
	char   passwd[9]; // 密码
	double balance;   // 初始余额
}	OPEN_REQUEST;
// 开户响应
typedef struct tag_OpenRespond {
	long type;       // 消息类型
	char error[512]; // 错误信息
	int  id;         // 帐号
}	OPEN_RESPOND;
// 清户请求
typedef struct tag_CloseRequest {
	long  type;      // 业务类型
	pid_t pid;       // 进程标识
	int   id;        // 帐号
	char  name[256]; // 户名
	char  passwd[9]; // 密码
}	CLOSE_REQUEST;
// 清户响应
typedef struct tag_CloseRespond {
	long   type;       // 消息类型
	char   error[512]; // 错误信息
	double balance;    // 余额
}	CLOSE_RESPOND;
// 存款请求
typedef struct tag_SaveRequest {
	long   type;      // 业务类型
	pid_t  pid;       // 进程标识
	int    id;        // 帐号
	char   name[256]; // 户名
	double money;     // 存款金额
}	SAVE_REQUEST;
// 存款响应
typedef struct tag_SaveRespond {
	long   type;       // 消息类型
	char   error[512]; // 错误信息
	double balance;    // 余额
}	SAVE_RESPOND;
// 取款请求
typedef struct tag_WithdrawRequest {
	long   type;      // 业务类型
	pid_t  pid;       // 进程标识
	int    id;        // 帐号
	char   name[256]; // 户名
	char   passwd[9]; // 密码
	double money;     // 取款金额
}	WITHDRAW_REQUEST;
// 取款响应
typedef struct tag_WithdrawRespond {
	long   type;       // 消息类型
	char   error[512]; // 错误信息
	double balance;    // 余额
}	WITHDRAW_RESPOND;
// 查询请求
typedef struct tag_QueryRequest {
	long   type;      // 业务类型
	pid_t  pid;       // 进程标识
	int    id;        // 帐号
	char   name[256]; // 户名
	char   passwd[9]; // 密码
}	QUERY_REQUEST;
// 查询响应
typedef struct tag_QueryRespond {
	long   type;       // 消息类型
	char   error[512]; // 错误信息
	double balance;    // 余额
}	QUERY_RESPOND;
// 转帐请求
typedef struct tag_TransferRequest {
	long   type;         // 业务类型
	pid_t  pid;          // 进程标识
	int    id[2];        // 帐号
	char   name[2][256]; // 户名
	char   passwd[9];    // 密码
	double money;        // 转帐金额
}	TRANSFER_REQUEST;
// 转帐响应
typedef struct tag_TransferRespond {
	long   type;       // 消息类型
	char   error[512]; // 错误信息
	double balance;    // 余额
}	TRANSFER_RESPOND;
#endif // _BANK_H
