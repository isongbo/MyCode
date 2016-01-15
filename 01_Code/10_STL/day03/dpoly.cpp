#include <iostream>
using namespace std;
class Shape {
public:
	virtual void draw (void) const = 0;
};
class Rect : public Shape {
public:
	void draw (void) const {
		cout << "绘制矩形" << endl;
	}
};
class Circle : public Shape {
public:
	void draw (void) const {
		cout << "绘制圆形" << endl;
	}
};
// 多态函数
void drawAny (Shape const& shape) {
	shape.draw ();
}
int main (void) {
	drawAny (Rect ());
	drawAny (Circle ());
	return 0;
}
