#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Student {
public:
	Student (string const& name = "",
		int age = 0, int score = 0) :
		m_name (name), m_age (age),
		m_score (score) {}
	bool operator< (Student const& rhs) const{
//		return m_age < rhs.m_age;
//		return m_score > rhs.m_score;
		if (m_age == rhs.m_age)
			return m_score > rhs.m_score;
		return m_age < rhs.m_age;
	}
	friend ostream& operator<< (ostream& os,
		Student const& student) {
		return os << student.m_name << ','
			<< student.m_age << ','
			<< student.m_score;
	}
//private:
	string m_name;
	int m_age;
	int m_score;
};
typedef vector<Student>::iterator IT;
typedef vector<Student>::const_iterator CIT;
void print (vector<Student> const& vs) {
	for (CIT it = vs.begin (); it != vs.end();
		++it) cout << *it << endl;
}
bool intCmp (int x, int y) {
	return x > y;
}
class IntCmp {
public:
	bool operator() (int x,  int y) const {
		return x > y;
	}
};
int main (void) {
	int ai[] = {13, 27, 19, 27, 22};
	int* pi = find (ai, ai + 5, 27);
	if (pi == ai + 5)
		cout << "没找到！" << endl;
	else
		cout << "找到了：" << *pi
			<< " (" << *(pi+1) << ')' << endl;
	vector<int> vi (ai, ai + 5);
	vector<int>::iterator it = find (
		vi.begin (), vi.end (), 27);
	if (it == vi.end ())
		cout << "没找到！" << endl;
	else
		cout << "找到了：" << *it
			<< " (" << *(it+1) << ')' << endl;
	it = vi.begin ();
	while (true) {
		it = find (it, vi.end (), 27);
		if (it == vi.end ())
			break;
		*(it++) = 72;
	}
//	sort (vi.begin (), vi.end ());
//	sort (vi.rbegin (), vi.rend ());
//	sort (vi.begin (), vi.end (), intCmp);
	sort (vi.begin (), vi.end (), IntCmp ());
	for (it = vi.begin (); it != vi.end ();
		++it) cout << *it << ' ';
	cout << endl;
	vector<Student> vs;
	vs.push_back (Student ("a", 22, 90));
	vs.push_back (Student ("b", 25, 70));
	vs.push_back (Student ("c", 22, 80));
	vs.push_back (Student ("d", 18, 60));
	vs.push_back (Student ("e", 25, 85));
	print (vs);
	cout << "-------" << endl;
	sort (vs.begin (), vs.end ());
	print (vs);
	cout << "-------" << endl;
	Student s ("张飞", 30, 40);
	vs.push_back (s);
	cout << s << endl;
	cout << vs.back () << endl;
	vs.back ().m_name = "赵云";
	vs.back ().m_age = 10;
	vs.back ().m_score = 100;
	cout << s << endl;
	cout << vs.back () << endl;
	return 0;
}
