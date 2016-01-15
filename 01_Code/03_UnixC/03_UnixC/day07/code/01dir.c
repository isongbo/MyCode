//递归遍历目录中的所有内容
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void print(char* path)
{
	//1.打开目录
	DIR* dir = opendir(path);
	if(NULL == dir)
	{
		return;
	}
	//2.读取目录中的内容
	struct dirent* ent;
	while((ent = readdir(dir)) != NULL)
	{
		//2.1 如果是目录，先打印，再递归
		if(4 == ent->d_type)
		{
			printf("[%s]\n",ent->d_name);
			//跳过 . ..这两个特殊的目录
			if(!strcmp(ent->d_name,".") || !strcmp(ent->d_name,".."))
			{
				continue;//读取下一个内容
			}
			//拼接新的路径
			char buf[100] = {0};
			sprintf(buf,"%s/%s",path,ent->d_name);
			//递归调用
			print(buf);
		}
		//2.2 如果是普通文件,直接打印
		if(8 == ent->d_type)
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
