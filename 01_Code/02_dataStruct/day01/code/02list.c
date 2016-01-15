//链式存储结构的各种操作
#include <stdio.h>
#include <stdlib.h>

//定义结构体类型
struct Node
{
	int data;//存储具体的数据内容
	struct Node* next;//存放下一个元素地址
};

void travel(struct Node* pn)
{
	printf("链式结构中的元素有：");
	while(NULL != pn)
	{
		printf("%d ",pn->data);
		//指针指向下一个元素
		pn = pn->next;
	}
	printf("\n");
}

int main(void)
{
	//1.准备三个结构体变量
	struct Node n1 = {11,NULL};
	struct Node n2 = {22,NULL};
	struct Node n3 = {33,NULL};
	//2.组成链式存储结构
	n1.next = &n2;
	n2.next = &n3;
	struct Node* p = &n1;
	//3.循环遍历链式存储结构中所有元素值
	/*
	struct Node* pn = p;
	printf("链式结构中的元素有：");
	while(NULL != pn)
	{
		printf("%d ",pn->data);
		//指针指向下一个元素
		pn = pn->next;
	}
	printf("\n");
	*/
	//练习：打包在一个travel函数中
	travel(p);

	printf("-----------------------\n");
	//4.创建新元素，插入到链式结构第一个位置
	struct Node* q = (struct Node*)malloc(sizeof(struct Node));
	q->data = 44;
	q->next = NULL;

	q->next = p;
	p = q;
	travel(p);
	
	//5.删除新元素
	p = p->next;
	free(q);
	q = NULL;
	travel(p);
	return 0;
}





