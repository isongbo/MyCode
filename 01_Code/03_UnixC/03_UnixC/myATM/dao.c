#include "dao.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

//定义一个文件来存储帐号
const char* ID_FILE = "id.dat";

//生成一个不重复的帐号
int generator_id()
{
	static int x = 100000;
	//ID_FILE文件是否存在，出错返回-1
	if(access(ID_FILE,F_OK) == -1)
	{
		int fd = open(ID_FILE,O_WRONLY|O_CREAT|O_EXCL,0600);
		if(fd == -1)
		{
			 perror("文件打开失败");
			 return -1;
		}
		write(fd,&x,sizeof(x));
		close(fd);
		return x;
	}
	//RD_WR为读写模式
	int fd = open(ID_FILE,O_RDWR);
	if(fd == -1)
	{
		perror("文件打开失败");
		return -1;
	}
	//读出文件中的值存到x中
	read(fd,&x,sizeof(x));
    x++;
	//将读写位置置到文件头
	lseek(fd,0,SEEK_SET);
	//将x的值写入到文件中
	write(fd,&x,sizeof(x));
	close(fd);
	return x;
}

//将一个新的帐号保存到文件
int createUser(struct Account acc)
{
	char filename[20] = {0};
	sprintf(filename,"%d.dat",acc.id);
  int fd = open(filename,O_WRONLY|O_CREAT|O_EXCL,0600);
	if(fd == -1)
	{
		perror("创建帐户文件失败");
		return -1;
	}
	if(write(fd,&acc,sizeof(acc)) < 0)
	{
		return -1;
	}
	close(fd);
	printf("用户创建成功\n");
	return 0;
}
//查找帐号，并进行销户
int destoryUser(struct Account acc)
{
	char filename[20] = {0};
	sprintf(filename,"%d.dat",acc.id);
	int fd = open(filename,O_RDONLY,0600);
   if(fd == -1)
   {
		perror("failed:");
		printf("此帐户不存在\n");
		return -1;
   }
	//删除文件的函数
	remove(filename);
	return 0;
}
//查找帐户，并进行存钱
int saveMoney(struct Account acc,struct Account *p)
{
	char filename[20] = {0};
	sprintf(filename,"%d.dat",acc.id);
   int fd = open(filename,O_RDWR,0600);	
	if(fd == -1)
	{
		perror("文件打开失败");
		printf("此帐户不存在，请先创建帐户\n");
		return -1;
	}
	printf("文件打开成功\n");
	struct Account accTemp;
	read(fd,&accTemp,sizeof(accTemp));
	accTemp.balance += acc.balance;
	printf("存入之后的金额是：%lf\n",accTemp.balance);
	*p = accTemp;
	lseek(fd,-sizeof(accTemp),SEEK_CUR);
	write(fd,&accTemp,sizeof(accTemp));
	return 0;
}
//取钱的处理
int getMoney(struct Account acc,struct Account *p)
{
	char filename[20] = {0};
	sprintf(filename,"%d.dat",acc.id);
	//O_WRONLY为只写 O_RDONLY为只读
	int fd = open(filename,O_RDWR,0600);
	if(fd == -1)
	{
		perror("文件打开失败");
		return -1;
	}
	struct Account accTemp;
	read(fd,&accTemp,sizeof(accTemp));
	if(accTemp.balance < acc.balance)
	{
		return -1;
	}
   accTemp.balance -= acc.balance;
	printf("取款结束之后的余额是：%lf\n",accTemp.balance);
	lseek(fd,-sizeof(accTemp),SEEK_CUR);
	write(fd,&accTemp,sizeof(accTemp));
	*p = accTemp;
	return 0;
}
//查询余额
int checkMoney(struct Account acc,struct Account *p)
{
	char filename[20] = {0};
	sprintf(filename,"%d.dat",acc.id);
	int fd = open(filename,O_RDONLY,0600);
	if(fd == -1)
	{
		perror("文件打开失败");
		return -1;
	}
	struct Account accTemp;
	read(fd,&accTemp,sizeof(accTemp));
	*p = accTemp;
	return 0;
}
//转帐的函数实现
int moveMoney(struct Account acc1,struct Account acc2,struct Account *p)
{
   char filenameOut[20] = {0},filenameIn[20] = {0};
	//转出帐户的处理
	sprintf(filenameOut,"%d.dat",acc1.id);
	int fd = open(filenameOut,O_RDWR);
	if(fd == -1)
	{
		printf("转出帐户不存在\n");
		return -1;
	}
	printf("转出帐户打开成功\n");
	struct Account accTemp;
	read(fd,&accTemp,sizeof(accTemp));
	if(accTemp.balance < acc1.balance)
	{
		printf("转出帐户余额不足\n");
		return -1;
	}
	accTemp.balance -= acc1.balance;
	lseek(fd,0,SEEK_SET);
	write(fd,&accTemp,sizeof(accTemp));
	*p = accTemp;
   //转入帐户的处理
	sprintf(filenameIn,"%d.dat",acc2.id);
	int fd2 = open(filenameIn,O_RDWR);
	if(fd2 == -1)
	{
		perror("转入帐户不存在");
		return -1;
	}
	printf("转入帐户的文件打开成功\n");
	read(fd2,&accTemp,sizeof(accTemp));
	accTemp.balance += acc1.balance;
	lseek(fd2,0,SEEK_SET);
	write(fd2,&accTemp,sizeof(accTemp));
   return 1;
}
