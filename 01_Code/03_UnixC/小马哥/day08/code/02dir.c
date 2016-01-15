//遍历目录中的所有内容
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

void print(char* path)
{
	//1.打开目录
	DIR* dir = opendir(path);
	if(NULL == dir)
	{
		return;//退出条件
	}
	//2.读取目录中的内容
	struct dirent* ent;
	while(ent = readdir(dir))
	{
		//2.1 读取到的是目录，进入递归
		if(4 == ent->d_type)
		{
			printf("[%s]\n",ent->d_name);
			//对目录 . ..进行特殊处理
			if(!strcmp(ent->d_name,".") || !strcmp(ent->d_name,".."))
			{
				continue;//读取下一个
			}
			//将当前目录名和之前路径拼接起来
			char buf[100] = {0};
			sprintf(buf,"%s/%s",path,ent->d_name);
			print(buf);
		}
		//2.2 读取到的是文件，打印即可
		else
		{
			printf("%s\n",ent->d_name);
		}
	}
}

int main(void)
{
	print("../../day02/code");
	return 0;
}
