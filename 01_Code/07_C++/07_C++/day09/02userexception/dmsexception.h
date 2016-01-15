#ifndef  DMSEXCEPTION_H
#define  DMSEXCEPTION_H
#include <string>
using namespace std;
class  DmsException{
    string  msg;
	public:
	DmsException(string msg=""):msg(msg){
	}
	const char* what()const throw(){
	    return  msg.c_str();
	}
};
class  DmsNetWorkException
    :public DmsException{
    public:
	DmsNetWorkException(string msg="")
		:DmsException(msg){
	
	}	
};
class  DmsInitNetWorkException
    :public DmsNetWorkException{
    public:
	DmsInitNetWorkException(string msg="")
		:DmsNetWorkException(msg){
	}	
};
class  DmsSendDataException
    :public DmsNetWorkException{
    public:
	DmsSendDataException(string msg="")
		:DmsNetWorkException(msg){
	
	}	
};
#endif


