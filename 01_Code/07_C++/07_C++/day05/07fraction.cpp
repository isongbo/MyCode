#include <iostream>
using namespace std;
class  Fraction{
    private:
	int  x;
	int  y;
	public:
	Fraction(int x=0,int y=1):x(x),y(y){
	}
	void  show(){
        cout << x << '/' << y << endl;	
	}
private:	
friend Fraction  operator*(const Fraction& fa,
	const Fraction& fb);
friend ostream&  operator<<(ostream& os,
    const Fraction& fb);
friend istream&  operator>>(istream& is,
	Fraction& fb);
};
/* 设计一个全局函数 可以完成两个分数的相乘 */
Fraction  operator*(const Fraction& fa,
	const Fraction& fb){
    return Fraction(fa.x*fb.x,fa.y*fb.y);
}
/* 写一个全局函数 支持 operator<< */
ostream&  operator<<(ostream& os,
	const Fraction& fb){
    cout << fb.x << '/' << fb.y; 
	return  os;
}
/* 写一个输入运算符 operator>> */
istream&  operator>>(istream& is,
	Fraction& fb){
    cout << "请输入分子:" << endl;
	is >> fb.x;
	cout << "请输入分母:" << endl;
	is >> fb.y;
	return  is;
}
int main(){
    Fraction  fa(1,2);
	cin >> fa;
	fa.show();
	cout << fa << endl;
	cout << endl;
    Fraction  fb(1,3);
	fb.show();
	Fraction  fc=fa*fb;
	fc.show();
}


