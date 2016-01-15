#include <iostream>
#include <iomanip>
using namespace std;
int main (void) {
	/*
	cout.precision (10);
	cout << 10.0 / 3.0 << endl;
	cout << cout.precision () << endl;
	cout.setf (ios::scientific,
		ios::floatfield);
	cout << 1000.0 / 3.0 << endl;
	cout << '[';
	cout.width (10);
	cout.fill ('*');
	cout.setf (ios::showbase);
	cout.setf (ios::internal,
		ios::adjustfield);
	cout.setf (ios::hex, ios::basefield);
	cout << 12345;
	cout << ']' << endl;
	*/
	cout << setprecision (10) << 10.0 / 3.0
		<< endl;
	cout << scientific << 1000.0 / 3.0
		<< endl;
	cout << '[' 
		<< setw (10)
		<< setfill ('*')
		<< showpos
		<< internal
		<< 12345
		<< ']'
		<< endl;
	return 0;
}
