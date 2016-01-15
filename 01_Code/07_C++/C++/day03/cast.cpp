#include <iostream>
#include <cstdio>
using namespace std;
struct A {};
struct B : public A {
	B (void) {}
	B (A const&) {}
};
struct C {};
int main (void) {
	int i = 65;
//	char c = (char)i;
	char c = char(i);
	A a;
	B b;
	a = b;
	b = static_cast<B> (a);
	C cc;
//	a = cc;
//	cc = a;
//	a = static_cast<A> (cc);
//	cc = static_cast<C> (a);
	// 如果在源类型和目标类型之间有一个方向可
	// 以做隐式类型转换，那么在两个方向上都可
	// 以做静态类型转换。
	// 如果在源类型和目标类型之间哪个方向都不
	// 能做隐式类型转换，那么在两个方向上也都
	// 不能做静态类型转换。
	int volatile const x = 100;
	int volatile const* p = &x;
//	*p = 200;
	int* q = const_cast<int*> (p); // 去常
	*q = 200;
	cout << x << ' ' << *q << ' '
		<< *p << endl;
//	cout << 100 << ...
//	cout << x << ...
	cout << (void*)&x << ' ' << q << ' '
		<< (void*)p << endl;
	int volatile const& r = x;
	int& s = const_cast<int&> (r);
	s = 300;
	cout << x << endl;
//	double* t = const_cast<double*> (p);
	int y = 0x12345678;
	char* t = reinterpret_cast<char*> (&y);
	for (int i = 0; i < 4; ++i)
		printf ("%#x ", t[i]);
	cout << endl;
	i = reinterpret_cast<int> (t);
	printf ("%#x %p\n", i, t);
	return 0;
}
