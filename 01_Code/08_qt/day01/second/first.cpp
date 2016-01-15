#include <QApplication>
#include <QLabel>
#include <QTextCodec>
int main(int argc,char** argv){
    /* 构建qt应用程序对象 */
	QApplication  app(argc,argv);
	QTextCodec *coder=
		QTextCodec::codecForName("utf-8");
    /* 创建一个标签对象 */
	QLabel  qlab(
		coder->toUnicode("你好 qt!"));
	qlab.show();
	/* 让程序进入事件循环 */
	return  app.exec();
}

