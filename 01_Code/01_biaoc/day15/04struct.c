/*
   结构体练习
   */
#include <stdio.h>
typedef struct {
	int row, col;
} pixel;
pixel *midpt(const pixel *p_pt1, const pixel *p_pt2, pixel *p_mid) {
	p_mid->row = (p_pt1->row + p_pt2->row) / 2;
	p_mid->col = (p_pt1->col + p_pt2->col) / 2;
	return p_mid;
}
int main() {
    pixel pt1 = {}, pt2 = {}, mid = {};
	pixel *p_pt = NULL;
	printf("请输入第一个点的位置：");
	scanf("%d%d", &(pt1.row), &(pt1.col));
	printf("请输入第二个点的位置：");
	scanf("%d%d", &(pt2.row), &(pt2.col));
	p_pt = midpt(&pt1, &pt2, &mid);
	printf("中点位置是(%d, %d)\n", p_pt->row, p_pt->col);
	printf("中点位置是(%d, %d)\n", mid.row, mid.col);
	return 0;
}




