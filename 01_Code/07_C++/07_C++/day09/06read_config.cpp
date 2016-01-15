#include <iostream>
#include <fstream>
using namespace std;
int main(){
	string  fname("config.txt");
    ifstream  ifs(fname.c_str());
	if(!ifs){
	    cout << "open file failed" << endl;
		return -1;
	}
    char   ip[20];
	short  port;
    int    ccount;
    double    pct;
	char   temp[30];
	ifs.getline(temp,30,'=');
    ifs.getline(ip,20);
	cout << ip << endl;
	ifs.getline(temp,30,'=');
	ifs >> port;
    cout << port << endl;  
	ifs.getline(temp,30,'=');
	ifs >> ccount;
    cout << ccount << endl;
	ifs.getline(temp,30,'=');
	ifs >> pct;
	cout << pct  << endl;
	ifs.close(); 
}



