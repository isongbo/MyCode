#include "date.h"	
#include <iostream>
#include <iomanip>
using namespace std;
Date::Date(int year,int month,int day)
	:year(year),month(month){
    this->day=day; 
}
void Date::setDate(int year,int month,
	int  day){
	/* 当成员函数的参数名和 成员变量
	   重名时 可以使用this指针区分 */
    this->year=year;
	this->month=month;
	this->day=day;
}
void Date::show(){
    cout << setfill('0') << setw(4) << year 
		 << '-' << setw(2) << month << '-'
		 << setw(2) << day << endl;
}

