//错误编号和错误信息
#include <stdio.h>
#include <errno.h>
//extern int errno;
#include <string.h>

int main(void)
{
		printf("出错之前：errno = %d\n",errno);
		//1.打开文件
		FILE* fp = fopen("/etc/passwd1","r");
		if(NULL == fp)
		{
				printf("打开文件失败\n");
				printf("errno = %d\n",errno);
				printf("%s\n",strerror(errno));
				perror("fopen");
				printf("%m\n");
				//return -1;
		}
		printf("打开文件成功\n");
		//2.关闭文件
		//fclose(fp);

		printf("-----------------------\n");
		//练习：使用w的方式打开/etc/passwd,然后使用三种方法打印错误原因
		FILE* fp2 = fopen("/etc/passwd","r");
		if(NULL == fp2)
		{
				printf("errno = %d\n",errno);
				printf("%s\n",strerror(errno));
				perror("fopen2");
				printf("fopen2:%m\n");
		}
		printf("errno = %d\n",errno);
		return 0;
}
