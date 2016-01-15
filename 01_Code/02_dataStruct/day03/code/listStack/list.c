//单链表的各种操作
#include "list.h"

//查看链表头结点元素值
int get_front(List* pl)
{
	/*
	if(empty(pl))
	{
		printf("链表为空,获取头结点元素失败\n");
		return -1;
	}
	return pl->head->data;
	*/
	return empty(pl)?-1:pl->head->data;
}

//查看链表尾节点元素值
int get_back(List* pl)
{
	if(empty(pl))
	{
		printf("链表为空，获取尾节点元素失败\n");
		return -1;
	}
	//遍历找到尾节点，然后返回元素值
	Node* p = pl->head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	return p->data;
}

//删除头结点的函数 pop_head
void pop_head(List* pl)
{
	del(pl,0);
}

//删除尾节点的函数 pop_tail
void pop_tail(List* pl)
{
	del(pl,length(pl)-1);
}

//判断链表是否为空 empty
int empty(List* pl)
{
	return NULL == pl->head;
}

//判断链表是否为满 full
int full(List* pl)
{
	return 0;
}

//删除链表中指定下标的节点元素
void del(List* pl,int pos)
{
	//1.判断坐标是否合法
	if(pos < 0 || pos >= length(pl))
	{
		printf("坐标%d不合法,删除失败\n",pos);
		return;
	}
	//2.删除头节点
	if(0 == pos)
	{
		Node* q = pl->head;
		pl->head = q->next;
		free(q);
		q = NULL;
		return;
	}
	//3.删除其他节点
	Node* p = pl->head;
	int i = 0;
	for(i = 1; i < pos; i++)
	{
		p = p->next;
	}
	Node* q = p->next;
	p->next = q->next;
	free(q);
	q = NULL;
}

//向链表中尾节点位置插入新节点
void push_tail(List* pl,int data)
{
	insert(pl,length(pl),data);
}

//向链表中任意位置插入新节点
void insert(List* pl,int pos,int data)
{
	//1.判断坐标是否合法
	if(pos < 0 || pos > length(pl))
	{
		//表示坐标不合法默认插入到链表尾部
		pos = length(pl);
		//pos = 0;
	}
	//2.创建新节点
	Node* pn = create_node(data);
	//3.将新节点插入到链表中
	//3.1 插入到头结点位置
	if(0 == pos)
	{
		pn->next = pl->head;
		pl->head = pn;
		return;
	}
	//3.2 插入到其他位置
	//当pos = 1时
	//   pn->next = pl->head->next;
	//   pl->head->next = pn;
	//当pos = 2时
	//   pn->next = pl->head->next->next;
	//   pl->head->next->next = pn;
	//当pos = 3时
	//   ...
	//综上所述：
	//   当pos=n时,比pos=1多n-1次next
	Node* p = pl->head;
	int i = 0;
	for(i = 1; i < pos; i++)
	{
		p = p->next;
	}
	pn->next = p->next;
	p->next = pn;
}

//计算链表中节点的个数，返回
int length(List* pl)
{
	int cnt = 0;
	Node* p = pl->head;
	while(p/* != NULL*/)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}

//创建新节点的函数
Node* create_node(int data)
{
	Node* pn = (Node*)malloc(sizeof(Node));
	pn->data = data;
	pn->next = NULL;
	return pn;
}

//释放链表中的所有节点
void clear(List* pl)
{
	while(NULL != pl->head)
	{
		//记录下一个节点位置
		Node* p = pl->head->next;
		//释放当前节点
		free(pl->head);
		//重新指向要删除的节点
		pl->head = p;
	}
}

//遍历链表中所有节点元素值
void travel(List* pl)
{
	printf("链表中的元素有：");
	Node* p = pl->head;
	while(p)
	{
		printf("%d ",p->data);
		//指向下一个
		p = p->next;
	}
	printf("\n");
}

//向链表中头节点位置插入新节点
void push_head(List* pl,int data)
{
	//1.创建新节点
	//Node n;
	//pn指向内存在堆区,pn本身在栈区
	//Node* pn = (Node*)malloc(sizeof(Node));
	//pn->data = data;
	//pn->next = NULL;
	//Node* pn = create_node(data);

	//2.将新节点插入到头结点位置
	//pn->next = pl->head;
	//pl->head = pn;
	insert(pl,0,data);
}







