#include "mytime.h"
MyTime::MyTime(){
    this->resize(300,400);
	showtime=new QLabel("current time",this);
	gettime=new QPushButton("gettime",this);
	showtime->move(100,50);
	gettime->move(100,300);
	connect(gettime,SIGNAL(clicked()),
		this,SLOT(setTime()));
	/* 绑定自定义信号 到 setText(QString) */
    connect(this,SIGNAL(mySig(QString)),
		showtime,SLOT(setText(QString))); 
}
#include <QTime>
void  MyTime::setTime(){
	QString  timestr=QTime::currentTime().
		toString("hh:mm:ss");
    // showtime->setText(timestr);
	/* 假设访问界面不方便  发射信号 */
    emit mySig(timestr);
}

