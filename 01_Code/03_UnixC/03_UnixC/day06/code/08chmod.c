//修改文件的大小和权限
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
	//1.获取文件a.txt的权限和大小
	struct stat s = {0};
	int res = stat("a.txt",&s);
	if(-1 == res)
	{
		perror("stat"),exit(-1);
	}
	printf("文件的权限是：%o\n",s.st_mode&0777);
	printf("文件的大小是：%ld\n",s.st_size);
	//2.修改文件a.txt的权限和大小
	res = chmod("a.txt",0600);
	if(-1 == res)
	{
		perror("chmod"),exit(-1);
	}
	res = truncate("a.txt",100);
	if(-1 == res)
	{
		perror("truncate"),exit(-1);
	}
	printf("修改权限和大小成功\n");
	//3.获取修改后的结果
	res = stat("a.txt",&s);
	if(-1 == res)
	{
		perror("stat2"),exit(-1);
	}
	printf("修改之后的权限是：%o\n",s.st_mode&0777);
	printf("修改之后的大小是：%ld\n",s.st_size);
	return 0;
}


