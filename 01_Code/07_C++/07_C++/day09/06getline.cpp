#include <iostream>
using namespace std;
int main(){
    char  data[20];
	cin.getline(data,10);
	cout << data << endl;
	/* data 无$ 但已经读走了$ */
	cin.getline(data,10,'$');
	cout << data << endl;
}

