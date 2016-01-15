//使用malloc申请内存的一般大小
#include <stdio.h>
#include <unistd.h> //getpid()函数
#include <stdlib.h>

int main(void)
{
	//获取当前进程的进程号
	printf("进程号:pid = %d\n",getpid());
	int* p1 = (int*)malloc(4);
	printf("申请了4个字节的内存空间\n");
	//从控制台读取一个字符,scanf("%c",c);
	getchar();

	int* p2 = (int*)malloc(4);
	printf("再次分配4个字节的内存,p1 = %p,p2 = %p\n",p1,p2);
	getchar();
	//进行越界访问,不要进行越界访问
	//*(p1+10000) = 100;
	//*(p1+33*1025) = 100;
	//printf("越界访问的值是：%d\n",*(p1+33*1025));
	return 0;
}
