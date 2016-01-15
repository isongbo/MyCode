#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;
struct Date{
    int year;
	int month;
	int day;
};
/* 重载Date的输出运算符 operator<< 即可 */
ostream&   operator<<(ostream& os,
	const Date& date){
    return  os << setfill('0') << setw(4) 
		<< date.year << '-' << setw(2) 
		<< date.month << '-' << setw(2)
		<< date.day;
}
int main(){
    ostringstream  ostr;
	string  name="xiaoqiang";
	int     age=23;
	double  salary=8898.85;
	ostr << name << ":";
	ostr << age << ":" << salary;
	string  mystr=ostr.str();
	cout << mystr << endl;
	Date  date={2015,3,25};
    ostringstream  datestr;
	datestr << date;
    // cout << date << endl;
	string  dstr=datestr.str();
	cout << dstr << endl;
	/* 当前时间变成字符串 格式 
	   yyyymmddhh24:mi:ss */
	istringstream   
		strc("wangcai 22 18878.88");
	strc >> name >> age >> salary;
    cout << name << ":" << age << ":" 
		 << salary << endl;
}



