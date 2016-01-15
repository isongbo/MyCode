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
A a;
int main (void) {
	cout << "main()函数开始了..." << endl;
//	{
//		A a;
//	}
	cout << "main()函数马上返回了..." << endl;
	return 0;
}
