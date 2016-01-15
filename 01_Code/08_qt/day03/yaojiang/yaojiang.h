#ifndef YAOJIANG_H
#define YAOJIANG_H

#include <QDialog>
#include <QImage>
#include <QTimer>
namespace Ui {
class YaoJiang;
}

class YaoJiang : public QDialog
{
    Q_OBJECT
    
public:
    explicit YaoJiang(QWidget *parent = 0);
    ~YaoJiang();
    
private:
    Ui::YaoJiang *ui;
    /* 要绘制的图片 */
    QImage  img;
    /* 随机的图片下标 */
    int   ind;
    /* 控制图片变化的定时器 */
    QTimer  *timer;
    /* 参与摇奖的人名 */
    QString  names[5];
    /* 控制重画的标志位 */
    bool  paintFlag;
/* 改变绘制标志的槽函数 */
public slots:
    void  changePaintFlag();
/* 实现更换名字的逻辑 */
public slots:
    void  changeName();
/* 绘制事件处理函数 */
public:
    void  paintEvent(QPaintEvent *e);
};

#endif // YAOJIANG_H



