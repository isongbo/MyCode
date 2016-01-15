//对目录的常见操作
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
	//1.打开目录
	DIR* dir = opendir("../../day02/code");
	if(NULL == dir)
	{
		perror("opendir"),exit(-1);
	}
	printf("打开目录成功\n");
	//2.遍历目录下的内容
	struct dirent* ent;// = readdir(dir);
	//while(ent/* != NULL*/)
	while(ent = readdir(dir))
	{
		//普通文件类型是8,目录类型是4
		//printf("%d,%s\n",ent->d_type,ent->d_name);
		//printf("%d,%s\n",ent[0].d_type,ent[0].d_name);
		//注意下面的优先级问题
		//printf("%d,%s\n",(*(ent+0)).d_type,(*(ent+0)).d_name);
		printf("%d,%s\n",(*ent).d_type,(*ent).d_name);
		//读取目录中的下一个内容
		//ent = readdir(dir);
	}

	printf("----------------------\n");
	char buf[100] = {0};
	//获取当前进程的工作目录存放在buf中,当然也可以通过返回值带出来
	char* pc = getcwd(buf,sizeof(buf));
	printf("buf = %s\n",buf);
	printf("pc = %s\n",pc);
	return 0;
}
