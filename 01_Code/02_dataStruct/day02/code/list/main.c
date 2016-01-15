//单链表的各种操作
#include "list.h"

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

