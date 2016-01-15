#include <iostream>
using namespace std;
class Product{
    int  pcount;
	double price;
	public:
	Product(){
	}
	Product(int pcount,double price)
		:pcount(pcount),price(price){
	}
	/* 重载() 运算符 */
	double  operator()(int c,double p,
		double pct){
	    return  c*p*pct;
	}
	/* 可以把 当前对象转换成希望的类型 */
    operator int (){
	    return  pcount;
	}
	operator double(){
	    return  price;
	}
};
int main(){
    Product  iphone6;
    cout << iphone6(10,5188.85,0.8) << endl;
    cout << iphone6(100,5188.85,0.7) << endl;
    Product  xiaomi4(50,1988.88);
	cout << (int)xiaomi4 << endl;
	cout << (double)xiaomi4 << endl;
}


