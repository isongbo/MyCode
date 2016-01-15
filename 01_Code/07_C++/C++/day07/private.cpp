#include <iostream>
using namespace std;
class Human {
public:
	int m_data;
};
//class Student : public Human {};
//class Student : private Human {};
class Student : protected Human {
public:
	int m_data;
};
int main (void) {
	Student s;
//	s.Human::m_data = 10;
//	Human* p = &s;
//	Human* p = static_cast<Human*> (&s);
	Human* p = (Human*)&s;
	cout << p << ' ' << &s << endl;
	p->m_data = 10;
//	Human& r = s;
	return 0;
}
