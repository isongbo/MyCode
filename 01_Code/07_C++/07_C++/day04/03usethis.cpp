#include <iostream>
using namespace std;
class Date;
void  showDate(Date* date);
class Date{
	public:
    int  year;
	int  month;
	int  day;
	public:
	Date(int year=2015,int month=1,int day=1){
	    this->year=year;
		this->month=month;
		this->day=day;
	}
	void  show(){
        showDate(this);	
	}
	Date&  addDay(){
	    day++;
		return  *this;
	}
};
/* 写一个全局函数  输出一个日期数据 */
void  showDate(Date* date){
    cout << date->year << '-' << date->month
		 << '-' << date->day << endl;
}
int main(){
    Date  date;
	date.show();
	date.addDay().addDay().show();
	date.show();
}



