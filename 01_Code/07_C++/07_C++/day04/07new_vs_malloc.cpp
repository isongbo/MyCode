#include <iostream>
using namespace std;
class Date{
    int  year;
	int  month;
	int  day;
	public:
	Date(){
	    cout << "Date()" << endl;
	}
	void show(){
	    cout << year << '-' << month << 
			'-' << day << endl;
	}
};
class  Emp{
    int   id;
	double salary;
	Date   startDate;
    public:
	Emp(){
		cout << "Emp()" << endl;
	    id=0;
		salary=4500;
	}
	void  show(){
	    cout << id << ":" << salary << endl;
		startDate.show();
	}
};
#include <cstdlib>
int main(){
    Emp *emp=new Emp();
	// Emp *emp=(Emp*)malloc(sizeof(Emp));
	emp->show();
}


