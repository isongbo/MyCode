#include <iostream>
using namespace std;
// 类模板
template<typename T>
class Comparator {
public:
	Comparator (T x, T y) :
		m_x (x), m_y (y) {}
	Comparator (Comparator<T> const& that) :
		m_x (that.m_x), m_y (that.m_y) {}
	Comparator<T>& operator= (
		Comparator<T> const& rhs) {
		if (&rhs != this) {
			m_x = rhs.m_x;
			m_y = rhs.m_y;
		}
		return *this;
	}
	~Comparator (void) {}
	T max (void) const {
		return m_x < m_y ? m_y : m_x;
	}
	T min (void) const {
		return m_x > m_y ? m_y : m_x;
	}
	/*
	int add (int x, int y) const {
		return x + y;
	}
	*/
	int add (int, int) const;
private:
	T m_x;
	T m_y;
};
template<typename T>
int Comparator<T>::add (int x, int y) const {
	return x + y;
}
class Integer {
public:
	Integer (int data = 0) : m_data (data) {}
	bool operator< (Integer const& rhs) const{
		return m_data < rhs.m_data;
	}
	int m_data;
};
int main (void) {
	Comparator<int> c1 (123, 456);
	cout << c1.max () << ' ' << c1.min ()
		<< endl;
	Comparator<double> c2 (1.23, 4.56);
	cout << c2.max () << ' ' << c2.min ()
		<< endl;
	Comparator<string> c3 ("hello", "world");
	cout << c3.max () << ' ' << c3.min ()
		<< endl;
	cout << c3.add (100, 200) << endl;
	Comparator<string> c4 = c3;
	cout << c4.max () << ' ' << c4.min ()
		<< endl;
	Comparator<string> c5 ("beijing","china");
	c4 = c5;
	cout << c4.max () << ' ' << c4.min ()
		<< endl;
	Comparator<Integer> c6 (123, 456);
	cout << c6.max ().m_data << endl;
	return 0;
}
