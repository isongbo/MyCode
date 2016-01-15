#include <iostream>
using namespace std;
void foo (void) {
	cout << "foo(void)" << endl;
}
void foo (int n) {
	cout << "foo(int)" << endl;
}
void foo (double d) {
	cout << "foo(double)" << endl;
}
/*
int foo (double d) {
	return 0;
}
*/
int main (void) {
	// 根据函数指针类型中的参数表信息，
	// 确定其所指向的重载版本
	void (*pfun1) (void) = foo;
	void (*pfun2) (int) = foo;
	void (*pfun3) (double) = foo;
	pfun1 ();
	pfun2 (1234);
	pfun3 (1.23);
//	int (*pfun4) (double) = foo;
	return 0;
}
