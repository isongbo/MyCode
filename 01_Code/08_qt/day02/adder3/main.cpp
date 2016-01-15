#include "adder.h"
#include <QApplication>
int main(int argc,char** argv){
    QApplication  app(argc,argv);
    Adder  adder;
	adder.show();
	return  app.exec();
}

