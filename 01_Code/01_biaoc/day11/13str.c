/*
   mystrlen练习
   */
#include <stdio.h>
int mystrlen(const char *src) {
	int pos = 0;
	/*while (*(src + pos)) {
        pos++;
	}*/
	while (1) {
		if (*(src + pos)) {
			pos++;
		}
		else {
			break;
		}
	}
	return pos;
}
int main() {
	printf("有效字符个数是%d\n", mystrlen("abcxyz"));
	return 0;
}
