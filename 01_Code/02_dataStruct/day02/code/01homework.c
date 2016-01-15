//链式存储结构的使用
#include <stdio.h>
#include <stdlib.h>

//定义结构体类型
typedef struct Node
{
	int data;//数据内容
	struct Node* next;//下一个元素地址
}Node;// => struct Node

void travel(Node* p)
{
	printf("链式存储结构的元素有：");
	while(p /*!= NULL*/)
	{
		printf("%d ",p->data);
		//指向下一个
		p = p->next;
	}
	printf("\n");
}

int main(void)
{
	//1.初始化3个元素
	Node* p1 = (Node*)malloc(sizeof(Node));
	p1->data = 11;
	p1->next = NULL;
	Node* p2 = (Node*)malloc(sizeof(Node));
	p2->data = 22;
	p2->next = NULL;
	Node* p3 = (Node*)malloc(sizeof(Node));
	p3->data = 33;
	p3->next = NULL;
	//2.组成链式存储结构进行遍历
	p1->next = p2;
	p2->next = p3;
	travel(p1);
	//3.动态创建一个新元素
	Node* q = (Node*)malloc(sizeof(Node));
	q->data = 44;
	q->next = NULL;
	//4.将新元素插入到第一个位置
	q->next = p1;
	//p1 = q;
	travel(q);//q指向的元素是第一个元素
	
	
	//5.删除第二个元素，也就是11这个元素
	q->next = p2;
	free(p1);
	p1 = NULL;
	travel(q);
	
	//6.修改第三个元素的值，也就是元素33
	p3->data = 333;
	travel(q);
	
	printf("--------------------\n");
	//7.释放所有元素
	free(q); q = NULL;
	free(p2); p2 = NULL;
	free(p3); p3 = NULL;
	travel(q);
	
	return 0;
}





