#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int max(int a,int b,int *pi){
  if(a == b) return -1;
  *pi = (a>b)?a:b;
  return 0; 
}
int rand10(){
  srand(time(0));//设置随机的种子
  int r = rand()%10;
  if(r == 0) return -1;
  else return r;
}
void prints(const char* s1){
  printf("%s\n",s1);
}
char* iserror(char* s1){
  if(!strcmp(s1,"error")) return NULL;
  return s1;
}
int main(){
  int ma = 0;
  int x = max(-1,-1,&ma);
  if(x==-1) printf("比较发生了错误\n");
  else printf("ma=%d\n",ma);
  x = rand10();
  printf("x=%d\n",x);
  prints("hello");
}

