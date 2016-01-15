//使用链式存储结构实现栈的基本操作
#include "stack.h"

//计算栈中元素的个数 size
int size(Stack* ps)
{
	return length(&ps->list);
}

//判断栈是为满 isfull
int isfull(Stack* ps)
{
	return full(&ps->list);
}

//判断栈是否为空 isempty
int isempty(Stack* ps)
{
	return empty(&ps->list);
}

//查看栈顶元素 peek
int peek(Stack* ps)
{
	return get_front(&ps->list);
}

//出栈操作 pop
int pop(Stack* ps)
{
	int res = get_front(&ps->list);
	pop_head(&ps->list);
	return res;
}

//遍历栈中的元素
void print(Stack* ps)
{
	printf("栈中元素:");
	//遍历链表中的元素
	travel(&ps->list);
}

//入栈操作
void push(Stack* ps,int data)
{
	//将数据插入到链表中
	push_head(&ps->list,data);
}



