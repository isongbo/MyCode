//使用普通文件的方式加载共享库文件
#include <stdio.h>
#include <dlfcn.h>

int main(void)
{
		//1.打开共享库文件
		void* handler = dlopen("./max/libmax.so",RTLD_NOW);
		//2.判断是否打开错误
		char* error = dlerror();
		if(error)
		{
				printf("打开共享文件失败\n");
				return -1;
		}
		//3.获取函数的地址并且调用
		int (*pMax)(int,int);
		pMax = dlsym(handler,"max");
		error = dlerror();
		if(error)
		{
				printf("获取函数的地址失败\n");
				return -1;
		}

		printf("最大值是：%d\n",pMax(10,20));

		//4.关闭共享库文件
		dlclose(handler);
		return 0;
}
