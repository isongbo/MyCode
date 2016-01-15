#ifndef QUEUE_H
#define QUEUE_H

//使用链式存储结构实现队列的操作
#include "list.h"

//定义队列的数据类型
typedef struct Queue
{
	//定义链表作为成员
	List list;
}Queue;

//入队操作
void push(Queue* pq,int data);
//遍历队列
void print(Queue* pq);
//计算队列中元素的个数 size
int size(Queue* pq);
//判断队列是否为满 isfull
int isfull(Queue* pq);
//判断队列是否为空 isempty
int isempty(Queue* pq);
//出队列操作 pop
int pop(Queue* pq);
//查看队头元素值 get_head
int get_head(Queue* pq);
//查看队尾元素值 get_tail
int get_tail(Queue* pq);

#endif
