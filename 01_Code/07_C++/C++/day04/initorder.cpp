#include <iostream>
#include <cstring>
using namespace std;
class A {
public:
	A (char const* str) : m_str (str),
		m_len (strlen (str)) {}
	string m_str;
	int m_len;
};
int main (void) {
	A a ("12345");
	cout << a.m_len << ' ' << a.m_str << endl;
	return 0;
}
