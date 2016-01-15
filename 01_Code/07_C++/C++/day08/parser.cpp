// 模板方法模式————好莱坞模式
#include <iostream>
using namespace std;
class Parser {
public:
	void parse (char const* filename) {
		cout << "开始解析" << filename
			<< "文件..." << endl;
		// ...
		drawText ();
		// ...
		drawCircle ();
		// ...
		drawRectangle ();
		// ...
		drawImage ();
		// ...
		cout << "解析" << filename
			<< "文件完成！" << endl;
	}
private:
	virtual void drawText (void) = 0;
	virtual void drawCircle (void) = 0;
	virtual void drawRectangle (void) = 0;
	virtual void drawImage (void) = 0;
	// ...
};
class Render : public Parser {
private:
	void drawText (void) {
		cout << "绘制文字..." << endl;
	}
	void drawCircle (void) {
		cout << "绘制圆形..." << endl;
	}
	void drawRectangle (void) {
		cout << "绘制矩形..." << endl;
	}
	void drawImage (void) {
		cout << "绘制图像..." << endl;
	}
	// ...
};
int main (void) {
	Render render;
	render.parse ("stdc++.pdf");
	return 0;
}
