/*
   结构体练习
   */
#include <stdio.h>
typedef struct {
	int row, col;
} pixel;
int main() {
	pixel pt1= {}, pt2 = {}, mid = {};
	pixel *p_pt1 = &pt1, *p_pt2 = &pt2, *p_mid = &mid;
    /*printf("请输入第一个点的位置：");
	scanf("%d%d", &(pt1.row), &(pt1.col));
	printf("请输入第二个点的位置：");
	scanf("%d%d", &(pt2.row), &(pt2.col));
	mid.row = (pt1.row + pt2.row) / 2;
	mid.col = (pt1.col + pt2.col) / 2;
	printf("中点位置是(%d, %d)\n", mid.row, mid.col);*/
	printf("请输入一个点的位置：");
	scanf("%d%d", &(p_pt1->row), &(p_pt1->col));
	printf("请输入另外一个点的位置：");
	scanf("%d%d", &(p_pt2->row), &(p_pt2->col));
	p_mid->row = (p_pt1->row + p_pt2->row) / 2;
	p_mid->col = (p_pt1->col + p_pt2->col) / 2;
	printf("中点位置是(%d, %d)\n", p_mid->row, p_mid->col);
	return 0;
}




