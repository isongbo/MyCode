/*
   结构体指针形式参数练习
   */
#include <stdio.h>
typedef struct {
	int row, col;
} pixel;
pixel *read(pixel *p_pt) {
	printf("请输入点的位置：");
	scanf("%d%d", &(p_pt->row), &(p_pt->col));
	return p_pt;
}
void print(const pixel *p_pt) {
	printf("位置是(%d, %d)\n", p_pt->row, p_pt->col);
}
int main() {
    pixel pt = {}, *p_pt = NULL;
	p_pt = read(&pt);
	print(&pt);
	print(p_pt);
	return 0;
}


