#include <iostream>
using namespace std;
inline int max (int x, int y) {
	return x < y ? y : x;
}
int main (void) {
	cout << max (123, 456) << endl;
	return 0;
}
