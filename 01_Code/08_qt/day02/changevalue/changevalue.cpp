#include <QApplication>
#include <QWidget>
#include <QSlider>
#include <QSpinBox>
int main(int argc,char** argv){
    QApplication  app(argc,argv);
    QWidget  *parent=new QWidget();
	parent->resize(500,400);
    /* 父窗口中的组件指针 */
	QSlider  *qsli;
	QSpinBox  *qspin;
    /* 赋值 */
	qsli=new QSlider(parent);
	qspin=new QSpinBox(parent);
    /* 调整组件的大小和 位置 */
	qsli->resize(20,200);
	qsli->move(50,100);
	qspin->move(300,200);
	qspin->setValue(5);
	parent->show();
	/* qsli 去影响 qspin  */
    QObject::connect(qsli,
		SIGNAL(valueChanged(int)),
		qspin,SLOT(setValue(int))); 
	/* qspin 去影响 qsli */
    QObject::connect(qspin,
		SIGNAL(valueChanged(int)),
		qsli,SLOT(setValue(int))); 
	return  app.exec();
}

