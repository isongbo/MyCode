#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QObject>
int main(int argc,char** argv){
    QApplication  app(argc,argv);
    /* 分别构建标签 和 按钮对象 并显示 */
	QLabel  qlab("hello qt!");
	QPushButton qpush("closelab");
	qlab.show();
	qpush.show();
	/* 点击按钮 关闭标签 
    QObject::connect(&qpush,
		SIGNAL(clicked()),&qlab,
		SLOT(close())); */
    /* 点击按钮  关闭整个应用程序 */ 
    QObject::connect(&qpush,
		SIGNAL(clicked()),&app,
		SLOT(quit()));
	return   app.exec();
}

