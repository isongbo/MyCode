#include <iostream>
#include <fstream>
using namespace std;
int main (void) {
	fstream fs ("seek.txt",
		ios::in | ios::out);
	fs << "0123456789";
	cout << fs.tellp () << endl;
	cout << fs.tellg () << endl;
	fs.seekp (-3, ios::cur);
	fs << "XYZ";
	fs.seekg (4, ios::beg);
	int a;
	fs >> a;
	cout << a << endl;
	string b;
	fs >> b;
	cout << b << endl;
	fs >> b;
	fs.clear ();
	fs.seekg (-3, ios::end);
	string c;
	fs >> c;
	cout << c << endl;
	return 0;
}
