#include "fishdlg.h"
#include "ui_fishdlg.h"
#include<QMouseEvent>
#include<qmath.h>
#include<QMatrix>
#include<QPen>
#include<QFont>
FishDlg::FishDlg(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::FishDlg)
{
    money=0;
    //ball=99;
    qsrand(QTime::currentTime().msec());//随机种子

    f_stack=new list<Fash*>;

    b_stack=new list<Ball*>;
    mouse=false;

    time=new QTimer;
    time->setInterval(50);
    time->start();
    this->setFixedSize(800,480);

    ui->setupUi(this);
    newFash();
    newFash();
    initString();
    this->setMouseTracking(true);

    connect(time,SIGNAL(timeout()),this,SLOT(repaint()));
}
/*
*绘制图片的接口
*/
void FishDlg::paintEvent(QPaintEvent *e){
    static int i=0;
    i=(++i)%20;
    if(i==0){
        newFash();
        newFash();
        newFash();
    }
    QPainter painter(this);
    QPixmap pix;
    pix.load(":images/bg.png");
    painter.drawPixmap(0,0,pix.width(),pix.height(),pix);
    paintFash(painter);
    paintWeapon(painter);
    paintBall(painter);
    paintMoney(painter);
}
FishDlg::~FishDlg()
{
    delete ui;
}
/*
**产生鱼,首先根据随机数确定新产生的鱼的种类，再根据种类确定鱼的各种属性 bottomFish，
**leftFish，topFish，rightFish是确定鱼产生出来后的初始位置
*/
void FishDlg::newFash(){

    int f_dec=qrand()%65;
    int foot=0,type=0;
    if(f_dec<15) type=0;
    else if(f_dec<25) type=1;
    else if(f_dec<35) type=2;
    else if(f_dec<40) type=3;
    else if(f_dec<45) type=4;
    else if(f_dec<50) type=5;
    else if(f_dec<55) type=6;
    else if(f_dec<56) type=7;
    else if(f_dec<60) type=8;
    else if(f_dec<62) type=9;
    else type=10;

    if(type<4) foot=3;
    else if(type<7)foot=4;
    else if(type==7)foot=1;
    else foot=5;

    float angle=qrand()%360;
    if(angle<45||angle>315) bottomFish(type,foot,angle);
    else if(angle<135) leftFish(type,foot,angle);
    else if(angle <225) topFish(type,foot,angle);
    else rightFish(type,foot,angle);
}
/*
**初始化字符串用于拼接鱼的图片，表示鱼的各个动作
*/
void FishDlg::initString(){
    f_str[0]="fish01";
    f_str[1]="fish02";
    f_str[2]="fish03";
    f_str[3]="fish04";
    f_str[4]="fish05";
    f_str[5]="fish06";
    f_str[6]="fish07";
    f_str[7]="fish08";
    f_str[8]="fish09";
    f_str[9]="fish10";
    f_str[10]="fish11";
}
/*
**鼠标事件处理
*/
void FishDlg::mousePressEvent(QMouseEvent *e){
    QPoint point =e->pos();
    double r=0;
    if(point.x()>441)
        r=atan((479.0-point.y())/(point.x()-441.0))*180/3.1415926;
    else if(point.x()<441)
        r=180-atan((479.0-point.y())/(441.0-point.x()))*180/3.1415926;
    else
        r=90;
    Ball* b=new Ball(0,433,389,r);//441,479  (429,399)
    b_stack->push_back(b);
}
void FishDlg::mouseMoveEvent(QMouseEvent *e){
    mpoint=e->pos();
#ifdef DEBUG
    qDebug()<<QString::number(mpoint.x())+","+QString::number(mpoint.y());
#endif
}
void FishDlg::mouseReleaseEvent(QMouseEvent*){
    mouse=false;
}
/*
**用于计算钱
*/
void FishDlg::addMoney(Fash* f)
{
    int x=f->f_type;
    switch(x){
    case 0:money+=1;
        break;
    case 1: money+=2;
        break;
    case 2:
        money+=3;
        break;
    case 3:
        money+=4;
        break;
    case 4:
        money+=5;
        break;
    case 5:
        money+=6;
        break;
    case 6:
        money+=7;
        break;
    case 7:
        money+=8;
        break;
    case 8:
        money+=9;
        break;
    case 9:
        money+=10;
        break;
    case 10:
        money+=11;
        break;
    }

}
void FishDlg::paintFash(QPainter& painter){
    QPixmap fash;
    QString str;
    for(list<Fash*>::iterator it=f_stack->begin();it!=f_stack->end();it++){
        //将游出边框的鱼从鱼链表中去除
        if(((*it)->f_x)<-300||((*it)->f_x)>1100||((*it)->f_y)<-300||((*it)->f_y)>880){
            Fash *p=*it;
            it--;
            f_stack->remove(p);

            delete (p);continue;
        }
        //绘制被捕捉后的鱼
        if((*it)->f_catched==true){
            painter.save();
            painter.translate((*it)->f_x,(*it)->f_y);
            painter.rotate((*it)->f_angle+90);
            str=":images/"+(QString)f_str[(*it)->f_type]+"_catch_0"+QString::number((*it)->f_images)+".png";
            fash.load(str);
            painter.drawPixmap(-fash.width()/2,-fash.height()/2,fash.width(),fash.height(),fash);

            painter.restore();
            //绘制加金币的效果
            QColor color(255,255,0);
            QString str=QString("+")+QString::number((*it)->f_type+1);
            paintString(painter,color,(*it)->f_x-(*it)->f_text*2,(*it)->f_y-(*it)->f_text*2,10+(*it)->f_text*5,str);
            (*it)->f_text+=1;
            //鱼被捕捉后前8中鱼的捕捉图片和后3种数目不同
            if((*it)->f_type<8)
                (*it)->f_images=(++(*it)->f_images)%2;
            else
                (*it)->f_images=(++(*it)->f_images)%4;
            (*it)->f_flag=(++(*it)->f_flag)%9;
            if((*it)->f_flag==8){

                addMoney(*it);

                Fash *p=*it;
                it--;
                f_stack->remove(p);
                delete (p);
            }

        }
        //绘制没有被捕捉的鱼
        else{
            painter.save();
            painter.translate((*it)->f_x,(*it)->f_y);
            painter.rotate((*it)->f_angle+90);
            str=":images/"+(QString)f_str[(*it)->f_type]+"_0"+QString::number((*it)->f_images)+".png";
            fash.load(str);

            painter.drawPixmap(-fash.width()/2,-fash.height()/2,fash.width(),fash.height(),fash);
            painter.restore();
            //如果这个“鱼”是乌龟，那么降低乌龟的游动频率
            if((*it)->f_type==7){
                static int i=0;
                if(i==0){
                    (*it)->move();
                    (*it)->f_images=(++(*it)->f_images)%10;
                }
                i=++i%2;
            }else{
                (*it)->move();
                (*it)->f_images=(++(*it)->f_images)%10;
            }
        }
#ifdef DEBUG
        qDebug()<<QString::number(r);
#endif
    }
}
/*
**绘制武器
*/
void FishDlg::paintWeapon(QPainter& painter){

    painter.save();
    QPixmap pix;
    pix.load(":images/bg2.png");
    painter.drawPixmap(20,410,pix.width(),pix.height(),pix);
    QPixmap pix2;
    pix2.load(":images/level.png");
    painter.translate(441,479);
    double r;
    //计算炮台旋转的角度
    if(mpoint.x()>441){
        r=atan((double)(479-mpoint.y())/(double)(mpoint.x()-441))*180/3.1415926;
    }
    else
        r=180-atan((double)(479.0-mpoint.y())/(double)(441-mpoint.x()))*180/3.1415926;
    painter.rotate(90-r);
    painter.drawPixmap(-21,-59,pix2.width(),pix2.height(),pix2);//387,400  387-x=441 -54
    painter.restore();
}
/*
**绘制子弹/渔网，子弹在碰撞到鱼后换成渔网
*/
void FishDlg::paintBall(QPainter& painter){
    QPixmap bullet;
    QPoint tPoint;//用于存放子弹相对于炮台的相对位置

    for(list<Ball*>::iterator it=b_stack->begin();it!=b_stack->end();it++ ){
        tPoint=QPoint(441+(479-(*it)->b_y)*cos((*it)->b_angle/180.0*3.1415926),
                      479-(479-(*it)->b_y)*sin((*it)->b_angle/180.0*3.1415926));
       //去除越界的子弹
        if(tPoint.y()<0||tPoint.x()<0||tPoint.x()>800){
            Ball *p=*it;
            it--;
            b_stack->remove(p);
            delete (p);
            continue;
        }
        //更改被击中鱼的的状态，和子弹的状态，将子弹变成渔网，鱼的状态变成被捕捉状态
        for(list<Fash*>::iterator fit=f_stack->begin();fit!=f_stack->end();fit++){

            if((*fit)->f_x<tPoint.x()+20&&(*fit)->f_x>tPoint.x()-20&&
               (*fit)->f_y<tPoint.y()+20&&(*fit)->f_y>tPoint.y()-20){
                (*it)->b_type=1;
                if((*fit)->f_catched!=true){
                    (*fit)->f_catched=true;
                    (*fit)->f_images=0;
                }
            }
        }
        if((*it)->b_type)
            bullet.load(":images/web.png");
        else
            bullet.load(":images/bullet.png");
        painter.save();
        painter.translate(441,479);
        painter.rotate(90-(*it)->b_angle);
/*
**渔网和鱼的绘制点不同，所以采用了两个绘制表达式
*/
        if((*it)->b_type)
            painter.drawPixmap((*it)->b_x-441-60,(*it)->b_y-479-60,bullet.width(),bullet.height(),bullet);
        else
            painter.drawPixmap((*it)->b_x-441-5,(*it)->b_y-479,bullet.width(),bullet.height(),bullet);
        painter.restore();
//子弹变成渔网后绘制4次，第5次在子弹链表中删除
        if((*it)->b_type){
            if((*it)->b_flag==4){
                Ball *p=*it;
                it--;
                b_stack->remove(p);
                delete (p);
                return;
            }
            (*it)->b_flag=(++(*it)->b_flag)%5;
        }else{
            (*it)->move();
        }
    }
}
/*
**绘制钱（得分框）
*/
void FishDlg::paintMoney(QPainter& painter){
    painter.save();
    QPen pen(QColor(255,0,0));
    painter.setPen(pen);
    QFont font("隶书",10,QFont::Bold);
    painter.setFont(font);
    //将money各位分解并绘制到对应的方框中
    painter.drawText(QRect(48,458,70,480),QString::number(money/100000>0?money/100000:0));
    painter.drawText(QRect(72,458,95,480),QString::number((money%100000)/10000>0?(money%100000)/10000:0));
    painter.drawText(QRect(95,458,115,480),QString::number((money%10000)/1000>0?(money%10000)/1000:0));
    painter.drawText(QRect(115,458,135,480),QString::number((money%1000)/100>0?(money%1000)/100:0));
    painter.drawText(QRect(138,458,155,480),QString::number((money%100)/10>0?(money%100)/10:0));
    painter.drawText(QRect(163,458,185,480),QString::number((money%10)>0?(money%10):0));
    painter.restore();
}
/*
**绘制字符串（自定义格式的字符串）
*/
void FishDlg::paintString(QPainter& painter,QColor &color,int x,int y,int fontSize,QString &str){
    painter.save();
    QPen pen(color);
    painter.setPen(pen);
    QFont font("Times",fontSize,QFont::Bold);
    painter.setFont(font);
    painter.drawText(QRect(x,y,x+50,y+50),str);
    painter.restore();
}
void FishDlg::keyPressEvent(QKeyEvent*e){
    switch(e->key()){
    case Qt::Key_S :
        break;
    }
}
/*
**产生上下左右四个方向的鱼
*/
void FishDlg::rightFish(int type,int foot,float angle){
    if(type<7){
        int y=qrand()%480;
        Fash *f;
        if(rand()%2){
            f=new Fash(800,y,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(800,y+50,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(800,y-50,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(800,y-100,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(800,y+100,type,angle,foot);
            f_stack->push_back(f);
        }
        else{
            f=new Fash(800,y+50,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(800,y-50,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(800,y,type,angle,foot);
            f_stack->push_back(f);
        }
    }else{
        Fash *f=new Fash(800,qrand()%480,type,angle,foot);
        f_stack->push_back(f);
    }
}
void FishDlg::leftFish(int type,int foot,float angle){
    if(type<7){
        int y=qrand()%480;
        Fash *f;
        if(rand()%2){
            f=new Fash(-400,y,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(-400,y+50,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(-400,y-50,type,angle,foot);
            f_stack->push_back(f);
        }else{
            f=new Fash(-400,y,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(-400,y+50,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(-400,y-50,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(-400,y+100,type,angle,foot);
            f_stack->push_back(f);
            f=new Fash(-400,y-100,type,angle,foot);
            f_stack->push_back(f);
        }
    }
    else{
        Fash *f=new Fash(-400,qrand()%480,type,angle,foot);
        f_stack->push_back(f);
    }
}
void FishDlg::topFish(int type,int foot,float angle){

    if(type<7){
        int x=qrand()%800-100;
        Fash *f;
        f=new Fash(x,-100,type,angle,foot);
        f_stack->push_back(f);
        f=new Fash(x+50,-100,type,angle,foot);
        f_stack->push_back(f);
        f=new Fash(x-50,-100,type,angle,foot);
        f_stack->push_back(f);
    }
    else{
        Fash *f=new Fash(qrand()%800,-100,type,angle,foot);
        f_stack->push_back(f);
    }
}
void FishDlg::bottomFish(int type,int foot,float angle){

    if(type<7){
        int x=qrand()%800-100;
        Fash *f;
        f=new Fash(x,500,type,angle,foot);
        f_stack->push_back(f);
        f=new Fash(x+50,500,type,angle,foot);
        f_stack->push_back(f);
        f=new Fash(x-50,500,type,angle,foot);
        f_stack->push_back(f);
    }
    else{
        Fash *f=new Fash(qrand()%800,500,type,angle,foot);
        f_stack->push_back(f);
    }

}
