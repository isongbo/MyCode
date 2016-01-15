#include <iostream>
using namespace std;
/*
void  printArr(int(&data)[5]){
    // cout << sizeof data << endl;
	for(int i=0;i<sizeof data/sizeof data[0]
		;i++){
	    cout << data[i] << ' '; 
	}
	cout << endl;
}*/
template <typename T>
void  printArr(T&  data){
    for(int i=0;i<sizeof data/sizeof data[0];
		i++){
	    cout << data[i] << ' '; 
	}
	cout << endl;
}
int main(){
    int data[5]={9,5,2,7,8};
    cout << sizeof data << endl;
	printArr(data);
	int data2[3]={3,7,2};
    printArr(data2);
}

