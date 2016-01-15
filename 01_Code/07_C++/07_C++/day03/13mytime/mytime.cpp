#include "mytime.h"
#include <iostream>
#include <iomanip>
using namespace std;
void  show(){
    cout << "this is show()" << endl;
	cout << g_var << endl;
}
	
MyTime::MyTime(int hour,int min,int sec)
	:hour(hour),min(min),sec(sec){

}
void  MyTime::setTime(int h,int m,int s){
    hour=h;
	min=m;
	sec=s;
}
void  MyTime::show(){
	/* 调用全局show函数 */
    ::show();
    cout << setfill('0') << setw(2) << hour
		<< ':' << setw(2) << min << ':' 
		<< setw(2) << sec << endl;
}

