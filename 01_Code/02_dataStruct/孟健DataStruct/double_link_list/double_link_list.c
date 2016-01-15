#include <stdio.h>
#include <stdlib.h>

#include "double_link_list.h"

/*创建链表*/
LIST *list_create(void)
{
	LIST *list = malloc(sizeof(LIST));
	list->head = NULL;
	list->tail = NULL;
	list->frwd = NULL;
	list->brwd = NULL;

	return list;
}
/*销毁链表*/
void list_destroy(LIST *list)
{
	/*销毁链表中的所有节点*/
	list_clear(list);
	free(list);
}

/*创建节点*/
LIST_NODE *node_create(int data, LIST_NODE* prev,
		               LIST_NODE *next)
{
	LIST_NODE *node = malloc(sizeof(LIST_NODE));
	/*初始化节点*/
	node->data = data;
	node->prev = prev;
	node->next = next;

	return node;
}
/*销毁节点,后继节点通过返回传递给调用者，
  前驱节点通过参数传递给调用者*/
LIST_NODE *node_destroy(LIST_NODE *node, 
		                LIST_NODE **prev)
{
	LIST_NODE *next = node->next;
	if(prev)
	{
		/*返回要释放节点的前驱节点地址*/
		*prev = node->prev;
	}

	free(node);
	/*返回要释放节点的后继节点地址*/
	return next;

}

/*前插入节点
 * list 要操作的链表
 * pos, 要在list链表中的哪个位置之前插入
 */
int list_insert(LIST *list, int pos, int data)
{
	LIST_NODE *find = NULL;
	
	/*寻找pos节点的地址*/
	for(find=list->head; find; find=find->next)
	{
		/*当pos等于0代表找到了该节点*/
		if(!pos--)
		{
			LIST_NODE *node = node_create(data,
					                    find->prev,                                        find);
			/*如果前驱节点存在*/
			if(find->prev)
			{
				find->prev->next = node;
			}
			else
			{
				/*如果在第一个节点之前插入新节点*/
				list->head = node;
			}
			/*插入位置节点的prev重新赋值*/
			find->prev = node;

			/*插入成功，跳出for循环*/
			break;
		}
	}
}

/*后插入节点*/
void list_append(LIST *list, int data)
{
	/*在链表的尾部插入新节点，并使tail指向新的尾节点*/
	list->tail = node_create(data, list->tail,NULL);
	/*让原尾节点的next指向新的尾节点*/
	/*新尾节点的前驱节点不为空（即原链表为非空链表）*/
	if(list->tail->prev)
	{
		list->tail->prev->next = list->tail;
	}
	else
	{
		/*如果原链表为空，新加入的节点既是尾节点
		 也是头节点
		 */
		list->head = list->tail;
	}
}

/*随机访问第pos个节点*/
int *list_at(LIST *list, int pos)
{
	LIST_NODE *find = NULL;
	for(find=list->head; find; find=find->next)
	{
		if(!pos--)
		{
			return &(find->data);
		}
	}
	return NULL;
}

/*删除链表中pos位置的节点*/
void list_earse(LIST *list, int pos)
{
	LIST_NODE *find = NULL;
	for(find=list->head; find; find=find->next)
	{
		if(!pos--)
		{
			LIST_NODE *prev = NULL;
			LIST_NODE *next = NULL;
		    
			/*free 了find节点，并且返回了find节点
			 的前驱和后继节点地址*/	
			next = node_destroy(find,&prev);
			/*让前驱节点的next指向第三个节点*/
			if(prev)
			{
				/*如果删除的不是第一个节点*/
				prev->next = next;
			}
			else
			{
				/*如果删除的是第一个节点，让head
				 指向新的头节点*/
				list->head = next;
			}
			/*让后继节点的prev指向第一个节点*/
			if(next)
			{
				/*如果删除的节点不是尾节点*/
				next->prev = prev;
			}
			else
			{
				/*如果删除的是尾节点*/
				list->tail = prev;
			}
		}
	}

}

/*按data删除所有匹配成功的节点*/
void list_remove(LIST *list, int data)
{
	LIST_NODE *find = NULL;
	LIST_NODE *next = NULL;
	LIST_NODE *prev = NULL;

	for(find=list->head; find; find=next)
	{
		next = find->next;

		if(find->data == data)
		{
			next = node_destroy(find, &prev);
			/*让前驱节点的next指向第三个节点*/
			if(prev)
			{
				/*如果删除的不是第一个节点*/
				prev->next = next;
			}
			else
			{
				/*如果删除的是第一个节点，让head
				 指向新的头节点*/
				list->head = next;
			}
			/*让后继节点的prev指向第一个节点*/
			if(next)
			{
				/*如果删除的节点不是尾节点*/
				next->prev = prev;
			}
			else
			{
				/*如果删除的是尾节点*/
				list->tail = prev;
			}
		}
	}

}

/*清空链表*/
void list_clear(LIST *list)
{
	while(list->head)
	{
		list->head = node_destroy(list->head,NULL);
	}

	list->tail = NULL;
}

/*判空*/
int list_empty(LIST *list)
{
	if(!list->head && !list->tail)
	{
		return 1;/*空*/
	}	

	return 0;
}	
/*开始正向迭代*/
void list_begin(LIST *list)
{
	list->frwd = list->head;
}

/*向后正向迭代*/
void list_next(LIST *list)
{
	list->frwd = list->frwd->next;
}

/*获取当前节点data的地址*/
int *list_current(LIST *list)
{
	return &(list->frwd->data);
}

/*判断正向迭代是否终止*/
int list_end(LIST *list)
{
	return !(list->frwd);
}






