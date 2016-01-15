//单链表的各种操作
#include <stdio.h>
#include <stdlib.h>

//定义节点的数据类型
typedef struct Node
{
	int data;//数据内容
	struct Node* next;//下一个节点地址
}Node;

//定义单链表的数据类型
typedef struct List
{
	Node* head;//头指针
}List;

//向链表中头节点位置插入新节点
void push_head(List* pl,int data);
//遍历链表中所有节点元素值
void travel(List* pl);
//释放链表中的所有节点
void clear(List* pl);
//创建新节点的函数
Node* create_node(int data);
//计算链表中节点的个数，返回
int length(List* pl);
//向链表中任意位置插入新节点
void insert(List* pl,int pos,int data);
//向链表中尾节点位置插入新节点
void push_tail(List* pl,int data);
//删除链表中指定下标的节点元素
void del(List* pl,int pos);
//删除头结点的函数 pop_head
void pop_head(List* pl);
//删除尾节点的函数 pop_tail
void pop_tail(List* pl);
//判断链表是否为空 empty
int empty(List* pl);
//判断链表是否为满 full
int full(List* pl);
//查看链表头结点元素值
int get_front(List* pl);
//查看链表尾节点元素值
int get_back(List* pl);

int main(void)
{
	//创建一个链表
	List list;
	//int num; 栈区
	//List* pl = (list*)malloc(sizeof(List));
	list.head = NULL;
	push_head(&list,33);
	travel(&list); // 33
	push_head(&list,22);
	travel(&list); // 22 33
	push_head(&list,11);
	travel(&list); // 11 22 33

	//clear(&list);
	//travel(&list);

	printf("链表中节点的个数是：%d\n",length(&list));

	printf("--------------------------\n");
	insert(&list,-2,44);
	travel(&list); // 11 22 33 44
	insert(&list,0,55);
	travel(&list); // 55 11 22 33 44
	insert(&list,3,66);
	travel(&list); // 55 11 22 66 33 44
	insert(&list,6,77);
	travel(&list); // 55 11 22 66 33 44 77

	push_tail(&list,88);
	travel(&list);// 55 11 22 66 33 44 77 88

	printf("--------------------------\n");
	del(&list,-2); //删除失败
	del(&list,0);
	travel(&list); // 11 22 66 33 44 77 88
	del(&list,2);
	travel(&list); // 11 22 33 44 77 88
	del(&list,5);
	travel(&list); // 11 22 33 44 77

	printf("---------------------\n");
	pop_head(&list);
	travel(&list); // 22 33 44 77
	pop_tail(&list);
	travel(&list); // 22 33 44
	printf("%s\n",empty(&list)?"链表为空":"链表不为空");
	printf("%s\n",full(&list)?"链表为满":"链表没有满");

	printf("-------------------------\n");
	printf("链表头节点元素值是：%d\n",get_front(&list));
	printf("链表尾节点元素值是：%d\n",get_back(&list));
	return 0;
}

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







