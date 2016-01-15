#include <iostream>
using namespace std;
template<typename T>
class Array {
public:
	T& operator[] (size_t i) {
		return m_array[i];
	}
	T const& operator[] (size_t i) const {
		return const_cast<Array&> (*this)[i];
	}
private:
	T m_array[3];
};
template<typename T>
void print (Array<T> const& array) {
	for (size_t i = 0; i < 3; ++i)
		cout << array[i] << ' ';
	cout << endl;
}
int main (void) {
	Array<int> a1;
	a1[0] = 10; // a1.operator[](0) = 10;
	a1[1] = 20;
	a1[2] = 30;
	print (a1);
	Array<string> a2;
	a2[0] = "北京";
	a2[1] = "达内";
	a2[2] = "科技";
	print (a2);
	Array<Array<int> > a3;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			a3[i][j] = (i+1)*10+j+1;
//			a3.operator[](i).operator[](j)
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			cout << a3[i][j] << ' ';
		cout << endl;
	}
	return 0;
}
