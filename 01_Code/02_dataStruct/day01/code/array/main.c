//使用顺序存储结构实现各种操作
#include "arr.h"

int main(void)
{
	insert(-2,11); //插入失败
	insert(0,22);
	travel();//22
	insert(0,11);
	travel();//11 22
	insert(2,33);
	travel();//11 22 33
	
	randNum();

	printf("-----------------------\n");
	del(-2); //删除失败
	del(0); //11
	travel();//22 33

	printf("----------------------\n");
	int res = find(33);
	if(-1 != res)
	{
		printf("元素所对应的下标：%d\n",res);
	}
	else
	{
		printf("此元素不存在\n");
	}
	modify(0,222);
	travel();
	return 0;
}

