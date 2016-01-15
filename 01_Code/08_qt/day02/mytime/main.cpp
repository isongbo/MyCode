#include "mytime.h"
#include <QApplication>
int main(int argc,char** argv){
    QApplication  app(argc,argv);
    MyTime mt;
	mt.show();
	return  app.exec();
}

