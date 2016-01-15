#include <iostream>
using namespace std;
/* 饿汉模式
class Singleton {
public:
	static Singleton& getInstance (void) {
		return s_instance;
	}
	// ...
private:
	Singleton (int data = 0) : m_data (data){}
	Singleton (Singleton const& that) {}
	int m_data;
	static Singleton s_instance;
	// ...
};
Singleton Singleton::s_instance (1234);
*/
// 懒汉模式
class Singleton {
public:
	static Singleton& getInstance (void) {
		if (! s_instance)
			s_instance = new Singleton (1234);
		return *s_instance;
	}
	// ...
private:
	Singleton (int data = 0) : m_data (data){}
	Singleton (Singleton const& that) {}
	int m_data;
	static Singleton* s_instance;
	// ...
};
Singleton* Singleton::s_instance = NULL;
int main (void) {
	Singleton& s1 = Singleton::getInstance ();
	Singleton& s2 = Singleton::getInstance ();
	Singleton& s3 = Singleton::getInstance ();
	cout << &s1 << ' ' << &s2 << ' ' << &s3
		<< endl;
	return 0;
}
