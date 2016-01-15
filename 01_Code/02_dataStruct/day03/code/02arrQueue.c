//使用顺序存储结构实现队列的操作
#include <stdio.h>
#include <stdlib.h>

//定义队列的数据类型
typedef struct Queue
{
	int* arr;//数组的首地址
	int len;//数组的长度
	int front;//队头元素的下标
	int cnt;//队列中元素的个数
}Queue;

//创建队列的函数
Queue* create(int len);
//销毁队列的函数
void destroy(Queue* pq);
//入队操作
void push(Queue* pq,int data);
//遍历队列
void print(Queue* pq);

int main(void)
{
	Queue* pq = create(5);
	push(pq,11);
	print(pq); // 11
	push(pq,22);
	print(pq); // 11 22
	push(pq,33);
	print(pq); // 11 22 33
	push(pq,44);
	print(pq); // 11 22 33 44
	push(pq,55);
	print(pq); // 11 22 33 44 55
	push(pq,66); //入队列失败
	
	destroy(pq);
	return 0;
}

//遍历队列
void print(Queue* pq)
{
	int i = 0;
	printf("队列中的元素有：");
	for(i = pq->front; i < pq->front + pq->cnt; i++)
	{
		printf("%d ",pq->arr[i%pq->len]);
	}
	printf("\n");
}

//入队操作
void push(Queue* pq,int data)
{
	//判断队列是否为满
	if(pq->cnt >= pq->len)
	{
		printf("队列已满，入队失败\n");
		return;
	}
	//进行入队操作
	pq->arr[(pq->front+pq->cnt)%pq->len] = data;
	pq->cnt++;
}

//销毁队列的函数
void destroy(Queue* pq)
{
	free(pq->arr);
	pq->arr = NULL;
	free(pq);
	pq = NULL;
}

//创建队列的函数
Queue* create(int len)
{
	Queue* pq = (Queue*)malloc(sizeof(Queue));
	pq->arr = (int*)malloc(len*sizeof(int));
	pq->len = len;
	pq->front = 0;
	pq->cnt = 0;
	return pq;
}




