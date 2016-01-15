#include <iostream>
using namespace std;
class Integer {
public:
	// 无参构造函数，缺省构造函数
	Integer (void) {
		m_i = 0;
	}
	// 单参构造函数，类型转换构造函数
	Integer (int i) {
		m_i = i;
	}
	// 拷贝构造函数
	Integer (Integer const& that) {
//	Integer (Integer that) {
		m_i = that.m_i;
	}
	int& value (void) {
		return m_i;
	}
private:
	int m_i;
};
class B {};
class A {
public:
	// 通过以下类型转换构造函数完成的类型转换
	// 必须显式进行
	// ————A (...)/static_cast<A> (...)
	explicit A (B const& b) {
		// ...
	}
};
int main (void) {
	Integer i1;
	cout << i1.value () << endl; // 0
	Integer i2 (10);
	cout << i2.value () << endl; // 10
	i2 = 100; // i2 = Integer (100);
	cout << i2.value () << endl; // 100
	B b;
	A a (b);
//	a = b;
	a = static_cast<A> (b);
//	Integer i3 = i2;
	Integer i3 (i2);
	cout << i3.value () << endl;
	return 0;
}
/*
int i = 10; // 初始化
i = 20; // 赋值
*/
