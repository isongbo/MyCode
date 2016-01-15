#include <stdio.h>
//#include "add.h"
#include <add.h>
int main(){
  int r1 = add(1,2);
  double r2 = add2(1.1,2.2);
  printf("r1=%d,r2=%lf\n",r1,r2);
  return 0;
}//gcc test.c add.c

