#include <cstring>
#include <iostream>
using namespace std;
int foo (char const* str) {
	return strlen (str);
}
int mul (int x = 2, int y = 2) {
	return x + y;
}
void bar (int, char, double = 3.14) {}
int main (void) {
	int (&rfoo) (char const*) = foo;
	cout << rfoo ("12345") << endl;
	int (*pfoo) (char const*) = &foo;
	cout << (*pfoo) ("ABCDE") << endl;
	cout << mul () << endl;
	bar (10, 'A');
	return 0;
}
