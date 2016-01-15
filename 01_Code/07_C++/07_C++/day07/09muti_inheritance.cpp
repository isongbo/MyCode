#include <iostream>
using namespace std;
class  Phone{
    double   price;
	public:
    Phone(double price=0.0):price(price){
		cout << "Phone()" << endl;
	}
	double  getPrice(){
	    return  price;
	}
	void   callNum(string no){
	    cout << "给" << no << "打电话" 
			 << endl; 
	}
};
class  Camera{
    double   price;
	public:
    Camera(double price=0.0):price(price){
		cout << "Camera()" << endl;
	}
	double  getPrice(){
	    return  price;
	}
	void   camera(){
	    cout << "使用摄像机拍视频" << endl; 
	}
};
class  Mp3{
    double   price;
	public:
    Mp3(double price=0.0):price(price){
		cout << "Mp3()" << endl;
	}
	double  getPrice(){
	    return  price;
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
		double c=0.0):Mp3(m),Phone(p),
		Camera(c){
	    cout << "IPhone()" << endl; 
	}
	/* 名字隐藏机制的应用 */
	double  getPrice(){
	    return  Phone::getPrice()+
			    Camera::getPrice()+
				Mp3::getPrice();
	}
};
int main(){
    IPhone  iphone6s(2000,88,6000);
    cout << sizeof iphone6s << endl; 
	// cout << iphone6s.getPrice() << endl;
	iphone6s.callNum("15911085878");
	iphone6s.camera();
	iphone6s.play("传奇");
	cout << iphone6s.getPrice() << endl;
	cout << iphone6s.Phone::getPrice() << endl;
	cout << iphone6s.Mp3::getPrice() << endl;
}



