
#include <stdio.h>
#include <stdlib.h>

#include "double_link_list.h"

int main(void)
{
	printf("创建双向链表\n");
	LIST *list = list_create();

	/*插入数据*/
	printf("尾部插入\n");
	list_append(list, 10);
	list_append(list, 20);
	list_append(list, 50);
	list_append(list, 60);
	/*任意位置插入*/
	list_insert(list,2,30);
	list_insert(list,3,40);

	/*正向遍历*/
	printf("正向遍历链表");
	for(list_begin(list); !list_end(list); list_next(list))
	{
		printf("%d  ", *list_current(list));
	}
	printf("\n");
	
	
	/*反向遍历*/
	//printf("反向遍历链表");
	getchar();

	/*删除节点*/
	list_earse(list,0);
	list_remove(list,40);
	/*正向遍历*/
	printf("正向遍历链表");
	for(list_begin(list); !list_end(list); list_next(list))
	{
		printf("%d  ", *list_current(list));
	}
	printf("\n");
	getchar();

	/*随机访问*/
	printf("随机访问\n");
	
	printf("3 node = %d\n", *list_at(list,3));

	getchar();
	/*销毁链表*/
	list_destroy(list);
	return 0;
}


