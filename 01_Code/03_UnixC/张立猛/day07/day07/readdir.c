#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(){
  DIR* dir = opendir("../");//打开目录
  if(dir==NULL) perror("open"),exit(-1);
  struct dirent* ent;
  while(ent=readdir(dir)){
    //1 读 2 赋值 3 判断ent!=NULL
    printf("%d,%s\n",ent->d_type,
	  ent->d_name);//d_type为4的是子目录
  }
  closedir(dir);
}


