#include <iostream>
#include <typeinfo>
using namespace std;
template</*typename*/class T = int,
	size_t S = 3>
class Array {
public:
	T& operator[] (size_t i) {
		return m_array[i];
	}
	T const& operator[] (size_t i) const {
		return const_cast<Array&> (*this)[i];
	}
	void printType (void) const {
		cout << typeid (m_array).name ()
			<< endl;
	}
private:
	T m_array[S];
};
int main (void) {
	Array<int, 3> a1;
	a1.printType ();
//	Array<string, 10> a2;
//	Array<string, 3+7> a2;
	size_t const /*volatile*/ S = 10;
	Array<string, S> a2;
	a2.printType ();
	Array<> a3;
	a3.printType ();
	return 0;
}
