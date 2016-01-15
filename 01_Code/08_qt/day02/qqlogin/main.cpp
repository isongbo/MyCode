#include "qqlogin.h"
#include <QApplication>
int main(int argc,char** argv){
    QApplication  app(argc,argv);
    QqLogin  qq;
	qq.show();
	return  app.exec();
}

