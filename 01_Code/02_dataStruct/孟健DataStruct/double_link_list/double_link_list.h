
#ifndef __DOUBLE_LINK_LIST_H__
#define __DOUBLE_LINK_LIST_H__

/*节点*/
typedef struct listnode
{
	int data;
	struct listnode *prev;/*前驱节点指针变量*/
	struct listnode *next;/*后继节点指针变量*/
}LIST_NODE;

/*链表*/
typedef struct List
{
	LIST_NODE *head;/*头指针*/
	LIST_NODE *tail;/*尾指针*/

	LIST_NODE *frwd; /*正向迭代指针*/
	LIST_NODE *brwd; /*反向迭代指针*/
}LIST;

/*创建链表*/
LIST *list_create(void);
/*销毁链表*/
void list_destroy(LIST *list);

/*创建节点*/
LIST_NODE *node_create(int data, LIST_NODE* prev,
		               LIST_NODE *next);
/*销毁节点,后继节点通过返回传递给调用者，
  前驱节点通过参数传递给调用者*/
LIST_NODE *node_destroy(LIST_NODE *node, 
		                LIST_NODE **prev);

/*前插入节点
 * list 要操作的链表
 * pos, 要在list链表中的哪个位置之前插入
 */
int list_insert(LIST *list, int pos, int data);

/*后插入节点*/
void list_append(LIST *list, int data);

/*随机访问第pos个节点*/
int *list_at(LIST *list, int pos);

/*删除链表中pos位置的节点*/
void list_earse(LIST *list, int pos);

/*按data删除所有匹配成功的节点*/
void list_remove(LIST *list, int data);

/*清空链表*/
void list_clear(LIST *list);

/*判空*/
int list_empty(LIST *list);

/*开始正向迭代*/
void list_begin(LIST *list);

/*向后正向迭代*/
void list_next(LIST *list);

/*获取当前节点值*/
int *list_current(LIST *list);

/*判断正向迭代是否终止*/
int list_end(LIST *list);


#endif
