#ifndef SNAKEGAME_H
#define SNAKEGAME_H
#include <QDialog>
#include <QLabel>
#include <QList>
#include <QTimer>
enum  Direction{
    D_UP,D_DOWN,D_LEFT,D_RIGHT };
class SnakeGame:public QDialog{
    Q_OBJECT
/* 特征: */
private:
    /* 食物 */
    QLabel  *food;
    /* 蛇 */
    QList<QLabel*> snake;
    /* 方向 */
    Direction  dire;
    /* 步长 */
    int  footLen;
    /* 控制频率的定时器 */
    QTimer   *timer;
    /* 本关的分数 */
    int  score;
/* 行为 */
public:
    SnakeGame();
/* 根据方向蛇移动的函数  */
public slots:
    void  snakeMove();
/* 控制方向的键盘事件处理函数 */
public:
    void  keyPressEvent(QKeyEvent *e);
public:
    /* 吃食物 */
    void  eatFood();
    /* 产生新食物的函数 */
    QLabel* getNewFood();
};
#endif // SNAKEGAME_H
