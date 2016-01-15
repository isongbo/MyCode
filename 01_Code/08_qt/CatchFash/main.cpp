#include <QtGui/QApplication>
#include "fishdlg.h"
#include<QTextCodec>
//#include<QSound>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    FishDlg w;
    w.show();

    return a.exec();
}
