#include <cstdio>
#include <iostream>
using namespace std;
class A {
public:
	A (void) {
		cout << "A构造" << endl;
	}
	~A (void) {
		cout << "A析构" << endl;
	}
};
int fun3 (void) {
	A a;
	FILE* fp = fopen ("none", "r");
	if (! fp)
		return -1;
	// ...
	return 0;
}
int fun2 (void) {
	A a;
	// ...
	if (fun3 () == -1)
		return -1;
	// ...
	return 0;
}
int fun1 (void) {
	A a;
	// ...
	if (fun2 () == -1)
		return -1;
	// ...
	return 0;
}
int main (void) {
	if (fun1 () == -1) {
		cout << "文件打开失败！" << endl;
		return -1;
	}
	// ...
	cout << "成功！" << endl;
	return 0;
}
