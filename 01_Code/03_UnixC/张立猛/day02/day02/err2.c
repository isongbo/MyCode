#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(){
  FILE* file = fopen("/etc/passwd1","r");
  if(file == NULL){//出错了
    printf("errno=%d\n",errno);
    printf("%s\n",strerror(errno));
	printf("%m\n");
	perror("a");//打印错误信息并换行
  } else {
	printf("没问题\n");
	fclose(file);
  }
}

