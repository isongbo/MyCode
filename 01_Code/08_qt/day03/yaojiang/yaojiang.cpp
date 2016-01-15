#include "yaojiang.h"
#include "ui_yaojiang.h"
#include <QPainter>
#include <QTime>
YaoJiang::YaoJiang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YaoJiang)
{
    /* 种随机种子 */
    qsrand(QTime::currentTime()
           .msec());
    ui->setupUi(this);
    paintFlag=false;
    ind=-1;
    names[0]="beibei";
    names[1]="xiaoli";
    names[2]="xiaoxue";
    names[3]="feifei";
    names[4]="chengcheng";
    timer=new QTimer();
    timer->setInterval(200);
    timer->start();
    connect(timer,SIGNAL(timeout()),
        this,SLOT(repaint()));
    connect(timer,SIGNAL(timeout()),
        this,SLOT(changeName()));
    connect(ui->bstart,SIGNAL(clicked()),
        this,SLOT(changePaintFlag()));
    connect(ui->bstop,SIGNAL(clicked()),
        this,SLOT(changePaintFlag()));
}
/* 实现换名字 */
void  YaoJiang::changeName(){
    if(ind!=-1){
    ui->pname->setText(names[ind-1]);
    }
}
void  YaoJiang::changePaintFlag(){
    if(sender()==ui->bstart){
        paintFlag=true;
    }
    if(sender()==ui->bstop){
        paintFlag=false;
    }
}
YaoJiang::~YaoJiang()
{
    delete ui;
}

void  YaoJiang::paintEvent(
        QPaintEvent *e){
    QPainter   qp(this);
    // qp.drawLine(0,0,400,600);
    if(paintFlag){
    ind=(qrand()%5)+1;
    QString imgpath=":/img/";
    imgpath=imgpath
            +QString::number(ind);
    imgpath+=".jpg";
    img.load(imgpath);
    img=img.scaled(320,480);
    // qp.drawImage(40,40,img);
    }
    /* 把内存中的图片画一次 */
    qp.drawImage(40,40,img,0,0,
          160,240);
    qp.drawImage(200,280,img,
          160,240,160,240);
}



