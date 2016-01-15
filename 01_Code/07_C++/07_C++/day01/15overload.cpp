#include <iostream>
using namespace std;
int  getmax(int x,int y){
    cout << "getmax(int,int)" << endl;
	return  x>y?x:y;
}
double getmax(int x,double y){
    cout << "getmax(int,double)" << endl; 
	return  x>y?x:y;
}
double getmax(double x,int y){
    cout << "getmax(double,int)" << endl;
	return  x>y?x:y;
}
int main(){
    getmax(1,2);
    getmax(1.5,2);
	getmax(1,2.5);
	// getmax(1.5,2.5);
/* 定义一个函数指针 使用指针调用第二个函数*/
   double (*pfun) (int x,double y);
   pfun=&getmax;
   pfun(1,2);
}


