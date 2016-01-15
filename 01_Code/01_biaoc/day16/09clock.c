/*
   秒表练习
   */
#include <stdio.h>
#include <unistd.h>
int main() {
	int cnt = 0;
	while (1) {
		printf("%5d\r",cnt);
		fflush(stdout);
		cnt++;
		sleep(1);
	}
	return 0;
}
