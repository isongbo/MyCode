#include "snakegame.h"
#include <QTime>
#include <QMessageBox>
SnakeGame::SnakeGame(){
    this->resize(760,640);
    qsrand(QTime::currentTime().msec());
    footLen=40;
    snake.push_back(getFood());
    //snake[0]=getFood();
    food=getFood();
    dire=D_RIGHT;
    maxLen=3;
    /*启动定时器事件*/
    //this->startTimer(200);
    timer=new QTimer();
    /*每隔0.2秒发出timeout()信号*/
    timer->setInterval(200);
    timer->start();
    connect(timer,SIGNAL(timeout()),
            this,SLOT(snakeMove()));
}
SnakeGame::~SnakeGame(){

}
/*提供功能性函数*/
/*控制蛇移动  根据方向向前走一个步长*/
void   SnakeGame::snakeMove(){
    /*蛇头原来的位置*/
    int  x=snake[0]->x();
    int  y=snake[0]->y();
    /*思考如何吃掉食物 蛇头和食物坐标重合*/
    if(food->x()==x && food->y()==y){
        snake.push_back(food);
        food=getFood();
    }
    /*加逻辑判断*/
    if(snake.size()>=maxLen){
         QMessageBox  msg(this);
         msg.setText("snake maxlen game over?");
         msg.setStandardButtons
              (QMessageBox::Yes|QMessageBox::No);
         if(msg.exec()==QMessageBox::Yes){
              this->close();
         }else{
              maxLen=maxLen*2+1;
         }
    }
    if(x<0||y<0||x>=this->width()||y>=this->height()){
        QMessageBox  msg(this);
        msg.setText("game over?");
        msg.exec();
        this->close();
    }
    /*后面的跟着前面的走*/
    int  count=snake.size();
    for(int i=count-1;i>0;i--){
        snake[i]->move(snake[i-1]->x(),
                       snake[i-1]->y());
    }
    switch(dire){
        case  D_UP: y=y-footLen;break;
        case  D_DOWN:y=y+footLen; break;
        case D_LEFT:x=x-footLen;break;
        case D_RIGHT:x=x+footLen;break;
    }
    /*让蛇头走到新坐标*/
    snake[0]->move(x,y);
}
/*定时调用移动函数 使用定时器事件处理函数*/
void   SnakeGame::timerEvent(QTimerEvent *e){
    snakeMove();
}
/*控制方向 使用键盘事件处理函数*/
#include<QKeyEvent>
void    SnakeGame::keyPressEvent
(QKeyEvent *e){
    switch(e->key()){
        case  Qt::Key_Up:
        dire=D_UP;
        break;
        case Qt::Key_Down:
        dire=D_DOWN;
        break;
        case  Qt::Key_Left:
        dire=D_LEFT;
        break;
        case Qt::Key_Right:
        dire=D_RIGHT;
        break;
    }
}
/*得到食物的函数*/
QLabel* SnakeGame::getFood(){
    food=new QLabel(this);
    food->resize(footLen,footLen);
    food->setAutoFillBackground(true);
    /*设置调色板*/
    food->setPalette(QPalette(
         QColor(qrand()%256,qrand()%256,
                qrand()%256)));
    int  w=this->width()-footLen;
    int  h=this->height()-footLen;
    /*随机  界面范围内
    footLen的整数倍*/
    food->move(
    ((qrand()%w)/footLen)*footLen,
    ((qrand()%h)/footLen)*footLen);
    food->show();
    return  food;
}


