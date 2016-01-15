#include <iostream>
using namespace std;
#include "cmp.h"
int main (void) {
	cout << ::max (123, 456) << ' '
		<< ::min (123, 456) << endl;
	cout << ::max (1.23, 4.56) << ' '
		<< ::min (1.23, 4.56) << endl;
	cout << ::max<string> ("hello", "world")
		<< ' '
		<< ::min<string> ("hello", "world")
		<< endl;
	Comparator<int> ci (123, 456);
	cout << ci.max () << ' ' << ci.min ()
		<< endl;
	Comparator<double> cd (1.23, 4.56);
	cout << cd.max () << ' ' << cd.min ()
		<< endl;
	Comparator<string> cs ("hello", "world");
	cout << cs.max () << ' ' << cs.min ()
		<< endl;
	return 0;
}
