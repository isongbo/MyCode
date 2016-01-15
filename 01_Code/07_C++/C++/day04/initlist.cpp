#include <iostream>
using namespace std;
class Point2D {
public:
	Point2D (int x = 0, int y = 0) :
		m_x (x), m_y (y) {
//		m_x = x;
//		m_y = y;
	}
	void print (void) {
		cout << "Point2D(" << m_x << ','
			<< m_y << ')' << endl;
	}
private:
	int m_x;
	int m_y;
	// 友元类
	// 指明Point3D类是Point2D类的闺蜜，Point3D
	// 类可以访问Point2D类的任何私有成员
	friend class Point3D;
};
class Point3D {
public:
	Point3D (int x = 0, int y = 0,
		int z = 0) : m_p (x, y), m_z (z) {
//		m_p.m_x = x;
//		m_p.m_y = y;
	}
	Point3D (int a[]) :
		m_a {a[0], a[1], a[2]} {}
	Point3D (int year, int mon, int day, int)
		: m_date {year, mon, day} {}
	void print (void) {
		cout << "Point3D(" << m_p.m_x << ','
			<< m_p.m_y << ',' << m_z << ')'
			<< endl;
	}
	void show (void) {
		cout << m_a[0] << ',' << m_a[1]
			<< ',' << m_a[2] << endl;
	}
	void date (void) {
		cout << m_date.m_year << "年"
			<< m_date.m_mon << "月"
			<< m_date.m_day << "日" << endl;
	}
private:
	Point2D m_p;
	int m_z;
	int m_a[3];
	struct Date {
		int m_year;
		int m_mon;
		int m_day;
	}	m_date;
};
int main (void) {
	Point2D pa (10, 20);
	pa.print ();
	Point3D pb (30, 40, 50);
	pb.print ();
	int a[] = {60, 70, 80};
	Point3D pc (a);
	pc.show ();
	Point3D pd (2014, 8, 7, 0);
	pd.date ();
	return 0;
}
