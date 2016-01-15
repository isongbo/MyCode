
#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

int main(void)
{
	/*1、创建空树*/
	BSTREE *bstree =  bstree_create();
	
	/*2向树中插入节点*/
	bstree_insert(bstree, 50);
	//bstree_insert(bstree, 50);
	bstree_insert(bstree, 70);
	bstree_insert(bstree, 20);
	bstree_insert(bstree, 60);
	bstree_insert(bstree, 40);
	bstree_insert(bstree, 30);
	bstree_insert(bstree, 10);
	bstree_insert(bstree, 90);
	bstree_insert(bstree, 80);
	/*打印树*/
	bstree_print(bstree);
	
	/*3 遍历树*/
	printf("中序遍历：");
	bstree_intravel(bstree->root);
	printf("\n");
	printf("先序遍历：");
	bstree_pretravel(bstree->root);
	printf("\n");
	printf("后序遍历：");
	bstree_postravel(bstree->root);
	printf("\n");

	/*4 删除节点*/
	bstree_erase(bstree, 50);
	/*打印树*/
	bstree_print(bstree);
	printf("中序遍历：");
	bstree_intravel(bstree->root);
	printf("\n");

	/*销毁树*/
	bstree_destroy(bstree);
	bstree = NULL;
	/*打印树*/
	bstree_print(bstree);

	return 0;

}


