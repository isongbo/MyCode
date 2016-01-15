#include "qqlogin.h"
QqLogin::QqLogin():ui(new Ui_Dialog()){
    ui->setupUi(this);
	connect(ui->blogin,SIGNAL(clicked()),
		this,SLOT(loginAndCancel()));
	connect(ui->bcancel,SIGNAL(clicked()),
		this,SLOT(loginAndCancel()));
}
QqLogin::~QqLogin(){
    delete ui;
}
void QqLogin::loginAndCancel(){
    /* 判断是哪个组件发送的信号 */
    if(sender()==ui->blogin){
        if(ui->username->text()=="abc"
		  && ui->userpasswd->text()=="123"){
		  qDebug("login success!");  
		}else{
		  qDebug("login failed!"); 
		}	
	}
	if(sender()==ui->bcancel){
	    this->close();
	}
}

