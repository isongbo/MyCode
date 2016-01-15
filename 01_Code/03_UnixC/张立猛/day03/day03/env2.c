#include <stdio.h>
#include <stdlib.h>

int main(){//主函数的第三个参数也是环境表
  extern char** environ;//通用的环境表
  char* value = getenv("LANG");
  printf("value=%s\n",value);
  putenv("VAR=abc");
  printf("%s\n",getenv("VAR"));//abc
  putenv("VAR=123");
  printf("%s\n",getenv("VAR"));//123
  setenv("VAR","456",0);//不覆盖
  printf("%s\n",getenv("VAR"));//123
  setenv("VAR","789",1);//覆盖
  printf("%s\n",getenv("VAR"));//789
}

