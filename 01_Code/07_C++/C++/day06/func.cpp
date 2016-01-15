#include <iostream>
using namespace std;
class Square {
public:
	int operator() (int i) const {
		return i * i;
	}
	double operator() (double d) const {
		return d * d;
	}
};
int _square (int i) { return i * i; }
double _square (double d) { return d * d; }
class Power {
public:
	Power (int x = 0) :  m_x (x) {}
	// y^x
	double operator() (double y = 10) const {
		double res = 1;
		for (int i = 0; i < m_x; ++i)
			res *= y;
		return res;
	}
private:
	int m_x;
};
int main (void) {
	Square square;
	cout << square (2) << endl;
//	cout << square.operator() (2) << endl;
	cout << _square (2) << endl;
	cout << square (3.0) << endl;
//	cout << square.operator() (3.0) << endl;
	cout << _square (3.0) << endl;
	cout << Power (3) (2.0) << endl;
	cout << Power (4) (3.0) << endl;
	cout << Power (2) () << endl;
	return 0;
}
