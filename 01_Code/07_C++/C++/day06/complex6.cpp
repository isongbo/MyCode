#include <iostream>
using namespace std;
class Complex {
public:
	Complex (int r, int i) :
		m_r (r), m_i (i) {}
	Complex const operator+ (
		Complex const& c) const {
		return Complex (m_r + c.m_r,
			m_i + c.m_i);
	}
	friend Complex const operator+ (
		Complex const&, int);
	Complex const foo (int i) const;
	void print (void) const {
		cout << '(' << m_r << '+' << m_i
			<< "i)" << endl;
	}
private:
	int m_r;
	int m_i;
};
Complex const operator+ (Complex const& c,
	int i) {
	return Complex (c.m_r + i, c.m_i);
}
Complex const Complex::foo (int i) const {
//	return *this + i;
	return ::operator+ (*this, i);
}
int main (void) {
	Complex c1 (1, 2);
	c1.foo (12).print (); // (13+2i)
	return 0;
}
