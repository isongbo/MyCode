//使用不同的方式来存放字符串的比较
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	//ps1指向只读常量区,ps1本身在栈区
	char* ps1 = "abcd";
	//str指向栈区，本身在栈区
	char str[] = "abcd";
	//ps2指向栈区，本身在栈区
	char* ps2 = str;
	printf("ps1 = %p\n",ps1);
	printf("str = %p\n",str);
	printf("ps2 = %p\n",ps2);
	
	printf("&ps1 = %p\n",&ps1);
	printf("&str = %p\n",&str);
	printf("&ps2 = %p\n",&ps2);
	
	printf("--------------------\n");
	//改变各自的指向
	ps1 = "1234";
	//str = "1234"; str是数组名,不可改变
	ps2 = "1234";
	printf("ps1 = %p,ps2 = %p\n",ps1,ps2);
	
	printf("----------------------\n");
	//改变指向位置上对应的数据内容
	//strcpy(ps1,"cdef");//error 只读常量区
	strcpy(str,"cdef");
	//strcpy(ps2,"cdef");//error
	
	printf("---------------------\n");
	char* pc = (char*)malloc(10*sizeof(char));
	char* pc2 = pc;
	//改变指针指向的内容
	strcpy(pc,"cdef");
	//改变指针的指向
	pc = "4567";
	free(pc2);
	pc2 = NULL;
	return 0;
}




