//进程中的内存区域划分
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
		int* pi = malloc(4);
		// pi指向堆区  pi本身在栈区
		printf("pi = %p,&pi = %p\n",pi,&pi);
		
		printf("------------------------\n");
		char* ps = "hello";
		//将字符串常量 拷贝到 str指向的栈区空间
		char str[10] = "hello";
		// ps指向只读常量区 ，ps本身在栈区
		printf("ps = %p,&ps = %p\n",ps,&ps);
		printf("str = %p\n",str);
		//"hello"字符串可以看作一个无名的字符数组
		// 仅供娱乐！
		printf("字符串的首地址是：%p\n",&"hello"[0]);
		printf("字符串的首地址是：%p\n","hello");
		
		printf("---------------------------\n");
		char* pc = str;
		ps = "1234";
		// 数组名是个常量，不可改变
		//str = "1234";
		pc = "1234";
		// 上述代码改变指针的指向，也就是指针中保存的内容
		printf("ps = %p,str = %p,pc = %p\n",ps,str,pc);

		printf("--------------------------\n");
		printf("ps = %s,pc = %s,str = %s\n",ps,pc,str);
		//试图修改只读常量区的内容，可能引发段错误
		//ps[0] = 'A';
		//pc[0] = 'A';
		str[0] = 'A';
		printf("ps = %s,pc = %s,str = %s\n",ps,pc,str);

		printf("----------------------------\n");
		// ps指向堆区  ps本身在栈区
		ps = malloc(10);
		//改内容
		//ps[0] = 'A';
		//改内容
		strcpy(ps,"abcde");
		printf("ps = %s,ps = %p,&ps = %p\n",ps,ps,&ps);
		//改指向
		ps = "hello";
		printf("ps = %s,ps = %p,&ps = %p\n",ps,ps,&ps);
		return 0;
}
