//使用链式存储结构实现队列的操作
#include "queue.h"

//计算队列中元素的个数 size
int size(Queue* pq)
{
	return length(&pq->list);
}
//判断队列是否为满 isfull
int isfull(Queue* pq)
{
	return full(&pq->list);
}
//判断队列是否为空 isempty
int isempty(Queue* pq)
{
	return empty(&pq->list);
}
//出队列操作 pop
int pop(Queue* pq)
{
	int res = get_front(&pq->list);
	pop_head(&pq->list);
	return res;
}
//查看队头元素值 get_head
int get_head(Queue* pq)
{
	return get_front(&pq->list);
}
//查看队尾元素值 get_tail
int get_tail(Queue* pq)
{
	return get_back(&pq->list);
}
//遍历队列
void print(Queue* pq)
{
	travel(&pq->list);
}

//入队操作
void push(Queue* pq,int data)
{
	//将数据插入到链表中
	push_tail(&pq->list,data);
}









