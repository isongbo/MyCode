#include <iostream>
using namespace std;
class  Date{
    int  year;
	int  month;
	int  day;
	public:
	Date(){
	    cout << "Date()" << endl;
	}
    void  show(){
	    cout << year << '-' << month << 
			'-' << day << endl;
	}
};
class  Emp{
    int     eno;
	double  salary;
	Date    startDate;
	public:
	Emp(){
	    cout << "Emp()" << endl;
		eno=0;
		salary=3500;
	}
	void  show(){
	    cout << eno << ":" << salary << endl;
		startDate.show();
	}
};
int main(){
    Emp  emp;
	emp.show();
}


