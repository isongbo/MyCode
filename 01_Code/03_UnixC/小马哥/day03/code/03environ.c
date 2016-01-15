//环境表的使用
#include <stdio.h>
#include <string.h>

int main(void)
{
		/*char c;
		int i;
		char* pc = &c;
		int* pi = &i;
		char** ppc = &pc;
		printf("pc = %p,pi = %p,ppc = %p\n",pc,pi,ppc);
		// 1   4   4
		printf("pc+1 = %p,pi+1 = %p,ppc+1 = %p\n",pc+1,pi+1,ppc+1);*/
		
		//声明全局变量environ
		extern char** environ;
		//定义一个替身
		char** p = environ;
		// p指向环境表中第一个元素的地址
		// *p 获取环境表中第一个元素的内容
		// **p 获取环境表中第一个元素的第一个字符
		printf("**p = %c\n",**p);

		printf("----------------------\n");
		//循环遍历环境表中的所有内容
		while(*p /*!= NULL*/)
		{
				printf("%s\n",*p);
				//指向下一个元素
				p++;
		}

		printf("-------------------------\n");
		//练习：查找环境变量SHELL的值，然后放入一个字符数组中并且打印
		char value[20] = {0};
		//p指针回到环境表的首地址
		p = environ;
		while(*p)
		{
				if(0 == strncmp(*p,"SHELL=",6))
				{
						strcpy(value,*p+6);
						break;
				}
				p++;//指向下一个元素
		}
		printf("value = %s\n",value);
		return 0;
}




