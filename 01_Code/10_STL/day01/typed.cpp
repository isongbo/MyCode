#include <iostream>
using namespace std;
int max_int (int x, int y) {
	return x > y ? x : y;
}
double max_double (double x, double y) {
	return x > y ? x : y;
}
string max_string (string x, string y) {
	return x > y ? x : y;
}
int main (void) {
	cout << max_int (123, 456) << endl;
	cout << max_double (1.23, 4.56) << endl;
	cout << max_string ("hello", "world")
		<< endl;
	return 0;
}
