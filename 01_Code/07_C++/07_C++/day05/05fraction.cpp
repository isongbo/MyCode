#include <iostream>
using namespace std;
class  Fraction{
    public:
	int   x;
	int   y;
	public:
	Fraction(int x=0,int y=1):x(x),y(y){
	}
	void  show(){  
	    cout << x << '/' << y << endl;
	}
	/* 设计一个成员形式的 operator* */
    Fraction operator*(const Fraction& fb){
		cout << "mem operator*" << endl;
        return Fraction(x*fb.x,fb.y*y);
	}
	/* 成员形式的 operator+ */
	/* 成员形式的 operator*= */
};
/* 设计一个全局函数 负责两个分数的相乘 */
Fraction  mulFraction(const Fraction& fa,
	const Fraction& fb){
    return Fraction(fa.x*fb.x,fb.y*fa.y);
}
Fraction  operator*(const Fraction& fa,
	const Fraction& fb){
    return Fraction(fa.x*fb.x,fb.y*fa.y);
}
/* 仿照 乘法运算符 写一个加法运算符 */
Fraction  operator+(const Fraction& fa,
	const Fraction& fb){
    return Fraction(fa.x*fb.y+fa.y*fb.x,
		fa.y*fb.y);
}

int main(){
    Fraction  fa(1,2);
    fa.show();
	Fraction  fb(1,3);
    fb.show(); 
	Fraction  fc=mulFraction(fa,fb);
	fc.show();
	Fraction  fd=fa*fb;
	fd.show();
	Fraction  fe=fa+fb;
	fe.show();
}


