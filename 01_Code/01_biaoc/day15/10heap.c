/*
   动态分配内存练习
   */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int row, col;
} pixel;
/*pixel *midpt(const pixel *p_pt1, const pixel *p_pt2) {
    pixel *p_pt = (pixel *)malloc(sizeof(pixel));
	if (p_pt) {
		p_pt->row = (p_pt1->row + p_pt2->row) / 2;
		p_pt->col = (p_pt1->col + p_pt2->col) / 2;
	}
	return p_pt;
}*/
void midpt(const pixel *p_pt1, const pixel *p_pt2, pixel **pp_pt) {
	*pp_pt = (pixel *)malloc(sizeof(pixel));
	if (*pp_pt) {
		(*pp_pt)->row = (p_pt1->row + p_pt2->row) / 2;
		(*pp_pt)->col = (p_pt1->col + p_pt2->col) / 2;
	}
}
int main() {
	pixel pt1 = {}, pt2 = {}, *p_pt = NULL;
	printf("请输入第一个点的位置：");
	scanf("%d%d", &(pt1.row), &(pt1.col));
	printf("请输入另外一个点的位置：");
	scanf("%d%d", &(pt2.row), &(pt2.col));
	//p_pt = midpt(&pt1, &pt2);
	midpt(&pt1, &pt2, &p_pt);
	if (p_pt) {
		printf("中点位置是(%d, %d)\n", p_pt->row, p_pt->col);
		free(p_pt);
		p_pt = NULL;
	}
	return 0;
}



