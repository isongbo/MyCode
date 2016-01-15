#include <QApplication>
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
int main(int argc,char** argv){
	QApplication  app(argc,argv);
    QDialog  *parent=new QDialog();
	parent->resize(650,200);
/* 定义父窗口中的组件指针 */
QLineEdit  *add;
QLabel     *oper;
QLineEdit  *added;
QPushButton *equ;
QLineEdit  *res;
	/* 赋值 */
add=new QLineEdit(parent);
oper=new QLabel("+",parent);
added=new QLineEdit(parent);
equ=new QPushButton("=",parent);
res=new QLineEdit(parent);
/* 调整组件的位置 */
add->move(20,80);
oper->move(170,80);
added->move(220,80);
equ->move(370,80);
res->move(480,80);
	parent->show();
    return  app.exec();
}

