#include <iostream>
using namespace std;
int main (void) {
	int a = 10;
	cout << ++a << endl; // 11
	cout << a << endl; // 11
	++++++++a; // ++(++(++(++a)));
	cout << a << endl; // 15
	++a = 10;
	cout << a << endl; // 10
	cout << a-- << endl; // 10
	cout << a << endl; // 9
//	a--------;
//	a-- = 10;
	return 0;
}
