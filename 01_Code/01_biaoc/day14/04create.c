#include <stdlib.h>
#include "04create.h"
void create(int *p_num, int size) {
	int num = 0;
	for (num = 0;num <= size - 1;num++) {
		*(p_num + num) = rand() % 36 + 1;
	}
}
