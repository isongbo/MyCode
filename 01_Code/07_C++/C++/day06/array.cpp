#include <iostream>
using namespace std;
class Array {
public:
	int& operator[] (size_t index) {
		return m_array[index];
	}
	int const& operator[] (
		size_t index) const {
		return const_cast<Array&> (
			*this)[index];
	}
private:
	int m_array[100];
};
void print (Array const& array, size_t len) {
	for (size_t i = 0; i < len; ++i)
		cout << array[i] << ' ';
	cout << endl;
}
int main (void) {
	Array array;
	for (int i = 0; i < 10; ++i)
		array[i] = i;
	print (array, 10);
	Array a1;
	a1[0] = 10; // a1.operator[] (0) = 10;
	a1[1] = 20;
	a1[2] = 30;
	a1[3] = 40;
	a1[4] = 50;
	print (a1, 5);
	Array a2 = a1;
	print (a2, 5);
	return 0;
}
