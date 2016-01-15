#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream  ifs("05getput_file.cpp");
	int  c;
	/*while((c=ifs.get())!=EOF){
	    cout.put(c); 
	}*/
	char cc;
	/* while(ifs.get(cc)){
	    cout.put(cc);  
	} */
	while(ifs >> cc){
	    cout.put(cc);
	}
	ifs.close();
}

