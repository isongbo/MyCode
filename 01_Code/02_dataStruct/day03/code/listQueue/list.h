#ifndef LIST_H
#define LIST_H

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

#endif
