#include"Fash.h"
///*
#include<math.h>
// 构造函数，初始化成员
Fash::Fash(double f_x1,double f_y1,int f_Type1,float angle,int f_foot1){
    f_x=f_x1;
    f_y=f_y1;
    f_type=f_Type1;
    f_angle = angle;
    f_foot=f_foot1;
    f_images=rand()%10;
    initString();
    f_catched=false;
    f_flag=0;
    f_text=0;
}
//初始化字符串 ，目前只有11种鱼
void Fash::initString(){
    f_str[0]="fish01_0";
    f_str[1]="fish02_0";
    f_str[2]="fish03_0";
    f_str[3]="fish04_0";
    f_str[4]="fish05_0";
    f_str[5]="fish06_0";
    f_str[6]="fish07_0";
    f_str[7]="fish08_0";
    f_str[8]="fish09_0";
    f_str[9]="fish10_0";
    f_str[10]="fish11_0";
}
//鱼游动
void Fash::move()
{
    f_x+=f_foot*sin(f_angle/180*3.1415926);
    f_y-=f_foot*cos(f_angle/180*3.1415926);


    if(f_angle<180){
        if(f_angle<90){
            if(f_y<200)
                f_angle+=0.5;
            else
                f_angle-=0.5;
        }
        else{
            if(f_y<200)
                f_angle-=0.5;
            else
                f_angle+=0.5;
        }

    }
    else{
        if(f_x<250){
            if(f_y<200)
                f_angle-=0.5;
            else
                f_angle+=0.5;
        }
        else
        {
            if(f_y<200)
                f_angle+=0.5;
            else
                f_angle-=0.5;
        }
    }
}

Ball::Ball(int b_type1,double b_x1,double b_y1,double angle1){
    b_type=b_type1;
    b_x=b_x1;
    b_y=b_y1;
    b_angle=angle1;
    b_foot=LENGHT;
    b_flag=0;
}
//子弹游动
void Ball::move()
{
    b_y-=LENGHT;
}

