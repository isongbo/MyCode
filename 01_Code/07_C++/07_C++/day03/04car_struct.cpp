#include <iostream>
using namespace std;
struct  Car{
    /* 特征 */
	string   name;
	string   type;
	double   price;
	string   color;
	double   maxspeed;
	/* 行为 */
	void    show(){
	    cout << name << ":" << type 
			<< ":" << price << ":" << color
			<< ":" << maxspeed << "km/h" 
			<< endl; 
	}
	void    start(){
        cout << "汽车启动" << endl;	
	}
	void    run(double speed){
	    cout << "以时速" << speed << 
			"km" << "跑" << endl; 
	}
	void    stop(){
	    cout << "到达目的地 汽车停止" << endl;
	}
};
int main(){
	/* 实例化  car就是一个汽车对象 */
    Car   car;
	car.name="宝马";
	car.type="730";
	car.price=7000000.88;
	car.color="黑色";
    car.maxspeed=400;
    car.show();
	car.start();
	car.run(40);
    car.stop();
}



