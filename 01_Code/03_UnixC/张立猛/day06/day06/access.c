#include <stdio.h>
#include <unistd.h>

int main(){
  if(access("a.txt",R_OK)==0)
	printf("可读\n");
  if(access("a.txt",W_OK)==0)
	printf("可写\n");
  if(access("a.txt",X_OK)==0)
	printf("可执行\n");
  if(access("a.txt",F_OK)==0)
	printf("文件存在\n");
}//练习：用access()和stat()显示access.c
//的权限和文件是否存在 以及文件的大小

