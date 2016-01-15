#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  printf("begin\n");
  int re=execl("/bin/ls","ls","-l",NULL);
  printf("re=%d\n",re);
  printf("end\n");
}

