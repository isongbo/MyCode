///*
#ifndef FASH_H
#define FASH_H
#include<QPoint>
#include<qmath.h>
#include <QDebug>
#include<QPixmap>
#define LENGHT 20
#include<qstring.h>
/*
**管理鱼类，提供了鱼的游动管理函数
*/
class Fash{
public :
    double f_x;//小鱼所在位置x坐标
    double f_y;//小鱼所在位置y坐标
    int f_type;//小鱼的类型
    float f_angle;//方向，与垂直方向的角度
    int f_foot;//步长
    int f_images;//标识鱼当前动作，用于鱼游动过程中图片的切换
    char *f_str[11];//用于标识不同鱼类
    bool f_catched;//标记鱼是否被击中

    int f_flag;//标记
    int f_text;//绘制字体
public:
    Fash(double f_x1,double f_y1,int f_Type1,float angle,int f_foot1);
    void move();//简单的路径算法
    void initString();
};
/*
**子弹类，提供了子弹的移动管理函数
*/
class Ball{
public:
    int b_type;//子弹的类型
    double b_x;//子弹x轴方向的坐标
    double b_y;//子弹y轴方向的坐标
    double b_angle;//角度
    int b_foot;//子弹的步长
    int b_flag;
public:
    Ball(int b_type1,double b_x1,double b_y1,double angle1);
    void move();
};
#endif // FASH_H
//*/
