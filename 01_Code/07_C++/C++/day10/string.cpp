#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;
int main (void) {
	int n = 123;
	double d = 4.56;
	const char* s = "hello";
	/*
	char buf[256];
	sprintf (buf, "%d %g %s", n, d, s);
	cout << buf << endl;
	*/
	ostringstream oss;
	oss << n << ' ' << d << ' ' << s;
	string str = oss.str ();
	cout << str << endl;
	istringstream iss ("world 6.54 321");
	iss >> str >> d >> n;
	cout << str << endl;
	cout << d << endl;
	cout << n << endl;
	istringstream iss2;
	iss2.str ("unix 100 3.14");
	iss2 >> str >> n >> d;
	cout << str << endl;
	cout << n << endl;
	cout << d << endl;
	return 0;
}
