#include <iostream>
using namespace std;
class Integer {
public:
	Integer (int data = 0) : m_data (data) {}
	Integer& operator++ (void) {
		++m_data;
		return *this;
	}
	Integer const operator++ (int) {
		Integer old = *this;
		++m_data;
		return old;
	}
	friend ostream& operator<< (ostream& os,
		Integer const& i) {
		return os << i.m_data;
	}
private:
	int m_data;
};
void foo (int const& i) {
	cout << i << endl;
}
int main (void) {
	/*
	int i = 0;
	++++i; // ++(++i)
	cout << i << endl;
	++i = 10;
	cout << i << endl; // 10
	int j = 0;
//	j++++; // (j++)++
	cout << j++ << endl; // 0
	cout << j << endl; // 1
//	j++ = 9;
//	j++ += 1;
	foo (++i);
	foo (i++);
	cout << i << endl; // 12
	*/
	Integer n;
	cout << ++n << endl; // 1
	cout << n << endl; // 1
	cout << n++ << endl; // 1
	cout << n << endl; // 2
	++++n;
	cout << n << endl; // 4
//	n++++;
//	cout << n << endl;
	return 0;
}
