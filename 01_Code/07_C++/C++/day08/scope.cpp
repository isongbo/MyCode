#include <iostream>
using namespace std;
class A {
public:
	A (void) { cout << "A构造" << endl; }
	~A (void) { cout << "A析构" << endl; }
};
/*
A a1;
int main (void) {
	A a2;
	{
		A a3;
	}
	return 0;
}
int main (void) {
	for (int i = 0; i < 3; ++i) {
		A a;
		if (i == 0)
//			continue;
//			break;
			goto escape;
		// ...
	}
	// ...
escape:
	cout << "main()函数即将返回..." << endl;
	return 0;
}
*/
int main (void) {
	if (1) {
		A a;
		if (1) {
			A a;
			if (1) {
				A a;
				goto escape;
				cout << 3 << endl;
			}
			cout << 2 << endl;
		}
		cout << 1 << endl;
	}
escape:
	cout << "我要返回了！" << endl;
	return 0;
}
