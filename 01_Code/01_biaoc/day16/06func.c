/*
   标准函数演示
   */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int num = atoi("435");
	double dnum = atof("34.87");
	printf("num是%d\n", num);
	printf("dnum是%lg\n", dnum);
	dnum = sqrt(36.0);
	printf("dnum是%lg\n", dnum);
	dnum = pow(2, 3);
	printf("dnum是%lg\n", dnum);
	return 0;
}



