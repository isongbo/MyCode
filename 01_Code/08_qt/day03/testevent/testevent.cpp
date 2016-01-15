#include "testevent.h"
#include "ui_testevent.h"

TestEvent::TestEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestEvent)
{
    ui->setupUi(this);
    this->resize(600,400);
}

TestEvent::~TestEvent()
{
    delete ui;
}

void TestEvent::mousePressEvent
    (QMouseEvent *e){
    switch(e->button()){
        case Qt::LeftButton:
        qDebug("left button clicked %d:%d",
            e->x(),e->y());
        break;
        case Qt::MidButton:
        qDebug("mid button clicked");
        break;
        case Qt::RightButton:
        qDebug("right button clicked");
        break;
    }
}

void TestEvent::keyPressEvent
    (QKeyEvent *e){
    switch(e->key()){
        case Qt::Key_Up:
        qDebug("up key");
        break;
        case Qt::Key_Down:
        qDebug("down key");
        break;
        case Qt::Key_Left:
        qDebug("left key");
        break;
        case Qt::Key_Right:
        qDebug("right key");
         break;
    }
}




