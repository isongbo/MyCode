#ifndef TESTEVENT_H
#define TESTEVENT_H
#include <QMouseEvent>
#include <QDialog>
#include <QKeyEvent>
namespace Ui {
class TestEvent;
}

class TestEvent : public QDialog
{
    Q_OBJECT
    
public:
    explicit TestEvent(QWidget *parent = 0);
    ~TestEvent();
    
private:
    Ui::TestEvent *ui;
/* 鼠标事件处理函数 */
public:
void mousePressEvent(QMouseEvent *e);
/* 键盘事件处理函数 */
void keyPressEvent(QKeyEvent *e);
};

#endif // TESTEVENT_H



