//brk函数的使用
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
		//使用sbrk函数获取当前位置
		char* p = sbrk(0);
		printf("p = %p\n",p);
		//申请4个字节
		int res = brk(p+4);
		//相当于brk调用失败
		if(-1 == res)
		{
			  perror("brk"),exit(-1);
		}
		char* p2 = sbrk(0);
		printf("p2 = %p\n",p2); //p+4
		
		printf("---------------------\n");
		//表示申请了4个字节
		brk(p+8);
		p2 = sbrk(0);
		printf("p2 = %p\n",p2);//p+8

		printf("--------------------\n");	
		//释放了4个字节
		brk(p+4);
		p2 = sbrk(0);
		printf("p2 = %p\n",p2);//p+4
		
		printf("-------------------\n");
		//brk(p);全部释放
		//申请10个字节,总共14个字节
		brk(p+14);
		//p = "hello world"; 改变指针的指向
		strcpy(p,"hello world");
		printf("p = %s\n",p);
		
		printf("-------------------\n");
		void* cur = sbrk(0);
		printf("cur = %p\n",cur);
		//申请20个字节
		brk(cur+20);
		//brk(p+20);//6个字节
		cur = sbrk(0);
		printf("cur = %p\n",cur);
		brk(p);


		return 0;
}
