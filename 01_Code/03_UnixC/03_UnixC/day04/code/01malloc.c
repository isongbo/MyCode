//使用malloc在堆区申请动态内存
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* p1 = (int*)malloc(4);
	int* p2 = (int*)malloc(4);
	int* p3 = (int*)malloc(4);
	int* p4 = (int*)malloc(4);
	int* p5 = (int*)malloc(4);

	printf("p1 = %p\n",p1);
	printf("p2 = %p\n",p2);
	printf("p3 = %p\n",p3);
	printf("p4 = %p\n",p4);
	printf("p5 = %p\n",p5);

	printf("-----------------------\n");
	*p1 = 1;
	//*(p1+1) = 2;
	//*(p1+2) = 3;
	//*(p1+3) = 4;
	*(p1+4) = 5;
	//释放p1指向的动态内存
	free(p1); p1 = NULL;
	printf("*p2 = %d\n",*p2);
	return 0;
}




