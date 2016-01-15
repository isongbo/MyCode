#include <iostream>
using namespace std;
void foo (void) {
	cout << "foo(void)" << endl;
}
void foo (int a) {
	cout << "foo(int)" << endl;
}
void foo (int a, int b) {
	cout << "foo(int,int)" << endl;
}
// 重载与参数名无关
//void foo (int b, int a) {}
void foo (int a, double b) {
	cout << "foo(int,double)" << endl;
}
// 重载与返回类型无关
//int foo (int a, double b) {}
namespace ns1 {
	void bar (int x) {
		cout << "ns1::bar(int)" << endl;
	}
}
namespace ns2 {
	void bar (double x) {
		cout << "ns2::bar(dobule)" << endl;
	}
}
int main (void) {
	foo ();
	foo (10);
	foo (10, 1.23);
	void foo (int, int);
	foo (10, 1.23);
//	foo (10);
//	foo ();
	using namespace ns1;
	using namespace ns2;
	bar (10);
	bar (1.23);
	using ns1::bar;
	bar (10);
	bar (1.23);
	using ns2::bar;
	bar (10);
	bar (1.23);
	return 0;
}
