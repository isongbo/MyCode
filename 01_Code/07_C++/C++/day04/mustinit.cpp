#include <iostream>
using namespace std;
int g_data = 1234;
class A {
public:
	A (void) : m_i (1000), m_r (g_data) {}
	int const m_i;
	int& m_r;
};
int main (void) {
	A a;
	cout << a.m_i << ' ' << a.m_r << endl;
	return 0;
}
