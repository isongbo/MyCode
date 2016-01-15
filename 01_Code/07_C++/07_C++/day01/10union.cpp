#include <iostream>
using namespace std;
int main(){
    union {
	    int  x;
		char data[4];
	};
	// x=0x31323334;
	x=0x41424344;
	/* 请写出char数组中对应的四个字符 
	   31 ---49  '0' 48  'a' 97 'A' 65 */
	for(int i=0;i<4;i++){
	    cout << data[i] << ' ';
	}
	cout << endl;
	int tx=100;
    // htonl
}

