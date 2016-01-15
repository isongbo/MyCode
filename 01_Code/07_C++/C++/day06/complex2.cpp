#include <iostream>
using namespace std;
class Complex {
public:
	Complex (int r = 0, int i = 0) :
		m_r (r), m_i (i) {}
	Complex& operator+= (Complex const& rhs) {
		m_r += rhs.m_r;
		m_i += rhs.m_i;
		return *this;
	}
	friend Complex& operator-= (Complex& lhs,
		Complex const& rhs) {
		lhs.m_r -= rhs.m_r;
		lhs.m_i -= rhs.m_i;
		return lhs;
	}
	void print (void) const {
		cout << '(' << m_r << '+' << m_i
			<< "i)" << endl;
	}
private:
	int m_r;
	int m_i;
};
int main (void) {
	Complex c1 (1, 2), c2 (3, 4);
	c1 += c2; // c1.operator+= (c2);
	c1.print (); // (4+6i)
	(c1 += c2) = c2;
	c1.print (); // (3+4i)
	c1 -= c2; // ::operator-= (c1, c2);
	c1.print (); // (0+0i)
	(c1 -= c2) = c2;
	c1.print (); // (3+4i)
	return 0;
}
