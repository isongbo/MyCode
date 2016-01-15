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
/*int len2(line l1) {
	return (l1.pt1.row - l1.pt2.row) * (l1.pt1.row - l1.pt2.row) + (l1.pt1.col - l1.pt2.col) * (l1.pt1.col - l1.pt2.col);
}*/
int len2(const line *p_l) {
	return (p_l->pt1.row - p_l->pt2.row) * (p_l->pt1.row - p_l->pt2.row) + (p_l->pt1.col - p_l->pt2.col) * (p_l->pt1.col - p_l->pt2.col);
}
int main() {
	line l1 = {}, l2 = {};
	printf("请输入第一条线段的位置：");
	scanf("%d%d%d%d", &(l1.pt1.row), &(l1.pt1.col), &(l1.pt2.row), &(l1.pt2.col));
	printf("请输入第二条线段的位置：");
	scanf("%d%d%d%d", &(l2.pt1.row), &(l2.pt1.col), &(l2.pt2.row), &(l2.pt2.col));
	if (len2(&l1) > len2(&l2)) {
		printf("比较长的线段位置是((%d, %d), (%d, %d))\n", l1.pt1.row, l1.pt1.col, l1.pt2.row, l1.pt2.col);
	}
	else {
		printf("比较长的线段位置是((%d, %d), (%d, %d))\n", l2.pt1.row, l2.pt1.col, l2.pt2.row, l2.pt2.col);
	}
	return 0;
}






