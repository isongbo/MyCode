//使用malloc分配内存的情况
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		int* p1 = malloc(4);
		int* p2 = malloc(4);
		int* p3 = malloc(4);
		int* p4 = malloc(4);
		int* p5 = malloc(4);
		//各个指针之间相差16个字节,多出12个字节
		printf("p1 = %p\n",p1);
		printf("p2 = %p\n",p2);
		printf("p3 = %p\n",p3);
		printf("p4 = %p\n",p4);
		printf("p5 = %p\n",p5);

		printf("--------------------------\n");
		*p1 = 1;
		//*(p1+1) = 2;
		//*(p1+2) = 3;
		//*(p1+3) = 4;
		*(p1+4) = 5;
		*(p1+5) = 6;
		//表示释放指针p1所指向的那块内存
		free(p1);
		p1 = NULL;
		printf("*p2 = %d\n",*p2);//5
		return 0;
}
