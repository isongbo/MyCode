#ifndef  MYTIME_H
#define  MYTIME_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
class  MyTime:public QDialog{
	Q_OBJECT
    private:
	QLabel  *showtime;
	QPushButton *gettime;
	public:
	MyTime();
	/* 完成赋值的槽函数 */
	public slots:
	void  setTime();	
};
#endif

