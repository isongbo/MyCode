#include <iostream>
using namespace std;
void   printArr(int* data,
	int len=1,char sep=','){
    for(int i=0;i<len-1;i++){
	    cout << data[i] << sep;
	}
	cout << data[len-1] << endl;
}

int main(){
    int   data[5]={9,5,2,7,12};
	printArr(data);
	printArr(data,2);
    printArr(data,3,' ');
	printArr(data,5,'$');
}

