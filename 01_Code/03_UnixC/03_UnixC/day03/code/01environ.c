//打印环境表中的内容
#include <stdio.h>
#include <string.h>

int main(void)
{
	//声明存储环境表首地址的全局变量
	extern char** environ;
	char** p = environ;
	while(*p != NULL)
	{
		printf("%s\n",*p);
		//指向下一个元素
		p++;
	}
	
	//练习：定义一个数组，将环境表中环境变量名为SHELL=右边的值放到数组中，并且打印出来
	printf("------------------------\n");
	p = environ;
	char value[100] = {0};
	while(*p != NULL)
	{
		//比较前5个字符是否为SHELL
		if(!strncmp(*p,"SHELL",5))
		{
			//跳过前6个字符
			strcpy(value,*p+6);
			break;
		}
		//指向下一个环境变量
		p++;
	}
	printf("value = %s\n",value);
	return 0;
}




