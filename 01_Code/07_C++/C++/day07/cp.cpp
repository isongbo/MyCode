#include <iostream>
using namespace std;
class Base {
public:
	Base (int x = 0) : m_x (x) {
		cout << "基类构造函数" << endl;
	}
	Base (Base const& that) :
		m_x (that.m_x) {
		cout << "基类拷贝构造" << endl;
	}
	Base& operator= (Base const& that) {
		cout << "基类拷贝赋值" << endl;
		if (&that != this)
			m_x = that.m_x;
		return *this;
	}
	friend ostream& operator<< (ostream& os,
		Base const& base) {
		return os << base.m_x;
	}
protected:
	int m_x;
};
class Derived : public Base {
public:
	Derived (int x = 0, int y = 0) :
		Base (x), m_y (y) {
		cout << "子类构造函数" << endl;
	}
	Derived (Derived const& that) :
		Base (that), m_y (that.m_y) {
		cout << "子类拷贝构造" << endl;
	}
	Derived& operator= (Derived const& that) {
		cout << "子类拷贝赋值" << endl;
		if (&that != this) {
//			Base::operator= (that);
			static_cast<Base&> (*this) = that;
			m_y = that.m_y;
		}
		return *this;
	}
	void print (void) const {
		cout << m_x << ' ' << m_y << endl;
	}
	friend ostream& operator<< (ostream& os,
		Derived const& derived) {
		return os << static_cast<
			Base const&> (derived) << ' '
			<< derived.m_y;
	}
private:
	int m_y;
};
int main (void) {
	Derived d1 (123, 456);
	d1.print ();
	Derived d2 = d1;
	d2.print ();
	Derived d3 (654, 321);
	d3.print ();
	d3 = d1;
	d3.print ();
	cout << d3 << endl;
	return 0;
}
