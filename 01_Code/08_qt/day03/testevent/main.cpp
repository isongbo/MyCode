#include <QtGui/QApplication>
#include "testevent.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestEvent w;
    w.show();
    
    return a.exec();
}
