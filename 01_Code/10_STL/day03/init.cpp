#include <iostream>
using namespace std;
class Integer {
public:
	Integer (int data = 1234) :
		m_data (data) {}
	operator int (void) {
		return m_data;
	}
private:
	int m_data;
};
template<typename T>
T foo (void) {
	T t = T ();
//	string t = string ();
//	Integer t = Integer ();
//	int t = int ();
	return t;
}
template<typename T>
class A {
public:
	A (void) : m_t () {}
	T m_t;
};
int main (void) {
	cout << '[' << foo<string> () << ']'
		<< endl;
	cout << '[' << foo<int> () << ']' << endl;
	cout << '[' << foo<Integer> () << ']'
		<< endl;
	cout << '[' << foo<void*> () << ']'
		<< endl;
	cout << "----------------" << endl;
	A<string> as;
	cout << '[' << as.m_t << ']' << endl;
	A<int> ai;
	cout << '[' << ai.m_t << ']' << endl;
	A<Integer> an;
	cout << '[' << an.m_t << ']' << endl;
	A<void*> ap;
	cout << '[' << ap.m_t << ']' << endl;
	return 0;
}
