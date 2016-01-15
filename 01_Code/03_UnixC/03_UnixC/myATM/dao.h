//数据对象的存储
#ifndef DAO_H
#define DAO_H
#include "bank.h"

//生成一个不重复的帐号
int generator_id();
//将一个新的帐号保存到文件
int createUser(struct Account acc);
//销户的功能
int destroyUser(struct Account acc);
//实现存钱的功能
int saveMoney(struct Account acc,struct Account *p);
//实现取钱的功能
int getMoney(struct Account acc,struct Account *p);
//实现查询余额的功能
int checkMoney(struct Account acc,struct Account *p);
//转帐的函数
int moveMoney(struct Account acc1,struct Account acc2,struct Account *p);

#endif
