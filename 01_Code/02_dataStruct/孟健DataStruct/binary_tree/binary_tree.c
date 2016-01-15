#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

/*创建树的节点*/
BSTREE_NODE *create_node(int data)
{
	BSTREE_NODE *node = malloc(sizeof(BSTREE_NODE));
	/*初始化该节点成员变量*/
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void insert(BSTREE_NODE *node, BSTREE_NODE **pes_root)
{
	/*如果为空树*/
	if(*pes_root == NULL)
    {
		*pes_root = node;
	}
	else
	{
		/*如果树不为空*/
		/*待插入节点的值小于根节点，待插入节点一定插入其左子树*/
		if(node->data < (*pes_root)->data)
		{
			insert(node,&((*pes_root)->left));
		}
		else
		{
			insert(node, &((*pes_root)->right));
		}
	}

}
/*创建树*/
BSTREE *bstree_create(void)
{
	BSTREE *bstree = malloc(sizeof(BSTREE));
	/*初始化成员变量*/
	bstree->root = NULL;
	bstree->size = 0;

	return bstree;
}
void node_destroy(BSTREE_NODE *node)
{
	free(node);
}
void clear(BSTREE_NODE **pes_root)
{
	/*该树非空*/
	if(*pes_root)
	{
		/*清空左子树*/
		clear( &((*pes_root)->left));
		/*清空右子树*/
		clear( &((*pes_root)->right));
		
		/*销毁根节点*/
		node_destroy(*pes_root);
		*pes_root = NULL;
	}
}

void bstree_clear(BSTREE *bstree)
{
	/*销毁所有子树*/
	clear(&(bstree->root));

	bstree->size = 0;
}

/*销毁树*/
void bstree_destroy(BSTREE *bstree)
{
	/*销毁树中的所有节点，使其成为空树*/
	bstree_clear(bstree);

	free(bstree);

}

/*插入节点*/
void bstree_insert(BSTREE *bstree, int data)
{
	/*将创建好的节点插入到root指向的树中去*/
	insert(create_node(data), &(bstree->root));

}

BSTREE_NODE **find(int data, BSTREE_NODE **root)
{
	/*如果为空树*/
	if(!*root)
	{
		return NULL;
	}
	if(data < ((*root)->data))
	{
		/*访问左子树*/
		return find(data, &((*root)->left));
	}
	else if(data > ((*root)->data))
	{
		/*访问右子树*/
		return find(data, &((*root)->right));
	}
	else
	{
		return root;
	}

}

/*删除节点*/
int bstree_erase(BSTREE *bstree, int data)
{
	/*找到节点*/
	BSTREE_NODE **node = find(data, &bstree->root);

	/*如果找到节点*/
	if(*node)
	{
		/*1、将匹配节点的左子树插入其右子树*/
		insert((*node)->left, &((*node)->right));
		
		BSTREE_NODE  *tmp = *node;
		/*2、用匹配节点的右子树的跟节点取代匹配节点*/
		*node = (*node)->right;

		/*3 free掉匹配节点*/
		node_destroy(tmp);

		return 1;/*删除成功*/
	}

	return 0;
}

void print(BSTREE_NODE *root, int level)
{
	int i  = 0;
	/*树非空*/
	if(root)
	{
		print(root->right, level+1);
		for(i=0; i<level; i++)
		{
			printf("  ");
		}
		printf("%d\n", root->data);
		print(root->left, level+1);
	}
	
}

/*按照树形打印该树*/
void bstree_print(BSTREE *bstree)
{
	if(bstree)
	{
		print(bstree->root, 0);	
	}
}

/*先序遍历*/
void bstree_pretravel(BSTREE_NODE *root)
{
	if(root)
	{
		/*访问根节点*/
		printf("%d  ", root->data);
		/*遍历左子树*/
		bstree_pretravel(root->left);
		/*遍历右子树*/
		bstree_pretravel(root->right);
	}
}
/*中序遍历*/
void bstree_intravel(BSTREE_NODE *root)
{
	if(root)
	{
		/*遍历左子树*/
		bstree_intravel(root->left);
		/*访问根节点*/
		printf("%d  ", root->data);
		/*遍历右子树*/
		bstree_intravel(root->right);

	}
}
/*后序遍历*/
void bstree_postravel(BSTREE_NODE *root)
{

	if(root)
	{
		/*遍历左子树*/
		bstree_postravel(root->left);
		/*遍历右子树*/
		bstree_postravel(root->right);
		/*访问根节点*/
		printf("%d  ", root->data);
	}
}
/*更新节点*/
void bstree_update(BSTREE *tree, int old, int new)
{
	while(bstree_erase(tree, old))
	{
	   bstree_insert(tree, new);
	}
}




