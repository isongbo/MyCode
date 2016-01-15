#include "mytime.h"
MyTime::MyTime(){
    this->resize(300,400);
	showtime=new QLabel("current time",this);
	gettime=new QPushButton("gettime",this);
    timer=new QTimer(this);
	timer->setInterval(100);
	timer->start();
	showtime->move(100,50);
	gettime->move(100,300);
	connect(gettime,SIGNAL(clicked()),
		this,SLOT(setTime()));
	connect(timer,SIGNAL(timeout()),
		this,SLOT(setTime()));
}
#include <QTime>
void  MyTime::setTime(){
	QString  timestr=QTime::currentTime().
		toString("hh:mm:ss");
    showtime->setText(timestr);
    /* 获取showtime的当前位置 */
	int  x=showtime->x();
	int  y=showtime->y();
    y=y+10;
	if(y>=400){
	    y=0;
	}
	showtime->move(x,y);
}



