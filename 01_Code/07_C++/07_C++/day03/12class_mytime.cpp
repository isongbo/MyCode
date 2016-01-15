#include <iostream>
#include <iomanip>
using namespace std;
class MyTime{
    int  hour;
	int  min;
	int  sec;
	public:
	MyTime(int hour=0,int min=0,int sec=0)
		:hour(hour),min(min),sec(sec){
	
	}
    void  setTime(int h=12,int m=0,int s=0){
	    hour=h;
		min=m;
		sec=s;
	}
	void  show(){
	    cout << setfill('0') << setw(2) 
			<< hour << ':' << setw(2) 
			<< min << ':' << setw(2) 
			<< sec << endl; 
	}
};
int main(){
    MyTime  mt;
	mt.show();
    mt.setTime();
	mt.show();
}




