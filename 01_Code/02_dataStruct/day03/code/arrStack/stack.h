#ifndef STACK_H
#define STACK_H

//使用顺序存储结构实现堆栈的操作
#include <stdio.h>
#include <stdlib.h>

//定义堆栈的数据类型
typedef struct Stack
{
	//int arr[5];
	int* arr;//保存数组的首地址
	int len;//保存数组的长度
	int top;//保存数组的下标
}Stack;

//创建堆栈的函数
Stack* create(int len);
//销毁堆栈的函数
void destroy(Stack* ps);
//入栈操作
void push(Stack* ps,int data);
//遍历
void print(Stack* ps);
//计算栈中元素的个数 size
int size(Stack* ps);
//判断栈是否为满 isfull
int isfull(Stack* ps);
//判断栈是否为空 isempty
int isempty(Stack* ps);
//出栈操作  pop
int pop(Stack* ps);
//查看栈顶元素
int peek(Stack* ps);

#endif
