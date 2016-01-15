/*
   结构体练习
   */
#include <stdio.h>
typedef struct {
	int row, col;
} pixel;
typedef struct {
	pixel pt1, pt2;
} rect;
int main() {
	rect r1 = {};
	int area = 0;
	printf("请输入水平长方形的位置：");
	scanf("%d%d%d%d", &(r1.pt1.row), &(r1.pt1.col), &(r1.pt2.row), &(r1.pt2.col));
	area = (r1.pt1.row - r1.pt2.row) * (r1.pt1.col - r1.pt2.col);
	area = area >= 0 ? area : 0 - area;
	printf("面积是%d\n", area);
	return 0;
}




