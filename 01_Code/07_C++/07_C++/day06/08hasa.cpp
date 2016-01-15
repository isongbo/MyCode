#include <iostream>
using namespace std;
class  Radio{
	public:
    string  name;
	public:
	void   radioFun(){
	    cout << "收听广播" << endl;
	}
};
class  Car{
    public:
	Radio   r;
	double  price;
	void   carFun(){
	    cout << "代步" << endl;
	}
};
int main(){
    Car   car;
	car.r.name="test";
	cout << sizeof(car) << endl;
	car.r.radioFun();
	car.carFun();
}

