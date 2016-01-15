#include <iostream>
using namespace std;
int add (int x, int y) {
	return x + y;
}
int sub (int x, int y) {
	return x - y;
}
int mul (int x, int y) {
	return x * y;
}
int div (int x, int y) {
	return x / y;
}
int mod (int x, int y) {
	return x % y;
}
// 多态函数
int cal (int x, int y, int (*fun) (int,int)) {
	return fun (x, y);
}
int main (void) {
	int x = 456, y = 123;
	cout << cal (x, y, add) << endl;
	cout << cal (x, y, sub) << endl;
	cout << cal (x, y, mul) << endl;
	cout << cal (x, y, div) << endl;
	cout << cal (x, y, mod) << endl;
	return 0;
}
