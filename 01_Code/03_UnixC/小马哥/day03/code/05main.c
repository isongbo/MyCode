//主函数的使用
#include <stdio.h>

int main(int argc,char* argv[],char** env)
{
		printf("argc = %d\n",argc);
		printf("---------------------\n");
		int i = 0;
		for(i = 0; i < argc; i++)
		{
				printf("argv[%d] = %s\n",i,argv[i]);
		}

		extern char** environ;
		printf("environ = %p,env = %p\n",environ,env);
		return 0;
}
