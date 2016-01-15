/*
   线段长度作业
   */
#include <stdio.h>
typedef struct {
	int row, col;
} pixel;
typedef struct {
    pixel pt1, pt2;
} line;
#define   LEN2(l)   (((l)->pt1.row - (l)->pt2.row) * ((l)->pt1.row - (l)->pt2.row) + ((l)->pt1.col - (l)->pt2.col) * ((l)->pt1.col - (l)->pt2.col))
int main() {
	line l1 = {}, l2 = {};
	printf("请输入第一条线段的位置：");
	scanf("%d%d%d%d", &(l1.pt1.row), &(l1.pt1.col), &(l1.pt2.row), &(l1.pt2.col));
	printf("请输入第二条线段的位置：");
	scanf("%d%d%d%d", &(l2.pt1.row), &(l2.pt1.col), &(l2.pt2.row), &(l2.pt2.col));
	if (LEN2(&l1) > LEN2(&l2)) {
		printf("比较长的线段位置是((%d, %d), (%d, %d))\n", l1.pt1.row, l1.pt1.col, l1.pt2.row, l1.pt2.col);
	}
	else {
		printf("比较长的线段位置是((%d, %d), (%d, %d))\n", l2.pt1.row, l2.pt1.col, l2.pt2.row, l2.pt2.col);
	}
	return 0;
}






