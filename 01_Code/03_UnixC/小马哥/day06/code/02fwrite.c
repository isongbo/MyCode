//使用标C函数实现向文件中写入0 ~ 100万的int数据
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
		//1.创建一个文件
		FILE* fp = fopen("num.dat","wb+");
		if(NULL == fp)
		{
				perror("fopen"),exit(-1);
		}
		//2.将0~100万的数值按照格式化写入文件
		int i = 0;
		for(i = 0; i < 1000000; i++)
		{
				//把整型变量按照格式放入字符数组中
				char buf[20] = {0};
				sprintf(buf,"%d\n",i);
				//写入数据
				fwrite(buf,strlen(buf),1,fp);
		}
		//3.关闭文件
		fclose(fp);
		//练习：使用UC函数实现同样的功能 03write.c
		return 0;
}
