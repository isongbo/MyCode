#ifndef  ADDER_H
#define  ADDER_H
#include "jfq.h"
#include <QDialog>
class  Adder:public QDialog{
    Q_OBJECT
    private:
	/* 指向界面的指针 */
	Ui_Dialog   *ui;
	public:
	Adder();
	~Adder();
	/* 完成计算的槽函数 */
	public slots:
	void  getRes();	
};
#endif

