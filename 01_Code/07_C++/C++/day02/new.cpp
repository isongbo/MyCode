#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
void foo (void) {
	int* p0 = new int[1024];
	// ...
	delete[] p0;
}
int main (void) {
	int* p0 = new int[1024];
	// ...
	int* p1 = (int*)malloc (sizeof (int));
	*p1 = 1234;
	cout << *p1 << endl;
	free (p1);
	p1 = NULL;
	free (p1);
	int* p2 = new int;
	*p2 = 5678;
	cout << *p2 << endl;
	delete p2;
	p2 = NULL;
	delete p2;
	int* p3 = new int (100);
	cout << *p3 << endl;
	delete p3;
	int* p4 = new int[5];
	for (int i = 0; i < 5; ++i)
		p4[i] = i;
	for (int i = 0; i < 5; ++i)
		cout << p4[i] << ' ';
	cout << endl;
	delete[] p4;
	int* p5 = new int[5] {100, 200, 300};
	for (int i = 0; i < 5; ++i)
		cout << p5[i] << ' ';
	cout << endl;
	delete[] p5;
	// N维数组就是N-1维数组的一维数组，
	// N维数组的首地址就是一个N-1维数组的指针
	int (*p6)[4] = new int[3][4] {
		{11, 12, 13, 14},
		{21, 22, 23, 24},
		{31, 32, 33, 34}};
//	int *p6[4]; // 指针数组
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j)
			cout << p6[i][j] << ' ';
		cout << endl;
	}
	delete[] p6;
	int (*p7)[3][4] = new int[2][3][4] {
		{{111, 112, 113, 114},
		 {121, 122, 123, 124},
		 {131, 132, 133, 134}},
		{{211, 212, 213, 214},
		 {221, 222, 223, 224},
		 {231, 232, 233, 234}}};
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k < 4; ++k)
				cout << p7[i][j][k] << ' ';
			cout << endl;
		}
		cout << endl;
	}
	delete[] p7;
	char* p8 = (char*)malloc (0xFFFFFFFF);
	if (! p8)
		perror ("malloc");
	try {
		cout << "我要分配内存了！" << endl;
		char* p9 = new char[0xFFFFFFFF];
//		char* p9 = new char[10];
		cout << "分配内存成功了！" << endl;
		*p9 = 'A';
		cout << *p9 << endl;
		delete[] p9;
		cout << "释放内存成功了！" << endl;
	}
	catch (exception& ex) {
		cout << "分配内存失败了！" << endl;
		cout << ex.what () << endl;
	}
	char c[4];
	int* p = new (c) int (0x12345678);
	printf ("%#x, %#x, %#x, %#x\n",
		c[0], c[1], c[2], c[3]);
	return 0;
}
