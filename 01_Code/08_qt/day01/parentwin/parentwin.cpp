#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QObject>
#include <QWidget>
int main(int argc,char** argv){
    QApplication  app(argc,argv);
	/* 创建一个父窗口 */
	QWidget  *parent=new QWidget();
	parent->resize(300,500);
    QPushButton  *qpush=
		new QPushButton("closelab",parent);
	qpush->move(100,400);
	QLabel   qlab("hello qt",parent);
    // qpush->show();
	// qlab.show();
	/* 点击按钮 关闭标签 */
	QObject::connect(qpush,SIGNAL(clicked()),
		&qlab,SLOT(close()));
	parent->show();
	return  app.exec();
}

