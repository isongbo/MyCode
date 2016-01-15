#include <iostream>
using namespace std;
int main (void) {
	int a = 10, b = 20, c = 30;
	(a = b) = c;
	cout << a << ' ' << b << ' ' << c << endl;
	// 30 20 30
	// (a + b) = c;
	return 0;
}
