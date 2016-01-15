//使用链式存储结构实现队列的操作
#include "queue.h"

int main(void)
{
	Queue queue;
	queue.list.head = NULL;
	push(&queue,11);
	print(&queue); // 11
	push(&queue,22);
	print(&queue); // 11 22
	push(&queue,33);
	print(&queue); // 11 22 33

	printf("-----------------\n");
	printf("队列中元素个数是：%d\n",size(&queue));
	printf("%s\n",isempty(&queue)?"队列空了":"队列没有空");
	printf("%s\n",isfull(&queue)?"队列满了":"队列没有满");
	printf("出队列的元素是：%d\n",pop(&queue));
	printf("队头元素是:%d\n",get_head(&queue));
	printf("队尾元素是：%d\n",get_tail(&queue));
	return 0;
}

