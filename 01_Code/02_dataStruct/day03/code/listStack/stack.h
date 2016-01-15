#ifndef STACK_H
#define STACK_H

//使用链式存储结构实现栈的基本操作
#include "list.h"

//定义栈的数据类型
typedef struct Stack
{
	//定义链表作为成员
	List list;
}Stack;

//入栈操作
void push(Stack* ps,int data);
//遍历栈中的元素
void print(Stack* ps);
//计算栈中元素的个数 size
int size(Stack* ps);
//判断栈是为满 isfull
int isfull(Stack* ps);
//判断栈是否为空 isempty
int isempty(Stack* ps);
//查看栈顶元素 peek
int peek(Stack* ps);
//出栈操作 pop
int pop(Stack* ps);

#endif
