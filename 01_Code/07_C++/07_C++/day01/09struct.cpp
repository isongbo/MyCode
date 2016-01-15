#include <iostream>
#include <cstdio>
using namespace std;
struct  Date{
    int  year;
	int  month;
	int  day;
	/* 显示日期类型的数据 */
	void  show(){
	    printf("%04d-%02d-%02d\n",
		  year,month,day);   
	}
};
/* 写一个全局函数 用来显示一个日期变量 
   显示格式 yyyy-mm-dd */
void   showDate(Date* date){
    printf("%04d-%02d-%02d\n",date->year,
		date->month,date->day);
}
int main(){
    Date  date;
	cout << sizeof date << endl;
	cout << sizeof(Date) << endl;
	date.year=2015;
    date.month=3;
	date.day=13;
    showDate(&date);
	date.show();
}

