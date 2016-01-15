#include <iostream>
using namespace std;
// 形状：位置、绘制
// |
// +--圆形：半径、(绘制)
// +--矩形：长宽、(绘制)
// 形状
class Shape {
public:
	Shape (int x, int y) : m_x (x), m_y (y) {}
	virtual void draw (void) const = 0;
protected:
	int m_x; // 4
	int m_y; // 4
};
// 圆形
class Circle : public Shape {
public:
	Circle (int x, int y, int r) :
		Shape (x, y), m_r (r) {}
	virtual void draw (void) const {
		cout << "圆形(" << m_x << ','
			<< m_y << ',' << m_r << ')'
			<< endl;
	}
private:
	int m_r; // 4
};
// 矩形
class Rectangle : public Shape {
public:
	Rectangle (int x, int y, int w, int h) :
		Shape (x, y), m_w (w), m_h (h) {}
	void draw (void) const {
		cout << "矩形(" << m_x << ','
			<< m_y << ',' << m_w << ','
			<< m_h << ')' << endl;
	}
private:
	int m_w;
	int m_h;
};
class Triangle : public Shape {};
void render (Shape* shapes[]) {
	for (size_t i = 0; shapes[i]; ++i)
		shapes[i]->draw ();
}
void drawAny (Shape const& shape) {
	shape.draw ();
}
int main (void) {
	Shape* shapes[1024] = {0};
	shapes[0] = new Circle (1, 2, 3);
	shapes[1] = new Circle (4, 5, 6);
	shapes[2] = new Rectangle (7, 8, 9, 10);
	shapes[3] = new Rectangle (11,12,13,14);
	shapes[4] = new Circle (15, 16, 17);
	render (shapes);
	Circle cr (18, 19, 20);
	drawAny (cr);
	Rectangle rc (21, 22, 23, 24);
	drawAny (rc);
//	Shape* s = new Shape (25, 26);
//	Shape* s = NULL;
//	s->draw ();
//	Triangle t;
	cout << sizeof (Circle) << endl; // 16
	return 0;
}
