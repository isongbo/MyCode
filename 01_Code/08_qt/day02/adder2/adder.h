#ifndef ADDER_H
#define ADDER_H
#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
class  Adder:public QDialog{
	Q_OBJECT
	private:
	/* 定义父窗口中的组件指针 */
	    QLineEdit  *add;
		QLabel     *oper;
		QLineEdit  *added;
		QPushButton *equ;
		QLineEdit  *res;
    public:
		Adder();
    /* 完成计算的槽函数 */
    public slots:
		void  getRes();
};
#endif

