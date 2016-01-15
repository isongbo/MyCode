
#include <stdio.h>
#include <stdlib.h>

/*节点*/
typedef struct ListNode
{
	int data;/*数据*/
	struct ListNode *next;/*后继节点指针*/
}LIST_NODE;

/*创建新的节点*/
LIST_NODE *node_create(int data)
{
	LIST_NODE *node = malloc(sizeof(LIST_NODE));
	node->data = data;
	node->next = NULL;
	return node;
}

/*创建链表,带头节点*/
LIST_NODE *list_create(void)
{
	LIST_NODE *head = node_create(0);
	return head;
}

/*插入新的节点*/
void list_insert(LIST_NODE *head, int data)
{
	LIST_NODE *node = node_create(data);
	
	node->next = head->next;
	head->next = node;
}

void list_print(LIST_NODE *head)
{
	LIST_NODE *node = head->next;
	/*遍历链表*/
	for(; node; node=node->next)
	{
		printf("%d ", node->data);
	}
	printf("\n");
}

int main(void)
{
	/*创建链表*/
	LIST_NODE *head = list_create();
	/*插入节点*/
	list_insert(head,11);
	list_insert(head,35);
	list_insert(head,28);
	list_insert(head,66);
	list_insert(head,70);
	list_insert(head,19);
	list_print(head);

	return 0;

}



