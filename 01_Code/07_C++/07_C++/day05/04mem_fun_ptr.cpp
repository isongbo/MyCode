#include <iostream>
using namespace std;
struct  Date{
	private:
    int  year;
	int  month;
	int  day;
	public:
	Date(int  year=2015,int month=1,
		int day=1):year(year),month(month),
	    day(day){
	
	}
    int  getYear(){
	    return year;
	}
	int  getMonth(){
	    return  month;
	}
};
int main(){
    Date  *pdate=new Date();
	/* 定义一个成员函数指针 指向 getYear 
	   并调用这个函数 */
	int  (Date::*pfun)();
    pfun=&Date::getYear;
	cout  << (pdate->*pfun)() << endl;
}

