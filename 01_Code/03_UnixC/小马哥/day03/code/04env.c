//环境变量的相关操作
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
		printf("SHELL = %s\n",getenv("SHELL"));

		//不修改
		setenv("SHELL","/bin/csh",0);
		printf("SHELL = %s\n",getenv("SHELL"));
		//修改环境变量的值
		setenv("SHELL","/bin/csh",1);
		printf("SHELL = %s\n",getenv("SHELL"));
	
		printf("-------------------\n");
		//修改SHELL的值
		putenv("SHELL=/bin/bash");
		printf("SHELL = %s\n",getenv("SHELL"));
		//删除环境变量SHELL
		unsetenv("SHELL");
		printf("SHELL = %s\n",getenv("SHELL"));
		//清空环境表
		clearenv();
		printf("PATH = %s\n",getenv("PATH"));
		return 0;
}
