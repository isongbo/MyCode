#include <iostream>
#include <iomanip>
using namespace std;
class Date{
    private:
	int  year;
	int  month;
	int  day;
	public:
	void  show(){
	    cout << setfill('0') << setw(4) <<
			year << '-' << setw(2) << month
			<< '-' << setw(2) << day << endl;
	}
	void  setDate(int y=2015,int m=1,int d=1){
	    year=y;
		month=m;
		day=d;
	}
};
int main(){
    Date  date;
	date.setDate();
	date.show();
	date.setDate(2020,10,1);
	date.show();
}



