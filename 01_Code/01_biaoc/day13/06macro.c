/*
   宏演示
   */
#include <stdio.h>
#define    PI           3.14f
#define    CIRCLE(r)    2 * PI * r
#define    AREA(r)      PI * r * r
int main() {
	int radius = 0;
	printf("请输入半径：");
	scanf("%d", &radius);
	printf("周长是%g\n", CIRCLE(radius));
	printf("面积是%g\n", AREA(radius));
	return 0;
}





