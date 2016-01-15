#ifndef QQLOGIN_H
#define QQLOGIN_H
#include "qq.h"
#include <QDialog>
class  QqLogin:public QDialog{
	Q_OBJECT
    private:
	Ui_Dialog *ui;
	public:
	QqLogin();
	~QqLogin();
    /* 完成登录和取消的槽函数 */
	public slots:
	void  loginAndCancel();	
};
#endif

