#include <iostream>
using namespace std;
class Date{
    private:
	int  year;
	int  month;
	int  day;
	public:
/* 提供一个构造函数 完成对成员变量的赋值 */
	Date(int y=2015,int m=1,int d=1){
		cout << "Date()" << endl;
        year=y; 
		month=m;
		day=d;
	}
};
int main(){
    Date  date;
	Date  *pdate=new Date();
	Date  *pdate2=new Date;
	/* 编译器会理解成函数声明 */
    Date  date2();
	/* 创建一个对象 并赋值  */
	Date  date3(2014,1,1);
}




