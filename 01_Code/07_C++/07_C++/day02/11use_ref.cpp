#include <iostream>
using namespace std;
/* void  myswap(int x,int y){
	int  temp=x;
	x=y;
	y=temp;
    cout << x << ":" << y << endl; 
} */
/*
void  myswap(int* x,int* y){
    int  temp=*x;
	*x=*y;
	*y=temp;
    cout << *x << ":" << *y << endl; 
}*/
void  myswap(int& x,int& y){
    int temp=x;
	x=y;
	y=temp;
    cout << x << ":" << y << endl;
}
int main(){
    int  x=10;
	int  y=20;
	int  temp=x;
	x=y;
	y=temp;
	cout << x << ":" << y << endl;
	myswap(x,y);
	cout << x << ":" << y << endl;
}

