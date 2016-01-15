//C语言的错误处理
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//获取随机数的函数
int randNum(void)
{
		//1.设置随机种子
		srand(time(0));
		//2.得到随机数
		int num = rand()%10+1;
		return 5==num?-1:num;
}

//判断两个参数的大小
int max(int i,int j,int* pi)
{
		if(i == j)
		{
				return -1;
		}
		*pi = i>j?i:j;
		return 0;
}

//根据传入的字符串进行比较
char* myStr(char* str)
{
		return strcmp(str,"error")?"ok":NULL;
}

//打印传入的字符串
void print(char* str)
{
		printf("str = %s\n",str);
}

int main(void)
{
		printf("获取到的随机数是：%d\n",randNum());
		int res = 0;
		if(!max(-1,-2,&res))
		{
				printf("最大值是：%d\n",res);
		}

		char* ps = myStr("hello");
		if(ps)
		{
				printf("ps = %s\n",ps);
		}
		print("不抛弃，不放弃");
		return 0;
}
