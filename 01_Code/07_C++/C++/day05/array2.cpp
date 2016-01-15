#include <cstring>
#include <iostream>
using namespace std;
class Array {
public:
	Array (size_t size) :
		m_array (new int[size]),
		m_size (size) {}
	// 析构函数
	~Array (void) {
		if (m_array) {
			delete[] m_array;
			m_array = NULL;
		}
	}
	// 拷贝构造函数————深拷贝
	Array (Array const& that) {
		m_array = new int[that.m_size];
		memcpy (m_array, that.m_array,
			that.m_size * sizeof (
			that.m_array[0]));
		m_size = that.m_size;
	}
	// 拷贝赋值运算符函数————深拷贝
	Array& operator= (Array const& that) {
		// 避免自赋值
		if (&that != this) {
			// 释放旧资源
			if (m_array) {
				delete[] m_array;
				m_array = NULL;
			}
			// 分配新资源
			m_array = new int[that.m_size];
			// 拷贝新内容
			memcpy (m_array, that.m_array,
				that.m_size * sizeof (
				that.m_array[0]));
			m_size = that.m_size;
		}
		// 返回自引用
		return *this;
	}
	size_t size (void) const {
		return m_size;
	}
	int& at (size_t index) {
		return m_array[index];
	}
	int const& at (size_t index) const {
		return const_cast<Array*> (
			this)->at (index);
	}
private:
	int* m_array; // 指针/引用型成员需要考虑
	              // 深拷贝问题
	size_t m_size;
};
void print (Array const& array) {
	for (size_t i = 0; i < array.size (); ++i)
		cout << array.at (i) << ' ';
	cout << endl;
}
int main (void) {
	Array array (20);
	for (int i = 0; i < array.size (); ++i)
		array.at (i) = i;
	print (array);
	/*
	Array a1 (5);
	a1.at (0) = 10;
	a1.at (1) = 20;
	a1.at (2) = 30;
	a1.at (3) = 40;
	a1.at (4) = 50;
	print (a1);
	Array a2 = a1;
	print (a2);
	*/
	Array* a1 = new Array (5);
	a1->at (0) = 10;
	a1->at (1) = 20;
	a1->at (2) = 30;
	a1->at (3) = 40;
	a1->at (4) = 50;
	print (*a1);
//	Array* a2 = new Array (*a1);
	Array* a2 = new Array (5);
	*a2 = *a1; // (*a2).operator= (*a1)
	print (*a2);
	a2->at(0)++;
	print (*a1);
	print (*a2);
	*a2 = *a2; // (*a2).operator= (*a2)
	print (*a2);
	delete a2;
	delete a1;
	return 0;
}
