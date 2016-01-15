//有序二叉树的各种操作
#include <stdio.h>
#include <stdlib.h>

//定义二叉树中节点的数据类型
typedef struct Node
{
	int data;//数据元素值
	struct Node* left;//指向左子树的指针
	struct Node* right;//指向右子树的指针
}Node;

//定义二叉树的数据类型
typedef struct Tree
{
	Node* root;//指向根节点
	int count;//记录节点的个数
}Tree;

//插入节点
void insertData(Tree* pt,int data);
//创建新节点的函数
Node* create_node(int data);
//插入节点的递归函数
void insert(Node** ppRoot,Node* pn);
//采用中序遍历二叉树中的元素
void travelData(Tree* pt);
//递归遍历的函数
void travel(Node* pRoot);
//清空二叉树
void clearData(Tree* pt);
//清空的递归函数
void clear(Node** ppRoot);
//查找指定元素节点位置的函数
Node** findData(Tree* pt,int data);
//查找的递归函数
Node** find(Node** ppRoot,int data);
//删除指定元素的函数
void delData(Tree* pt,int data);
//修改元素的值
void modify(Tree* pt,int oldNum,int newNum);
//判断二叉树是否为空
int isempty(Tree* pt);
//判断二叉树是否为满
int isfull(Tree* pt);
//获取二叉树中元素的个数
int size(Tree* pt);
//获取根节点的元素值
int getRoot(Tree* pt);

int main(void)
{
	//创建二叉树并且进行初始化
	Tree tree;
	tree.root = NULL;
	tree.count = 0;

	insertData(&tree,45);
	travelData(&tree); // 45
	insertData(&tree,20);
	travelData(&tree); // 20 45
	insertData(&tree,30);
	travelData(&tree); // 20 30 45
	insertData(&tree,60);
	travelData(&tree); // 20 30 45 60
	insertData(&tree,25);
	travelData(&tree); // 20 25 30 45 60

	printf("-------------------\n");
	//clearData(&tree);
	//travelData(&tree); // 啥都没有 你瞅啥
	delData(&tree,30);
	travelData(&tree); // 20 25 45 60

	modify(&tree,25,15);
	travelData(&tree);
	printf("%s\n",isempty(&tree)?"二叉树空了":"二叉树没有空");
	printf("%s\n",isfull(&tree)?"二叉树满了":"二叉树没有满");
	printf("二叉树中元素的个数是：%d\n",size(&tree));
	printf("二叉树中根节点元素值是：%d\n",getRoot(&tree));
	return 0;
}

//修改元素的值
void modify(Tree* pt,int oldNum,int newNum)
{
	//1.删除旧节点
	delData(pt,oldNum);
	//2.插入新节点
	insertData(pt,newNum);
}

//判断二叉树是否为空
int isempty(Tree* pt)
{
	return NULL == pt->root;
}

//判断二叉树是否为满
int isfull(Tree* pt)
{
	return 0;
}
//获取二叉树中元素的个数
int size(Tree* pt)
{
	return pt->count;
}
//获取根节点的元素值
int getRoot(Tree* pt)
{
	return isempty(pt)?-1:pt->root->data;
}
//删除指定元素的函数
void delData(Tree* pt,int data)
{
	//1.查找数据所对应的位置
	Node** ppn = findData(pt,data);
	//2.查找失败的处理方法
	if(NULL == *ppn)
	{
		printf("查找失败,元素%d不存在\n",data);
		return;
	}
	//3.查找成功的处理方法
	//3.1 将要删除节点的左子树合并到右子树中
	if(NULL != (*ppn)->left)
	{
		insert(&(*ppn)->right,(*ppn)->left);
	}
	//3.2 使用临时指针记录要删除的节点地址
	Node* p = *ppn;
	//3.3 将合并出来的二叉树连接到大二叉树中
	*ppn = (*ppn)->right;
	//3.4 删除节点,节点个数减1
	free(p);
	p = NULL;
	pt->count--;
}

//查找指定元素节点位置的函数
Node** findData(Tree* pt,int data)
{
	//调用递归函数
	return find(&pt->root,data);
}
//查找的递归函数
Node** find(Node** ppRoot,int data)
{
	//1.判断二叉树是否为空，如果为空，直接返回
	if(NULL == *ppRoot)
	{
		return ppRoot;
	}
	//2.判断新元素和根节点元素的大小,如果相等，则直接返回
	if(data == (*ppRoot)->data)
	{
		return ppRoot;
	}
	//3.如果新元素小于根节点,左子树中查找
	else if(data < (*ppRoot)->data)
	{
		return find(&(*ppRoot)->left,data);
	}
	//4.如果新元素大于根节点,右子树中查找
	else
	{
		return find(&(*ppRoot)->right,data);
	}
}

//清空二叉树
void clearData(Tree* pt)
{
	//调用递归函数
	clear(&pt->root);
	//节点个数为0;
	pt->count = 0;
}

//清空的递归函数
void clear(Node** ppRoot)
{
	if(NULL != *ppRoot)
	{
		//1.清空左子树
		clear(&(*ppRoot)->left);
		//2.清空右子树
		clear(&(*ppRoot)->right);
		//3.清空根节点
		free(*ppRoot);
		*ppRoot = NULL;
	}
}

//递归遍历的函数
void travel(Node* pRoot)
{
	if(NULL != pRoot)
	{
		//1.遍历左子树
		travel(pRoot->left);
		//2.遍历根节点
		printf("%d ",pRoot->data);
		//3.遍历右子树
		travel(pRoot->right);
	}
}

//采用中序遍历二叉树中的元素
void travelData(Tree* pt)
{
	//调用递归函数进行真正的遍历
	travel(pt->root);
	printf("\n");
}

//插入节点的递归函数
void insert(Node** ppRoot,Node* pn)
{
	//Node** ppRoot = &pt->root;
	// *ppRoot = *(&pt->root) = pt->root
	//1.判断二叉树是否为空,如果为空，直接插入
	if(NULL == *ppRoot)
	{
		*ppRoot = pn;
	}
	//2.如果不为空,判断新节点与根节点的大小
	//2.1 如果新节点比根节点小，插入到左子树
	else if(pn->data < (*ppRoot)->data)
	{
		insert(&(*ppRoot)->left,pn);
	}
	//2.2 否则插入到右子树
	else
	{
		insert(&(*ppRoot)->right,pn);
	}
}

//插入节点
void insertData(Tree* pt,int data)
{
	//1.创建新节点
	Node* pn = create_node(data);
	//2.将新节点插入到二叉树中
	insert(&pt->root,pn);
	//3.节点个数加1
	pt->count++;
}

//创建新节点的函数
Node* create_node(int data)
{
	Node* pn = (Node*)malloc(sizeof(Node));
	pn->data = data;
	pn->left = NULL;
	pn->right = NULL;
	return pn;
}





