//stat函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

int main(void)
{
	struct stat st = {0};
	int res = stat("a.txt",&st);
	if(-1 == res)
	{
		perror("stat"),exit(-1);
	}
	// __off_t __time_t 本质都是long int
	printf("文件的类型和权限是：%o\n",st.st_mode);
	printf("文件的大小是：%ld\n",st.st_size);
	printf("文件的最后一次修改时间是：%ld\n",st.st_mtime);
	
	printf("---------------------\n");
	printf("文件的权限是：%o\n",st.st_mode&0777);
	printf("文件的最后一次修改时间是：%s\n",ctime(&st.st_mtime));
	
	if(S_ISREG(st.st_mode))
	{
		printf("该文件是一个普通文件\n");
	}
	if(S_ISDIR(st.st_mode))
	{
		printf("该文件是一个目录\n");
	}
	return 0;
}





