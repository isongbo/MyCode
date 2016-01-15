#include <iostream>
using namespace std;
//extern "C" int getmax(int x,int y);
extern "C" {
	int getmax(int x,int y);
}	
int main(){
    getmax(1,2);
}

