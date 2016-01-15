#include <iostream>
using namespace std;
class Complex {
public:
	Complex (int r = 0, int i = 0) :
		m_r (r), m_i (i) {}
	friend istream& operator>> (istream& is,
		Complex& c) {
		return is >> c.m_r >> c.m_i;
	}
	friend ostream& operator<< (ostream& os,
		Complex const& c) {
		return os << '(' << c.m_r << '+'
			<< c.m_i << "i)";
	}
private:
	int m_r;
	int m_i;
};
int main (void) {
	cout << "请输入一个复数：" << flush;
	Complex c1;
	cin >> c1;
	// cin.operator>> (c1);
	// ::operator>> (cin, c1);
	cout << c1 << endl;
	// cout.operator<< (c1).operator<< (endl);
	// ::operator<< (::operator<< (cout, c1),
	//     endl);
	return 0;
}
