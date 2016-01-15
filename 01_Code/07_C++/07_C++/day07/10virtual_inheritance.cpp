#include <iostream>
using namespace std;
/* 抽取共有部分 到高层类中 */
class  Product{
    double   price;
	public:
	Product(double price=0.0):price(price){
	
	}
	double  getPrice(){
	    return  price;
	}
};
class  Phone:virtual public Product{
	public:
    Phone(double price=0.0):Product(price){
		cout << "Phone()" << endl;
	}
	void   callNum(string no){
	    cout << "给" << no << "打电话" 
			 << endl; 
	}
};
class  Camera:virtual public Product{
	public:
    Camera(double price=0.0):Product(price){
		cout << "Camera()" << endl;
	}
	void   camera(){
	    cout << "使用摄像机拍视频" << endl; 
	}
};
class  Mp3:virtual public Product{
	public:
    Mp3(double price=0.0):Product(price){
		cout << "Mp3()" << endl;
	}
	void   play(string music){
	    cout << "使用Mp3播放" << music 
			 << endl; 
	}
};
/* 调用父类构造函数的顺序 只和继承顺序有关
   与其它无关 */
class  IPhone:public Phone,public Mp3,
	public Camera{
	public:
    IPhone(double p=0.0,double m=0.0,
		double c=0.0):Product(p+m+c){
	    cout << "IPhone()" << endl; 
	}
};
int main(){
	cout << sizeof(Phone) << endl;
    IPhone  iphone6s(2000,88,6000);
    cout << sizeof iphone6s << endl; 
	iphone6s.callNum("15911085878");
	iphone6s.camera();
	iphone6s.play("传奇");
	cout << iphone6s.getPrice() << endl;
}



