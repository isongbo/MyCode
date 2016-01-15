#include <iostream>
#include <typeinfo>
using namespace std;
template<typename A,
	typename B = short, typename C = int>
class X {
public:
	void foo (void) const {
		cout << typeid (m_a).name () << ' '
			<< typeid (m_b).name () << ' '
			<< typeid (m_c).name () << endl;
	}
private:
	A m_a;
	B m_b;
	C m_c;
};
template<typename A,
	typename B = short, typename C = int>
void foo (void) {
	A a;
	B b;
	C c;
	cout << typeid (a).name () << ' '
		<< typeid (b).name () << ' '
		<< typeid (c).name () << endl;
}
template<typename T = string>
void bar (T const& t) {
	cout << typeid (t).name () << endl;
}
template<typename T>
void hum (T const& t = 123) {
	cout << typeid (t).name () << endl;
}
/*
void fun (int x, int y = x) {
	cout << x << ' ' << y << endl;
}
*/
template<typename A, typename B = A>
void fun (void) {
	cout << typeid (A).name () << ' '
		<< typeid (B).name () << endl;
}
int main (void) {
	X<char, short, int> x1;
	x1.foo ();
	X<char, short> x2;
	x2.foo ();
	X<char> x3;
	x3.foo ();
//	X<> x4;
//	x4.foo ();
	foo<char, short, int> ();
	foo<char, short> ();
	foo<char> ();
	bar/*<>*/ (100); // 隐式推断优于缺省参数
//	hum ();
	hum (456);
//	fun (123);
	fun<int> ();
	fun<int, double> ();
	return 0;
}
