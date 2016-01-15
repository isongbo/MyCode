#include <list>
#include <iostream>
using namespace std;
struct Date{
    int year;
	int month;
	int day;
	void show(){
	    cout << year << '-' << month << '-'
			 << day << endl;
	}
};
int main(){
    Date  datea={2015,10,1};
	Date  dateb={2020,10,2};
	Date  datec={2025,8,10};
    list<Date> dates;
    dates.push_back(datea);
	dates.push_back(dateb);
	dates.push_back(datec);
    list<Date>::iterator it;
	it=dates.begin();
	it->show();
	(*it).show();
	cout << "------------" << endl;
	/* 使用for循环 获取链表中的日期数据 */
	for(it=dates.begin();it!=dates.end();
		it++){
	    it->show(); 
	}
}





