#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		cout << "缺省构造" << endl;
	}
	A (A const& a) {
		cout << "拷贝构造" << endl;
	}
};
A foo (void) {
	A a;
	cout << "foo：" << &a << endl;
	return a;
}
int main (void) {
	A aa = foo ();
	cout << "main：" << &aa << endl;
	return 0;
}
// A的拷贝构造函数共执行几次？
// -fno-elide-constructors
// 关闭编译器对构造函数的优化
