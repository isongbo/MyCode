#include <cstdlib>
#include <cstring>
#include <iostream>
#include <typeinfo>
using namespace std;
// 两个任意类型值的最大值
template<typename T> // char const* const& x
T const& max (T const& x, T const& y) {
	cout << "<1" << typeid (x).name ()
		<< '>' << flush;
	return x < y ? y : x;
}
// 两个任意类型指针所指向目标的最大值
template<typename T> // char const** const& x
T* const& max (T* const& x, T* const& y) {
	cout << "<2" << typeid (x).name ()
		<< '>' << flush;
	return *x < *y ? y : x;
}
// 两个字符指针所指向字符串的最大值
char const* const& max (char const* const& x,
	char const* const& y) {
	cout << "<3" << typeid (x).name ()
		<< '>' << flush;
	return strcmp (x, y) < 0 ? y : x;
}
/*
// 在重载函数模板的时候，应该尽量把改变限制在
// 参数的具体类型和数量上，而不要改变其引用特
// 性，否则极有可能导致非预期的后果
char const* max (char const* x,
	char const* y) {
	cout << "<3" << typeid (x).name ()
		<< '>' << flush;
	return strcmp (x, y) < 0 ? y : x;
}
*/
// 三个任意类型值的最大值
template<typename T>
T const& max (T const& x, T const& y,
	T const& z) {
	cout << "<4" << typeid (x).name ()
		<< '>' << flush;
	return ::max (::max (x, y), z); // 3
	// 重载函数的备选方案是在函数模板被第一次
	// 编译的时候产生的，因此需要保证所有可能
	// 参与重载匹配的版本在第一次编译时都可见
}
/*
// 两个字符指针所指向字符串的最大值
char const* const& max (char const* const& x,
	char const* const& y) {
	cout << "<3" << typeid (x).name ()
		<< '>' << flush;
	return strcmp (x, y) < 0 ? y : x;
}
*/
int main (void) {
	int a = 123, b = 456;
	cout << ::max (a, b) << endl; // 1
	cout << *::max (&a, &b) << endl; // 2
	char const* x = "AB", *y = "ABC";
	cout << ::max (x, y) << endl; // 3
	// 隐式推断不支持隐式转换，因此如果调用
	// 参数的传递需要隐式转换，只能选择普通
	// 函数
	cout << ::max (x, (char*)y) << endl;
	// 带有尖括号的函数调用，只能选函数模板
	cout << ::max<> (x, y) << endl; // 2
	// 显式指定的模板参数必须在所选择的重载
	// 版本中与调用参数的类型保持一致
	cout << ::max<char const*> (x, y) << endl;
	// 1
	char const* z = "ABCD";
	char const* const& r = ::max (x, y, z);
	// 4
	cout << r << endl; // ABCD
	char const* m = "12", *n = "123",
		*o = "1234";
	cout << ::max (m, n, o) << endl; // 4
	cout << r << endl; // 1234 ?
	return 0;
}

