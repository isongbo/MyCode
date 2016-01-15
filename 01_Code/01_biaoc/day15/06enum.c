/*
   枚举类型演示
   */
#include <stdio.h>
enum season {
	CHUN,
	XIA = 6,
	QIU,
	DONG
};
int main() {
	enum season s;
	printf("QIU是%d\n", QIU);
	return 0;
}
