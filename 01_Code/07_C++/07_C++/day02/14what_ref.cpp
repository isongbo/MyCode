#include <iostream>
using namespace std;
int main(){
    int  x=100;
	const int*px=&x;
	int  y=200;
	// *px=200;
	px=&y;
    int *const rx=&x;
	// rx=&y;
	*rx=200;
	int  data[5];
}

