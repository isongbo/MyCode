#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  extern char** environ;//以NULL结束
  char** p=environ;//用局部变量p移动指针
  while(*p/*!=NULL*/){//!=NULl!=0可以省略
    printf("%s\n",*p);//*p是字符串
    p++;//Y
	//*p++;//Y,先算p++，然后对p取*
	//**p++;//Y  //(*p)++;//N
  }
  p = environ;//回复p的指向,回到首地址
  char value[100] = {};
  //练习:把LANG的值存入value中，并打印
  //strncmp()可以比较前n个字符
  while(*p){
    if(strncmp(*p,"LANG=",5) == 0)
      strcpy(value,*p+5);
	p++;
  }
  printf("value=%s\n",value);
  return 0;
}

