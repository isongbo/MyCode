#include <iostream>
using namespace std;
int main(){
    char  data[5];
	cout << "cin=" << cin << endl;
	cin.getline(data,5);
	cout << data << endl;
	if(!cin){
	// 复位 
	cin.clear();
	/* 清理缓冲区 */
	cin.ignore(200,'\n');
	cout << "cin=" << cin << endl;
	}
    int   x=0;
	cin >> x;
	cout << x << endl;
}

