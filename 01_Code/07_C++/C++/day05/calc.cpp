#include <iostream>
using namespace std;
class Integer {
public:
	Integer (int data = 0) : m_data (data) {}
	Integer add (Integer const& rhs) const {
		return Integer (m_data + rhs.m_data);
	}
	void print (void) const {
		cout << m_data << endl;
	}
private:
	int m_data;
};
int main (void) {
	int a = 1, b = 2, c = 3, d = 4;
	/*
	int e = a + b;
	e = e + c;
	e = e + d;
	*/
	int e = a + b + c + d; // 中缀表达式
	cout << e << endl;
	Integer f (1), g (2), h (3), i (4);
//	Integer j = f + g + h + i;
	Integer j;
	j = j.add (f);
	j = j.add (g);
	j = j.add (h);
	j = j.add (i);
	j.print ();
	return 0;
}
