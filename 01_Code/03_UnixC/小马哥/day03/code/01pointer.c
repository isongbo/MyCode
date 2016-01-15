//指针的深入浅出
#include <stdio.h>

int main(void)
{
		int num = 66;
		int* pNum = &num;
		int** ppNum = &pNum;

		printf("num = %d\n",num);
		printf("*pNum = %d\n",*pNum);
		printf("**ppNum = %d\n",**ppNum);
	
		printf("-----------------------\n");
		printf("&num = %p\n",&num);
		printf("pNum = %p\n",pNum);
		printf("*ppNum = %p\n",*ppNum);

		printf("---------------------\n");
		printf("&pNum = %p\n",&pNum);
		printf("ppNum = %p\n",ppNum);

		printf("-----------------------\n");
		printf("&ppNum = %p\n",&ppNum);
		return 0;
}
