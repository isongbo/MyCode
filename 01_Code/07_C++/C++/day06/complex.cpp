#include <iostream>
using namespace std;
class Complex {
public:
	Complex (int r = 0, int i = 0) :
		m_r (r), m_i (i) {}
	void print (void) const {
		cout << '(' << m_r << '+' << m_i
			<< "i)" << endl;
	}
private:
	int m_r;
	int m_i;
};
int main (void) {
	Complex c1 (1, 2);
	c1.print ();
	return 0;
}
