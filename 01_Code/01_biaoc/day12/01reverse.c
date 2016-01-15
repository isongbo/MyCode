/*
   颠倒数组内容作业
   */
#include <stdio.h>
int *reverse(int *p_num, int size) {
	int *p_first = p_num;
	int *p_last = p_num + size - 1;
	while (p_first < p_last) {
		int tmp = *p_first;
		*p_first = *p_last;
		*p_last = tmp;
		p_first++;
		p_last--;
	}
	return p_num;
}
int main() {
	int arr[] = {1, 2, 3, 4, 5}, num = 0;
    int *p_num = reverse(arr, 5);
    for (num = 0;num <= 4;num++) {
		printf("%d ", *(p_num + num));
		printf("%d ", arr[num]);
	}
	printf("\n");
	return 0;
}




