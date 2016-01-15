#include <iostream>
using namespace std;
class  Date{
    private:
	int  year;
	int  month;
	int  day;
	public:
	Date(int year=2015,int month=1,int day=1)
		:year(year),month(month),day(day){
	}
};
int main(){
    Date  date(2020,10,1);
    int *pmem=reinterpret_cast<int*>(&date);
	cout << *pmem << endl;
	cout << *(pmem+1) << endl;
	cout << *(pmem+2) << endl;
}

