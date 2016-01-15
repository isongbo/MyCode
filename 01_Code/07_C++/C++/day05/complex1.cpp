#include <iostream>
using namespace std;
class Complex {
public:
	Complex (int r = 0, int i = 0) :
		m_r (r), m_i (i) {}
	// 第一个const：返回右值
	// 第二个const：接受右值右操作数
	// 第三个const：接受右值左操作数
	const Complex operator+ (
		Complex const& rhs) const {
		return Complex (m_r + rhs.m_r,
			m_i + rhs.m_i);
	}
	void print (void) const {
		cout << '(' << m_r << '+' << m_i
			<< "i)" << endl;
	}
private:
	int m_r;
	int m_i;
	// 友元函数
	friend const Complex operator- (
		Complex const&, Complex const&);
};
const Complex operator- (Complex const& lhs,
	Complex const& rhs) {
	return Complex (lhs.m_r - rhs.m_r,
		lhs.m_i - rhs.m_i);
}
int main (void) {
	const Complex c1 (1, 2);
	const Complex c2 (3, 4);
	Complex c3 = c1 + c2;
//	Complex c3 = c1.operator+ (c2);
	c3.print (); // (4+6i)
//	(c1 + c2) = c3;
	c3 = c3 - c2;
//	c3 = ::operator- (c3, c2);
	c3.print (); // (1+2i)
	return 0;
}
