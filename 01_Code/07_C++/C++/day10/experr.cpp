#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <iostream>
using namespace std;
class MemError {
public:
	MemError (string const& file, int line,
		string const& msg) : m_file (file),
		m_line (line), m_msg (msg) {}
	friend ostream& operator<< (ostream& os,
		MemError const& ex) {
		cout << ex.m_file << ':'
			<< ex.m_line << '#'
			<< ex.m_msg;
	}
private:
	string m_file;
	int m_line;
	string m_msg;
};
class A {
public:
	A (void) {
		cout << "A构造" << endl;
	}
	~A (void) {
		cout << "A析构" << endl;
	}
};
void fun3 (void) {
	A a;
	throw "没有错误！";
	FILE* fp = fopen ("none", "r");
	if (! fp)
		throw -1;
	char* pb = (char*)malloc (0xFFFFFFFF);
	if (! pb)
//		throw "内存分配失败！";
		throw MemError (__FILE__, __LINE__,
			strerror (errno));
	/*
	{
		MemError ex (__FILE__, __LINE__,
			strerror (errno));
		throw &ex;
	}
	*/
	// ...
}
void fun2 (void) {
	A a;
	// ...
	fun3 ();
	// ...
}
void fun1 (void) {
	A a;
	// ...
	fun2 ();
	// ...
}
int main (void) {
	try {
		A a;
		fun1 ();
		// ...
	}
	catch (int ex) {
		if (ex == -1) {
			cout << "文件打开失败！" << endl;
			return -1;
		}
	}
	catch (MemError& ex) {
		cout << ex << endl;
		return -1;
	}
	/*
	catch (MemError* ex) {
		cout << *ex << endl;
		return -1;
	}
	*/
	catch (...) {
		cout << "未知错误！" << endl;
		return -1;
	}
	// ...
	cout << "成功！" << endl;
	return 0;
}
