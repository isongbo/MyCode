#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
/* 真正对文件进行异或的逻辑 */
void file_xor(const char* src,const char* des
	,unsigned char key){
    ifstream  ifs(src);
	if(!ifs){
	    cout << "open file" << src << 
			"failed" << endl;
		return;
	}
	ofstream  ofs(des);
    if(!ofs){
	    cout << "open file" << des <<
			"failed" << endl;
		return;
	}
	char  data[100];
	while(ifs.read(data,sizeof data)){
	    // 读满data这个缓冲区
		for(int i=0;i<100;i++){
		    data[i]=data[i]^key;
		}
		ofs.write(data,sizeof data);
	}
	// 最后一次读取 
    int  gcount=ifs.gcount();
    for(int i=0;i<gcount;i++){
	    data[i]=data[i]^key;
	} 
	ofs.write(data,gcount);
    ifs.close();
	ofs.close();
}
/* 加密函数 */
void  encode(const char* src,const char* des){
    unsigned char key=rand()%256;
	cout << "key=" << (int)key << endl;
    file_xor(src,des,key); 
}
/* 解密函数 */
void  decode(const char* src,const char* des,
	unsigned char key){
    file_xor(src,des,key);
}
int main(int argc,char** argv){
    srand(time(NULL));
    if(argc<3 || argc>4 ){
	    cout << "使用错误 应如下:" << endl;
		cout << "加密文件:" << endl;
		cout << "./filexor 源文件名 目标文件名" << endl;
		cout << "解密文件:" << endl;
		cout << "./filexor 源文件名 目标文件名 密钥 "
			 << endl;
	}else if(argc==3){
	    cout << "加密文件" << endl;
		encode(argv[1],argv[2]);
	}else if(argc==4){
	    cout << "解密文件" << endl;
		decode(argv[1],argv[2],atoi(argv[3]));
	}
}

