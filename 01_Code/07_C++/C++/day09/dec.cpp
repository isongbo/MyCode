#include <iostream>
using namespace std;
class Base {
public:
	Base (void) {
		cout << "基类构造" << endl;
	}
	virtual ~Base (void) {
		cout << "基类析构" << endl;
	}
};
class Derived : public Base {
public:
	Derived (void) :
		m_buffer (new char[256]) {
		cout << "子类构造" << endl;
	}
	~Derived (void) {
		cout << "子类析构" << endl;
		delete[] m_buffer;
	}
private:
	char* m_buffer;
};
int main (void) {
	Base* pb = new Derived;
	delete pb; // 调用的是子类的析构函数，
	           // 该析构函数一方面析构子类特有
	           // 的资源，另一方面还会自动调用
	           // 基类的析构函数，最后连基类带
	           // 子类所有的资源全部析构干净
	return 0;
}
// 任何时候将基类的析构函数声明为虚函数，总不
// 会有坏处。
