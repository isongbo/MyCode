#include <iostream>
using namespace std;
// 通用版本
template<typename A, typename B>
class X {
public:
	static void print (void) {
		cout << "X<A,B>" << endl;
	}
};
// 针对第二个类型参数取short的局部特化
template<typename A>
class X<A, short> {
public:
	static void print (void) {
		cout << "X<A,short>" << endl;
	}
};
// 针对两个类型参数都取short的完全特化
template<>
class X<short, short> {
public:
	static void print (void) {
		cout << "X<short,short>" << endl;
	}
};
// 针对两个类型参数取相同类型的局部特化
template<typename A>
class X<A, A> {
public:
	static void print (void) {
		cout << "X<A,A>" << endl;
	}
};
// 针对两个类型参数都取指针类型的局部特化
template<typename A, typename B>
class X<A*, B*> {
public:
	static void print (void) {
		cout << "X<A*,B*>" << endl;
	}
};
// 针对两个类型参数都取同种类型指针的局部特化
template<typename A>
class X<A*, A*> {
public:
	static void print (void) {
		cout << "X<A*,A*>" << endl;
	}
};
// 针对两个类型参数都取引用类型的局部特化
template<typename A, typename B>
class X<A&, B&> {
public:
	static void print (void) {
		cout << "X<A&,B&>" << endl;
	}
};
// 针对两个类型参数都取数组类型的局部特化
template<typename A, typename B>
class X<A[], B[]> {
public:
	static void print (void) {
		cout << "X<A[],B[]>" << endl;
	}
};
template<typename A, typename B>
void foo (void) {
	cout << "foo<A,B>" << endl;
}
//template<typename A>
//void foo<A, short> (void) {}
template<>
void foo<int, short> (void) {
	cout << "foo<int,short>" << endl;
}
int main (void) {
	X<int, char>::print ();
	X<int, short>::print ();
	X<short, short>::print ();
	X<int, int>::print ();
	X<int*, short*>::print ();
	X<int*, int*>::print ();
	X<int&, short&>::print ();
	X<int[], short[]>::print ();
	foo<char, float> ();
	foo<int, short> ();
	return 0;
}
