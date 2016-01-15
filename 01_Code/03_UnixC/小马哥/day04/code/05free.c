//使用free进行动态内存的回收
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
		printf("pid = %d\n",getpid());
		int* p1 = malloc(4096);
		printf("p1 = %p\n",p1);
		
		getchar();
		int* p2 = malloc(30*4096);
		printf("p2 = %p\n",p2);

		getchar();
		int* p3 = malloc(3*4096);
		printf("p3 = %p\n",p3);

		getchar();
		free(p3);
		printf("free p3\n");

		getchar();
		free(p2);
		printf("free p2\n");

		getchar();
		free(p1);
		printf("free p1\n");
		
		getchar();
		return 0;
}
