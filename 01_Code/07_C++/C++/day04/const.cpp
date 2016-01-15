#include <iostream>
using namespace std;
class Student {
public:
	Student (string const& name, int age) :
		m_name (name), m_age (age) {}
	void print (void) const {
		cout << m_name << "，"
			<< /*++*/m_age << endl;
	}
	/*
	void print (Student const* this) {
		cout << this->m_name << "，"
			<< ++this->m_age << endl;
	const_cast<Student*> (this)->m_age
	}
	*/
private:
	string m_name;
	mutable int m_age;
};
int main (void) {
	Student student ("张飞", 25);
	student.print ();
	student.print ();
	Student const& r = student;
	r.print ();
	return 0;
}
