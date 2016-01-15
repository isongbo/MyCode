#include <iostream>
using namespace std;
template<typename T> class A {
public:
	static int m_data;
};
template<typename T> int A<T>::m_data = 1234;
int main (void) {
	A<int> a1, a2;
	cout << &a1.m_data << ' ' << &a2.m_data
		<< ' ' << &A<int>::m_data << endl;
	A<double> a3, a4;
	cout << &a3.m_data << ' ' << &a4.m_data
		<< ' ' << &A<double>::m_data << endl;
	return 0;
}
