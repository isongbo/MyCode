#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct  Dog{
    char  name[20];
	int   age;
	Dog(string name="",int age=0){
	    strcpy(this->name,name.c_str());
		this->age=age;
	}
};
int main(){
    Dog   doga("wangcai",10);
    Dog   dogb("xiaoqiang",12);
    ofstream   ofs("dog.dat",
		ios::binary|ios::out);
    if(!ofs){
	    cout << "open file failed" << endl;
	} 
    ofs.write((const char*)&doga,sizeof doga);
	ofs.write((const char*)&dogb,sizeof dogb);
    ofs.close();
	ifstream   ifs("dog.dat");
    Dog  dogc;
    ifs.read((char*)&dogc,sizeof dogc);
	cout << dogc.name << ":" << dogc.age 
		<< endl;
    ifs.read((char*)&dogc,sizeof dogc);
	cout << dogc.name << ":" << dogc.age 
		<< endl;
	/* 实际读取到的字节数 */
	cout << "gcount=" << ifs.gcount() << endl;
	ifs.close();
}

