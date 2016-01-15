#include <iostream>
#include <fstream>
using namespace std;
int main(int argc,char** argv){

    if(argc<3 || argc>4 ){
	    cout << "使用错误 应如下:" << endl;
		cout << "加密文件:" << endl;
		cout << "./filexor 源文件名 目标文件名" << endl;
		cout << "解密文件:" << endl;
		cout << "./filexor 源文件名 目标文件名 密钥 "
			 << endl;
	}else if(argc==3){
	    cout << "加密文件" << endl;
	}else if(argc==4){
	    cout << "解密文件" << endl;
	}
}

