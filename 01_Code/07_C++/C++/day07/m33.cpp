#include <iostream>
#include <iomanip>
using namespace std;
class M33 {
public:
	// 缺省构造
	M33 (void) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				m_a[i][j] = 0;
	}
	// 有参构造(类型转换)
	M33 (int a[][3]) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				m_a[i][j] = a[i][j];
	}
	// +
	M33 const operator+ (M33 const& m) const {
		int a[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				a[i][j] = m_a[i][j] +
					m.m_a[i][j];
		return a;
	}
	// -
	M33 const operator- (M33 const& m) const {
		int a[3][3];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				a[i][j] = m_a[i][j] -
					m.m_a[i][j];
		return a;
	}
	// *
	M33 const operator* (M33 const& m) const {
		int a[3][3] = {0};
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				for (int k = 0; k < 3; ++k)
					a[i][j] += m_a[i][k] *
						m.m_a[k][j];
		return a;
	}
	// +=
	M33& operator+= (M33 const& m) {
		return *this = *this + m;
	}
	// -=
	M33& operator-= (M33 const& m) {
		return *this = *this - m;
	}
	// *=
	M33& operator*= (M33 const& m) {
		return *this = *this * m;
	}
	// 负
	M33 const operator- (void) const {
		return M33 () - *this;
	}
	// 前++
	M33& operator++ (void) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				++m_a[i][j];
		return *this;
	}
	// 前--
	M33& operator-- (void) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				--m_a[i][j];
		return *this;
	}
	// 后++
	M33 const operator++ (int) {
		M33 m = *this;
		++*this;
		return m;
	}
	// 后--
	M33 const operator-- (int) {
		M33 m = *this;
		--*this;
		return m;
	}
	// []
	int* operator[] (size_t i) {
		return m_a[i];
	}
	int const* operator[] (size_t i) const {
		return const_cast<M33&> (*this)[i];
	}
	// <<
	friend ostream& operator<< (ostream& os,
		M33 const& m) {
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j)
				os << setw (4) << m.m_a[i][j];
			os << endl;
		}
		return os;
	}
private:
	int m_a[3][3];
};
int main (void) {
	int a1[3][3] = {1,2,3,4,5,6,7,8,9};
	M33 m1 (a1);
	int a2[3][3] = {9,8,7,6,5,4,3,2,1};
	M33 m2 (a2);
	cout << "<+>" << endl;
	cout << m1 + m2 << endl;
	cout << "<->" << endl;
	cout << m1 - m2 << endl;
	cout << "<*>" << endl;
	cout << m1 * m2 << endl;
	cout << "<+=>" << endl;
	m1 += m2;
	cout << m1 << endl;
	cout << "<-=>" << endl;
	m1 -= m2;
	cout << m1 << endl;
	cout << "<*=>" << endl;
	m1 *= m2;
	cout << m1 << endl;
	cout << "<负>" << endl;
	cout << -m1 << endl;
	cout << "<前++>" << endl;
	cout << ++m2 << endl << m2 << endl;
	cout << "<前-->" << endl;
	cout << --m2 << endl << m2 << endl;
	cout << "<后++>" << endl;
	cout << m2++ << endl << m2 << endl;
	cout << "<后-->" << endl;
	cout << m2-- << endl << m2 << endl;
	cout << "<[]>" << endl;
	m2[1][1] *= 10;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			cout << setw (4) << m2[i][j];
		cout << endl;
	}
	return 0;
}
