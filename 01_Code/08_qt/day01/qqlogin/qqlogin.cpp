#include <QApplication>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
int main(int argc,char** argv){
    QApplication  app(argc,argv);
    /* 定义父窗口 并调整大小 显示 */
	QDialog  *parent=new QDialog();
    parent->resize(400,300);
	/* 定义父窗口中的组件指针 */
    QLineEdit  *username;
	QLineEdit  *userpasswd;
	QPushButton *blogin;
	QPushButton *bcancel;
    /* 赋值 */
    username=new QLineEdit(parent);
	userpasswd=new QLineEdit(parent);
    blogin=new QPushButton("login",parent);
	bcancel=new QPushButton("cancel",parent);
    /* 调整组件的位置 */
    username->move(200,50);
	userpasswd->move(200,100);
	blogin->move(50,200);
	bcancel->move(250,200);
	parent->show();
	/* 点击cancel按钮 关闭父窗口 */
    QObject::connect(bcancel,
	  SIGNAL(clicked()),parent,SLOT(close()));
	return  app.exec();
}


