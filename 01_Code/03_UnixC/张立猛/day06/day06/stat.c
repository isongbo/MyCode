#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
/*显示文件的i节点 类型+权限 硬链接数
  大小 最后修改时间*/
int main(){
  struct stat st;
  stat("a.txt",&st);//把a.txt的属性放入st
  printf("inode=%d\n",st.st_ino);//i节点
  printf("mode=%o\n",st.st_mode);
  printf("nlink=%d\n",st.st_nlink);
  printf("size=%d\n",st.st_size);//必须会
  printf("mtime=%s\n",
	ctime(&st.st_mtime));
 if(S_ISREG(st.st_mode))printf("文件\n");
 if(S_ISDIR(st.st_mode))printf("目录\n");
  printf("权限:%o\n",st.st_mode&07777);
}


