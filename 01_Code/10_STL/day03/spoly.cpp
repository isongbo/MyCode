#include <iostream>
using namespace std;
class Rect {
public:
	void draw (void) const {
		cout << "绘制矩形" << endl;
	}
};
class Circle {
public:
	void draw (void) const {
		cout << "绘制圆形" << endl;
	}
};
// 多态函数
template<typename Shape>
void drawAny (Shape const& shape) {
	shape.draw ();
}
int main (void) {
	drawAny (Rect ());
	drawAny (Circle ());
	return 0;
}
