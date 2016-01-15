#include <iostream>
using namespace std;
class Point2D {
public:
	Point2D (int x = 0, int y = 0) :
		m_x (x), m_y (y) {}
	void draw (void) const {
		cout << "2D(" << m_x << ',' << m_y
			<< ')' << endl;
	}
protected:
	int m_x;
	int m_y;
};
class Point3D : public Point2D {
public:
	void draw (void) const {
		cout << "3D(" << m_x << ',' << m_y
			<< ',' << m_z << ')' << endl;
	}
	static Point3D* create (int x = 0,
		int y = 0, int z = 0) {
		return new Point3D (x, y, z);
	}
private:
	Point3D (int x = 0, int y = 0, int z = 0):
		Point2D (x, y), m_z (z) {}
	int m_z;
};
/*
class Point4D : public Point3D {};
*/
int main (void) {
	Point2D p2 (100, 200);
	p2.draw ();
	Point3D* p3 = Point3D::create (300,
		400, 500);
	p3->draw ();
	delete p3;
//	Point4D p4;
	return 0;
}
