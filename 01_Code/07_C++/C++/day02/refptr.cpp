#include <iostream>
using namespace std;
int main (void) {
	int a;
	int& b = a;
	cout << sizeof (b) << endl;
	double c;
	double& d = c;
	cout << sizeof (d) << endl;
	int arr[5] = {10, 20, 30, 40, 50};
	// 数组引用——OK
	int (&ra)[5] = arr;
	for (int i = 0; i < 5; ++i)
		cout << ra[i] << ' ';
	cout << endl;
	int x, y, z;
	int* e[3] = {&x, &y, &z};
	// 引用数组——ERROR
//	int& e[3] = {x, y, z}; // 错误！
	int* p;
	// 指向指针的指针——OK
	int** pp = &p;
	int& r = a;
	// 引用引用的引用——ERROR
//	int&& rr = r; // 错误！
	// 引用指针的引用——OK
	int*& rp = p;
	// 指向引用的指针——ERROR
//	int&* pr = &r; // 错误！
	return 0;
}
