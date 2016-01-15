#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;
struct  MyTime{
    /* 特征: */
	int   hour;
	int   min;
	int   sec;
	/* 行为 */
	void  show(){
	    cout << setfill('0') << setw(2) << 
			hour << ":" << setw(2) << min << 
			":" << setw(2) << sec << '\r' <<
			flush;
	}
    void  dida(){
	    sleep(1);
		if(60==++sec){
		    sec=0;
			if(60==++min){
			    min=0;
				if(24==++hour){
				    hour=0;
				} 
			}
		}
	}
	void  run(){
	    while(1){
		    show();
			dida();
		}
	}
};
int main(){
    MyTime  mt;
	mt.hour=11;
	mt.min=30;
	mt.sec=6;
    mt.run();
}

