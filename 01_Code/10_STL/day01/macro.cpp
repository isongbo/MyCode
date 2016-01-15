#include <iostream>
using namespace std;
#define MAX(T) \
T max_##T (T x, T y) { \
	return x > y ? x : y; \
}
MAX (int) // int max_int (int x, int y) {...}
MAX (double)
MAX (string)
#define max(T) max_##T
int main (void) {
	cout << max(int) (123, 456) << endl;
//	cout << max_int (123, 456) << endl;
	cout << max(double) (1.23, 4.56) << endl;
	cout << max(string) ("hello", "world")
		<< endl;
	return 0;
}
