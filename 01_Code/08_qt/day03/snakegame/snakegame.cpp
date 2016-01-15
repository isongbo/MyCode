#include "snakegame.h"
#include <QTime>
#include <QKeyEvent>
#include <QMessageBox>
SnakeGame::SnakeGame(){
    /* 随机种子 */
    qsrand(QTime::currentTime()
        .msec());
    this->resize(801,600);
    footLen=40;
    snake.push_back(getNewFood());
    food=getNewFood();
    dire=D_RIGHT;
    timer=new QTimer();
    timer->setInterval(200);
    timer->start();
    score=3;
    /* 让蛇动起来 */
    connect(timer,SIGNAL(timeout()),
        this,SLOT(snakeMove()));
}
/* 根据方向蛇移动的函数  */
void  SnakeGame::snakeMove(){
    /* 蛇头现在的坐标 */
    int sx=snake[0]->x();
    int sy=snake[0]->y();
    /* 撞墙 */
    if(sx < 0 || sy <0 ||
       sx>=this->width()-footLen||
       sy>=this->height()){
        QMessageBox  msg(this);
        msg.setText("game over!");
        msg.exec();
        this->close();
    }
    /* 过关的逻辑 */
    if(snake.size()>=score){
        QMessageBox msg(this);
        msg.setText("guo guan continue?");
        msg.setStandardButtons(
          QMessageBox::Yes|QMessageBox::No);
        if(msg.exec()==QMessageBox::Yes){
            score=score*2+1;
        }else{
            this->close();
        }
    }
    /* 蛇头和食物坐标重合 */
    if(sx==food->x()&& sy==food->y()){
        eatFood();
    }
    /* 让后面的元素移动到前一个元素位置*/
    for(int i=snake.size()-1;i>0;i--){
        snake[i]->move(snake[i-1]->x(),
             snake[i-1]->y());
    }
    /* 特效
    if(snake.size()==5){
        snake[4]->move(snake[3]->x(),
            snake[3]->y());
        snake[3]->move(snake[2]->x(),
            snake[2]->y());
        snake[2]->move(snake[1]->x(),
            snake[1]->y());
        snake[1]->move(snake[0]->x(),
            snake[0]->y());
    }*/
    switch(dire){
        case D_UP:
        sy=sy-footLen;
        break;
        case D_DOWN:
        sy=sy+footLen;
        break;
        case D_LEFT:
        sx=sx-footLen;
        break;
        case D_RIGHT:
        sx=sx+footLen;
        break;
    }
    /* 把蛇头移动到 新坐标 */
    snake[0]->move(sx,sy);
}
/* 控制方向的键盘事件处理函数 */
void  SnakeGame::keyPressEvent
    (QKeyEvent *e){
    switch(e->key()){
        case Qt::Key_Up:
        dire=D_UP;
        break;
        case Qt::Key_Down:
        dire=D_DOWN;
        break;
        case Qt::Key_Left:
        dire=D_LEFT;
        break;
        case Qt::Key_Right:
        dire=D_RIGHT;
        break;
    }
}
/* 吃食物 */
void  SnakeGame::eatFood(){
    snake.push_back(food);
    /* 继续产生新食物 */
    food=getNewFood();
}
/* 产生新食物的函数 */
QLabel* SnakeGame::getNewFood(){
    food=new QLabel(this);
    food->resize(footLen,footLen);
    food->setAutoFillBackground(true);
    food->setPalette(QPalette(
      QColor(qrand()%256,qrand()%256,
      qrand()%256)));
    /* 位置随机
       位置在界面范围内
       位置是footLen的整数倍 */
    int  w=this->width()-footLen;
    int  h=this->height()-footLen;
    food->move(
      (qrand()%w)/footLen*footLen,
      (qrand()%h)/footLen*footLen);
    food->show();
    return  food;
}


