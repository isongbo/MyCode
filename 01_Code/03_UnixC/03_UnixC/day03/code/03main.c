//main函数原型的使用
#include <stdio.h>

int main(int argc,char* argv[],char* envp[])
{
	//fopen("a.txt");
	//fopen("b.txt");
	printf("参数的个数：argc = %d\n",argc);
	int i = 0;
	for(i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n",i,argv[i]);
	}
	
	//环境表的首地址
	extern char** environ;
	printf("environ = %p\n",environ);
	printf("envp = %p\n",envp);
	return 0;
}




