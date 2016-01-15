/*
   随机数演示
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	srand(time(0));
    printf("%d\n", rand());
    printf("%d\n", rand());
    printf("%d\n", rand());
	return 0;
}
