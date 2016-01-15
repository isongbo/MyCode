#ifndef ARR_H
#define ARR_H

//使用顺序存储结构实现各种操作
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//编写函数实现向数组指定位置插入指定元素
void insert(int top,int data);
//编写函数遍历数组中所有元素
void travel(void);
//编写函数实现随机访问功能
void randNum(void);
//编写函数实现删除指定位置的元素
void del(int top);
//编写函数实现查找指定元素的下标
int find(int data);
//编写函数实现修改指定位置的元素为新元素值
void modify(int top,int newData);

#endif
