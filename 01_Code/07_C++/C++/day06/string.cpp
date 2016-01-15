#include <cstring>
#include <iostream>
using namespace std;
class String {
public:
	// 接受C风格字符串的(类型转换)构造函数
	String (char const* str = NULL) :
		m_str (strcpy (
		new char[strlen (str ? str : "") + 1],
	   	str ? str : "")) {}
	// 拷贝构造函数
	String (String const& that) :
		m_str (strcpy (
		new char[strlen (that.m_str) + 1],
		that.m_str)) {}
	// 拷贝赋值运算符函数
	/* 菜鸟
	void operator= (String const& rhs) {
		m_str =	new char[strlen (
			rhs.m_str) + 1];
		strcpy (m_str, rhs.m_str);
	}
	*/
	/* 小鸟
	String& operator= (String const& rhs) {
		if (&rhs != this) {
			delete[] m_str;
			m_str =	new char[strlen (
				rhs.m_str) + 1];
			strcpy (m_str, rhs.m_str);
		}
		return *this;
	}
	*/
	/* 大鸟
	String& operator= (String const& rhs) {
		if (&rhs != this) {
			char* str = new char [strlen (
				rhs.m_str) + 1];
			delete[] m_str;
			m_str = strcpy (str, rhs.m_str);
		}
		return *this;
	}
	*/
	// 老鸟
	String& operator= (String const& rhs) {
		if (&rhs != this) {
			String str (rhs);
			swap (m_str, str.m_str);
		}
		return *this;
	}
	// 析构函数
	~String (void) {
		if (m_str) {
			delete[] m_str;
			m_str = NULL;
		}
	}
	// 获取C风格字符串
	char const* c_str (void) const {
		return m_str;
	}
	/*
	friend ostream& operator<< (ostream& os,
		String const& str) {
		return os << str.m_str;
	}
	*/
	ostream& operator>> (ostream& os) {
		return os << m_str;
	}
	char& operator[] (size_t i) {
		return m_str[i];
	}
	char const& operator[] (size_t i) const {
		return const_cast<String&> (*this)[i];
	}
	operator char const* (void) const {
		return m_str;
	}
private:
	char* m_str;
};
ostream& operator<< (ostream& os,
	String const& str) {
	return os << str.c_str ();
}
int main (void) {
	String s1 ("达内科技");
	cout << s1.c_str () << endl;
	String s2 = s1;
	cout << s2.c_str () << endl;
	String s3 ("Hello, World !");
	s1 = s3;
	cout << s1.c_str () << endl;
	cout << s1 << endl;
	s1[7] = 'L';
//	s1.operator[] (7) = 'L';
//	*(s1.operator char const* () + 7) = 'L';
	s1[8] = 'i';
	s1[9] = 'n';
	s1[10] = 'u';
	s1[11] = 'x';
	s1 >> cout << endl;
	char const* s4 = "Hello, Unix !";
	int res = strcmp (s1, s4);
	if (res > 0)
		cout << s1 << "大于" << s4 << endl;
	else
	if (res < 0)
		cout << s1 << "小于" << s4 << endl;
	else
		cout << s1 << "等于" << s4 << endl;
	return 0;
}
