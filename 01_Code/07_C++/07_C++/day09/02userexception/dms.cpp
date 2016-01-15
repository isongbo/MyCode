#include "dmsexception.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void  initNetWork()
	throw(DmsInitNetWorkException){
    int  r=rand()%2;
	if(0==r){
	    cout << "初始化网络成功" << endl;
	}else{
	    throw DmsInitNetWorkException
			("connect sever failed"); 
	}
}
void  sendData()throw(DmsSendDataException){
	try{
    initNetWork();
	}catch(DmsInitNetWorkException& e){
	// throw e;
	// throw 新异常;
	cout << "连接备用服务器" << endl;
	}
	int  r=rand()%2;
    if(0==r){
	    cout << "发送数据正常" << endl;
	}else{
	    throw DmsSendDataException
			("发送数据失败");
	}
}
int main(){
    srand(time(NULL));
	try{
    sendData();
	}catch(DmsSendDataException& e){
	cout << e.what() << endl;
	}
}



