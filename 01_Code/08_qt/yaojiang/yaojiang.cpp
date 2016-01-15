#include "yaojiang.h"
#include "ui_yaojiang.h"
#include <QTime>
YaoJiang::YaoJiang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::YaoJiang)
{
    /* 随机种子 */
    qsrand(QTime::currentTime().msec());
    ind=-1;
    ui->setupUi(this);
    names[0]="lili";
    names[1]="beibei";
    names[2]="xiaoxue";
    names[3]="qiqi";
    names[4]="feifei";
    timer=new QTimer(this);
    timer->setInterval(200);
    timer->start();
    paintFlag=false;
    /* 使用定时器控制 重画 */
    connect(timer,SIGNAL(timeout()),
            this,SLOT(repaint()));
    connect(timer,SIGNAL(timeout()),
            this,SLOT(changeName()));
    /* 绑定两个按钮到槽函数  */
    connect(ui->bstart,SIGNAL(clicked()),
         this,SLOT(changePaintFlag()));
    connect(ui->bstop,SIGNAL(clicked()),
         this,SLOT(changePaintFlag()));
}
void   YaoJiang::mouseMoveEvent(QMouseEvent *e){
     return;
}
YaoJiang::~YaoJiang()
{
    delete ui;
}
#include <QPainter>
void YaoJiang::paintEvent(QPaintEvent *e){
    QPainter   qp(this);
    if(paintFlag){
    ind=(qrand()%5)+1;
    QString   imgpath=":/img/";
    imgpath=imgpath+QString::number(ind);
    imgpath+=".jpg";
    /* 绘制图片 */
    img.load(imgpath);
    /* 缩放图片 */
    img=img.scaled(320,480);

    //qp.drawImage(40,40,img,0,0,160,240);
    //qp.drawImage(200,280,img,160,240,160,240);
    qp.drawImage(40,40,img);
    //ui->pname->setText(names[ind-1]);
    }
    /* 把内存中的图片 重新绘制一次 */
    qp.drawImage(40,40,img);
}
 void   YaoJiang::changePaintFlag(){
     if(sender()==ui->bstart){
          paintFlag=true;
     }
     if(sender()==ui->bstop){
          paintFlag=false;
     }
 }

void  YaoJiang::changeName(){
    if(ind!=-1)
    ui->pname->setText(names[ind-1]);
}




