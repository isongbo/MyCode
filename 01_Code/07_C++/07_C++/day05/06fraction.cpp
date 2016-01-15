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
	/* 成员形式的 operator+ */
	Fraction  operator+(const Fraction& fb){
	    return  Fraction(x*fb.y+y*fb.x,
			y*fb.y);
	}
	/* 成员形式的 operator*= */
	void operator*=(const Fraction& fb){
	    cout << "mem operator*= " << endl;
        x=x*fb.x;
		y*=fb.y;
	}
};
/* 全局形式的 operator*=    fa*=fb 
void  operator*=(Fraction& fa,
	const Fraction& fb){
	cout << "operator*=" << endl;
    fa.x=fa.x*fb.x;
	fa.y*=fb.y;
}  */
int main(){
    Fraction  fa(1,2);
    fa.show();
	Fraction  fb(1,3);
    fb.show(); 
	Fraction  fc=fa+fb;
	fc.show();
	fa*=fb;
    fa.show();
}


