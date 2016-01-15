#include <cstdlib>
#include <iostream>
using namespace std;
//void foo (int i) throw (int, double) {
//void foo (int i) throw (int, double,
//	char const*) {
//void foo (int i) { // 可抛出任何异常
void foo (int i) throw () { // 不抛出任何异常
	if (i == 1)
		throw 100;
	if (i == 2)
		throw 3.14;
	if (i == 3)
		throw "Hello, World !";
}
int main (int argc, char* argv[]) {
	if (argc < 2) {
		cout << "参数不够！" << endl;
		return -1;
	}
	try {
		foo (atoi (argv[1]));
	}
	catch (int ex) {
		cout << ex << endl;
	}
	catch (double ex) {
		cout << ex << endl;
	}
	catch (char const* ex) {
		cout << ex << endl;
	}
	return 0;
}
