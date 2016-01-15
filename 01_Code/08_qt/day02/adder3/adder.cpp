#include "adder.h"
Adder::Adder(){
    /* 创建界面 */
	ui=new Ui_Dialog();
	ui->setupUi(this);
	/* 访问界面中的组件 使用ui即可 */
	connect(ui->equ,SIGNAL(clicked()),
		this,SLOT(getRes()));
}
Adder::~Adder(){
    delete ui;
}
void  Adder::getRes(){
    ui->res->setText(QString::number(
		ui->add->text().toDouble()+
		ui->added->text().toDouble()));
}

