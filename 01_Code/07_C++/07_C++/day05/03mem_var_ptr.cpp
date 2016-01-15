#include <iostream>
using namespace std;
struct Date{
    int  year;
	int  month;
	int  day;
};
int main(){
    Date  date={2015,10,8};
	/* 要求定义一个成员变量指针 指向 month
	   然后通过成员变量指针获取数据 */
	union{
    int  Date::*pm;
	int  *pi;
	};
	pm=&Date::month;
	cout << pm << ":" << pi << endl;
    cout << date.*pm << endl;
	pm=&Date::year;
	cout << pm << ":" << pi << endl;
    cout << date.*pm << endl;
	pm=&Date::day;
    cout << pm << ":" << pi << endl;
}

