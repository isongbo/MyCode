#include <iostream>
#include <fstream>
using namespace std;
int main (void) {
	ifstream ifs ("get.txt");
	if (! ifs) {
		cout << "打开文件失败！" << endl;
		return -1;
	}
	int ch;
	while ((ch = ifs.get ()) != EOF)
		cout.put (ch);
	/*
	char ch;
	while (ifs.get (ch))
		cout << ch;
	*//*
	char buf[1024];
	ifs.get (buf, 1024);
	cout << buf << endl;
	ifs.ignore (2);
	ifs.get (buf, 1024);
	cout << buf << endl;
	*//*
	char buf[1024];
	ifs.get (buf, 1024, '$');
	cout << buf << endl;
	*//*
	char buf[1024];
	while (ifs.getline (buf, 1024))
		cout << buf << endl;
	*//*
	ifs.ignore (1024, '\n');
	scanf ("%*[^\n]");
	ifs.ignore ();
	scnaf ("%*c");
	*/
	return 0;
}
