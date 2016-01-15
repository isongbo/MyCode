#include <iostream>
using namespace std;
struct  Date{
    int  year;
	int  month;
	int  day;
	Date  operator++(){
	}
	Date  operator++(int){
	}
};
int  main(){
    Date  date;
	++date;
	date++;
}

