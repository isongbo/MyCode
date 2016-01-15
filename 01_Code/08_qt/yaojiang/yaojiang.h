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
 /* 绘制事件处理函数 */
public:
    void paintEvent(QPaintEvent *e);
    //void mousePressEvent(QMouseEvent *e);
    //void  keyPressEvent(QKeyEvent *e);
    void   mouseMoveEvent(QMouseEvent *e);
private:
    Ui::YaoJiang *ui;
/* 要绘制的图片 */
    QImage    img;
/* 记录图片编号的随机数 */
    int       ind;
/* 参与摇奖的人 */
    QString   names[5];
/* 定时器 控制图片的切换 */
    QTimer    *timer;
/* 控制绘制的标志位 */
    bool     paintFlag;
/* 控制绘制标志的槽函数 */
public slots:
    void   changePaintFlag();
    void   changeName();
};

#endif // YAOJIANG_H
