#include <iostream>
using namespace std;
extern "C" int add (int, int);
int main (void) {
	cout << add (123, 456) << endl;
	return 0;
}
