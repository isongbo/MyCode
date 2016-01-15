/*
   布雷练习
   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int map[10][10] = {};
	int delta[][2] = {{-1, -1}, {-1, 0}, 
		{-1, 1}, {0, -1}, {0, 1}, 
	    {1, -1}, {1, 0}, {1, 1}};
	int row = 0, col = 0, cnt = 0, num = 0;
	srand(time(0));
	//生成10个地雷放到二维数组里
    do {
        row = rand() % 10;
		col = rand() % 10;
		if (!map[row][col]) {
			map[row][col] = 10;
			cnt++;
		}
	} while (cnt < 10);
	//填充数字
	for (row = 0;row <= 9;row++) {
		for (col = 0;col <= 9;col++) {
			if (map[row][col] == 10) {
				continue;
			}
            cnt = 0;
            for (num = 0;num <= 7;num++) {
				if (row + delta[num][0] < 0) {
					continue;
				}
				if (row + delta[num][0] > 9) {
					continue;
				}
				if (col + delta[num][1] < 0) {
					continue;
				}
				if (col + delta[num][1] > 9) {
					continue;
				}
				if (map[row + delta[num][0]][col + delta[num][1]] == 10) {
					cnt++;
				}
			}
			map[row][col] = cnt;
		}
	}
	//把二维数组里的内容按顺序打印在屏幕上
	for (row = 0;row <= 9;row++) {
		for (col = 0;col <= 9;col++) {
			if (map[row][col] == 10) {
				printf("X");
			}
			else if (map[row][col] > 0) {
				printf("%d", map[row][col]);
			}
			else {
				printf("O");
			}
		}
		printf("\n");
	}
	return 0;
}




