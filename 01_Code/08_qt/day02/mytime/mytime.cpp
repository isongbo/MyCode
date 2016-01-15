#include "mytime.h"
MyTime::MyTime(){
    this->resize(300,400);
	showtime=new QLabel("current time",this);
	gettime=new QPushButton("gettime",this);
	showtime->move(100,50);
	gettime->move(100,300);
	connect(gettime,SIGNAL(clicked()),
		this,SLOT(setTime()));
}
#include <QTime>
void  MyTime::setTime(){
	QString  timestr=QTime::currentTime().
		toString("hh:mm:ss");
    showtime->setText(timestr);
}

