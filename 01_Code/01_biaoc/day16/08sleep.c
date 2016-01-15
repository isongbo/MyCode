/*
   sleep演示
   */
#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main() {
	printf("%ld\n", time(0));
	sleep(5);
	printf("%ld\n", time(0));
	return 0;
}
