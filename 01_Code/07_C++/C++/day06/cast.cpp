#include <iostream>
using namespace std;
class Point2D {
public:
	Point2D (int x, int y) : m_x (x),
		m_y (y) {}
	friend ostream& operator<< (ostream& os,
		Point2D const& p2) {
		return os << "2D(" << p2.m_x << ','
			<< p2.m_y << ')';
	}
private:
	int m_x;
	int m_y;
	friend class Point3D;
};
class Point3D {
public:
	Point3D (int x, int y, int z) : m_x (x),
		m_y (y), m_z (z) {}
	// 在目标类型中定义从源类型的类型转换构造
	// 函数
	Point3D (Point2D const& p2) :
		m_x (p2.m_x), m_y (p2.m_y), m_z (0) {}
	// 在源类型中定义到目标类型的类型转换运算
	// 符函数
	operator Point2D (void) const {
		return Point2D (m_x, m_y);
	}
	friend ostream& operator<< (ostream& os,
		Point3D const& p3) {
		return os << "3D(" << p3.m_x << ','
			<< p3.m_y << ',' << p3.m_z << ')';
	}
private:
	int m_x;
	int m_y;
	int m_z;
};
int main (void) {
	Point2D p2 (100, 200);
	cout << p2 << endl;
	Point3D p3 = p2;
	cout << p3 << endl;
	Point2D p4 = p3;
	cout << p4 << endl;
	return 0;
}
