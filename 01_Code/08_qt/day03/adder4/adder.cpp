#include "adder.h"
#include "ui_adder.h"

Adder::Adder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adder)
{
    ui->setupUi(this);
    /* 访问界面中的组件使用ui即可 */
    connect(ui->equ,SIGNAL(clicked()),
        this,SLOT(getRes()));
}
void  Adder::getRes(){
    ui->res->setText(QString::number(
        ui->add->text().toDouble()+
        ui->added->text().toDouble()));
}

Adder::~Adder()
{
    delete ui;
}
