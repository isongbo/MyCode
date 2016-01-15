//目录的基本操作
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(void)
{
	//1.打开目录
	DIR* dir = opendir("../code");
	if(NULL == dir)
	{
		perror("opendir"),exit(-1);
	}
	//2.读取目录中的内容进行打印
	struct dirent* ent = readdir(dir);
	while(ent != NULL)
	{
		//目录类型是4,普通文件类型是8
		printf("%d,%s\n",ent->d_type,ent->d_name);
		//读取下一个
		ent = readdir(dir);
	}
	return 0;
}


