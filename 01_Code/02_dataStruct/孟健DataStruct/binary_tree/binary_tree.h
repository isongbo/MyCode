#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef struct BsTreeNode
{
	int data; /*数据*/
	struct BsTreeNode *left; /*左子树*/
	struct BsTreeNode *right; /*右子树*/
}BSTREE_NODE;

typedef struct BsTree
{
	BSTREE_NODE *root; /*树根*/
	int size;  /*该树中节点的个数*/
}BSTREE;

/*创建树*/
BSTREE *bstree_create(void);

/*销毁树*/
void bstree_destroy(BSTREE *bstree);

/*插入节点*/
void bstree_insert(BSTREE *bstree, int data);

/*删除节点*/
int bstree_erase(BSTREE *bstree, int data);

/*按照树形打印该树*/
void bstree_print(BSTREE *bstree);

/*先序遍历*/
void bstree_pretravel(BSTREE_NODE *root);
/*中序遍历*/
void bstree_intravel(BSTREE_NODE *root);
/*后序遍历*/
void bstree_postravel(BSTREE_NODE *root);



#endif
