//环境变量相关的函数介绍
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	//获取环境变量SHELL所对应的值
	char* ps = getenv("SHELL");
	if(NULL == ps)
	{
		perror("getenv"),exit(-1);
	}
	printf("SHELL = %s\n",ps);

	printf("-------------------------\n");
	//表示不修改环境变量值
	int res = setenv("SHELL","1234",0);
	if(-1 == res)
	{
		perror("setenv"),exit(-1);
	}
	printf("修改之后的结果是：SHELL = %s\n",getenv("SHELL"));
	//修改环境变量的值
	res = setenv("SHELL","1234",1);
	if(-1 == res)
	{
		perror("setenv"),exit(-1);
	}
	printf("修改之后的结果是：SHELL = %s\n",getenv("SHELL"));
	//增加环境变量
	res = setenv("xiaomage","marz",1);
	if(-1 == res)
	{
		perror("setenv"),exit(-1);
	}
	printf("增加的环境变量是：xiaomage = %s\n",getenv("xiaomage"));

	printf("----------------------\n");
	//删除一个不存在的环境变量
	res = unsetenv("zhangfei");
	if(-1 == res)
	{
		perror("unsetenv"),exit(-1);
	}
	//删除一个已经存在的环境变量
	res = unsetenv("xiaomage");
	if(-1 == res)
	{
		perror("unsetenv"),exit(-1);
	}
	//获取失败,可能引发段错误
	printf("xiaomage = %s\n",getenv("xiaomage"));
	
	printf("---------------------\n");
	//修改环境变量SHELL的值
	putenv("SHELL=5678");
	printf("修改之后：SHELL = %s\n",getenv("SHELL"));

	//清空当前程序的环境表
	clearenv();
	printf("PATH = %s\n",getenv("PATH"));
	extern char** environ;
	printf("environ = %p\n",environ);
	return 0;
}



