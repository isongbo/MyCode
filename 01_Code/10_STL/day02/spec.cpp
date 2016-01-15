#include <cstring>
#include <iostream>
using namespace std;
// 类模板
template<typename T>
class Comparator {
public:
	Comparator (T x, T y) :
		m_x (x), m_y (y) {}
	T max (void) const {
		return m_x < m_y ? m_y : m_x;
	}
//	char const* max (void) const {
//		return strcmp (m_x, m_y) < 0 ? m_y :
//			m_x;
//	}
	T min (void) const {
		return m_x > m_y ? m_y : m_x;
	}
private:
	T m_x;
	T m_y;
};
/*
// 针对char const*的全类特化
template<>
class Comparator<char const*> {
public:
	Comparator (char const* a,
		char const* b) : m_a (a), m_b (b) {}
	char const* MAX (void) const {
		return strcmp (m_a, m_b) < 0 ?
			m_b : m_a;
	}
	char const* MIN (void) const {
		return strcmp (m_a, m_b) > 0 ?
			m_b : m_a;
	}
private:
	char const* m_a;
	char const* m_b;
};
*/
// 针对char const*的成员特化
template<>
char const* Comparator<char const*>::max (
	void) const {
	return strcmp (m_x, m_y) < 0 ? m_y : m_x;
}
template<>
char const* Comparator<char const*>::min (
	void) const {
	return strcmp (m_x, m_y) > 0 ? m_y : m_x;
}
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
	Comparator<char const*> c4 ("hello",
		"world");
//	cout << c4.MAX () << ' ' << c4.MIN ()
//		<< endl;
	cout << c4.max () << ' ' << c4.min ()
		<< endl;
	return 0;
}
