/*
   sprintf/sscanf函数演示
   */
#include <stdio.h>
int main() {
	char buf[20] = {};
	char ch = 't';
	int num = 45;
	float fnum = 4.76f;
	printf("%c %d %g\n", ch, num, fnum);
	sprintf(buf, "%c %d %g\n", ch, num, fnum);
	printf("%s\n", buf);
	sscanf("4.23 p 58", "%g %c %d", &fnum, &ch, &num);
	printf("%c %g %d\n", ch, fnum, num);
	return 0;
}



