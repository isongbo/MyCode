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
//计算队列中元素的个数
int size(Queue* pq);
//判断队列是否为满
int isfull(Queue* pq);
//判断队列是否为空
int isempty(Queue* pq);
//获取队头元素值
int get_head(Queue* pq);
//获取队尾元素值
int get_tail(Queue* pq);
//出队操作
int pop(Queue* pq);

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
	
	printf("---------------------\n");
	printf("队列中元素个数是：%d\n",size(pq));
	printf("%s\n",isfull(pq)?"队列满了":"队列没有满");
	printf("%s\n",isempty(pq)?"队列空了":"队列没有空");
	
	printf("-------------------------\n");
	printf("队头元素是：%d\n",get_head(pq));
	printf("队尾元素是：%d\n",get_tail(pq));
	printf("入队元素是：%d\n",pop(pq));
	print(pq);
	
	destroy(pq);
	return 0;
}

//获取队头元素值
int get_head(Queue* pq)
{
	return isempty(pq)?-1:pq->arr[pq->front%pq->len];
}
//获取队尾元素值
int get_tail(Queue* pq)
{
	return isempty(pq)?-1:pq->arr[(pq->front+pq->cnt-1)%pq->len];
}
//出队操作
int pop(Queue* pq)
{
	return isempty(pq)?-1:--pq->cnt,pq->arr[pq->front++%pq->len];
	//pq->front++;
}

//计算队列中元素的个数
int size(Queue* pq)
{
	return pq->cnt;
}
//判断队列是否为满
int isfull(Queue* pq)
{
	return pq->cnt == pq->len;
}
//判断队列是否为空
int isempty(Queue* pq)
{
	return 0 == pq->cnt;
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




