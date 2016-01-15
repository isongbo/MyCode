#include <iostream>
using namespace std;
int main (void) <%
	bool b = true;
	cout << boolalpha << b << noboolalpha
		<< ' ' << b << endl;
	b = false;
	cout << boolalpha << b << noboolalpha
		<< ' ' << b << endl;
	cout << sizeof (bool) << endl;
//	b = 1234;
//	b = 1.23;
//	b = 'A';
//	b = "Hello, World !";
//	b = *("Hello, World !" + 14);
//	b = "Hello, World !"[14];
	b = 14<:"Hello, World !":>;
	cout << boolalpha << b << endl;
//	a[b] <=> b[a] <=> *(a + b)
	return 0;
%>
