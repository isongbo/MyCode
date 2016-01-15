#include <iostream>
using namespace std;
int main(){
    /* 申请5个整数对应的堆空间 */
	int *parr=new  int[5];
	/* 给这块堆空间赋值 9 5 2 7 8 */
    // parr[0]=9;
	// *parr=9;
	// *(parr+1)=5;
	/* *parr++=9;
	   *parr++=5; */
	int  *temp=parr;
    *temp++=9;
	*temp++=5;
	*temp++=2;
    *temp++=7;
	*temp++=8;
	/* 输出这块空间的值  */
    for(int i=0;i<5;i++){
	    cout << parr[i] << ' ';
	}
	cout << endl;
	/* 释放堆空间  */
	delete[]  parr;
    char  data[110];
    int   *parr2=new (data)int[25];
	cout << parr2 << endl;
	cout << &data  << endl;
}




