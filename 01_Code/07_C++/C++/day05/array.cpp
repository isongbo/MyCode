#include <iostream>
using namespace std;
class Array {
public:
	int& at (size_t index) {
		return m_array[index];
	}
	int const& at (size_t index) const {
		return const_cast<Array*> (
			this)->at (index);
	}
private:
	int m_array[100];
};
void print (Array const& array, size_t len) {
	for (size_t i = 0; i < len; ++i)
		cout << array.at (i) << ' ';
	cout << endl;
}
int main (void) {
	Array array;
	for (int i = 0; i < 10; ++i)
		array.at (i) = i;
	print (array, 10);
	Array a1;
	a1.at (0) = 10;
	a1.at (1) = 20;
	a1.at (2) = 30;
	a1.at (3) = 40;
	a1.at (4) = 50;
	print (a1, 5);
	Array a2 = a1;
	print (a2, 5);
	return 0;
}
