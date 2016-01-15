#include "adder.h"	
Adder::Adder(){
    this->resize(650,200);
		/* 赋值 */
	add=new QLineEdit(this);
	oper=new QLabel("+",this);
	added=new QLineEdit(this);
	equ=new QPushButton("=",this);
	res=new QLineEdit(this);
	/* 调整组件的位置 */
	add->move(20,80);
	oper->move(170,80);
	added->move(220,80);
	equ->move(370,80);
	res->move(480,80);
	/* 连接equ 到this */
	connect(equ,SIGNAL(clicked()),
		this,SLOT(getRes()));
}
    /* 完成计算的槽函数 */
void  Adder::getRes(){
    QString  sadd=add->text();
	QString  sadded=added->text();
	double   dadd=sadd.toDouble();
	double   dadded=sadded.toDouble();
	res->setText(
		QString::number(dadd+dadded));
}


