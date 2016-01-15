#include <iostream>
using namespace std;
class Integer {
public:
	Integer (int i = 0) : m_i (i) {}
	operator int (void) const {
		return m_i;
	}
private:
	int m_i;
};
int main (void) {
	Integer i1 = 100;
	int n = i1;
	cout << i1 << endl;
	return 0;
}
