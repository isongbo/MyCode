#ifndef FISHDLG_H
#define FISHDLG_H
#include<QPainter>
#include<QDebug>
#include"Fash.h"
#include <QDialog>
#include<QTimer>
#include<QTime>
#include<list>
#include<QList>
#include<QPoint>
#include<QSound>
using namespace std;
namespace Ui {
    class FishDlg;
}
class FishDlg : public QDialog
{
    Q_OBJECT
    QTimer *time;
    list<Fash*> *f_stack;//存放鱼
    list<Ball*> *b_stack;//存放炮弹
    char* f_str[11];
    bool mouse;//鼠标点击标志
    int money;
    QPoint mpoint;
public:
    explicit FishDlg(QWidget *parent = 0);
    ~FishDlg();

    void paintEvent(QPaintEvent *e);

    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent*);
    void keyPressEvent(QKeyEvent*e);

public:
    void newFash();
    void initString();
    void paintFash(QPainter& painter);
    void paintWeapon(QPainter& painter);
    void paintBall(QPainter& painter);
    void paintMoney(QPainter& painter);
    void rightFish(int type,int foot,float angle);
    void leftFish(int type,int foot,float angle);
    void topFish(int type,int foot,float angle);
    void bottomFish(int type,int foot,float angle);
    void paintString(QPainter& painter,QColor &color,int x,int y,int fontSize,QString &str);
    void addMoney(Fash* f);
private:
    Ui::FishDlg *ui;
};
#endif // FISHDLG_H
