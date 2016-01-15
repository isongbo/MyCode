//使用顺序存储结构实现堆栈的操作
#include "stack.h"

//查看栈顶元素
int peek(Stack* ps)
{
	return isempty(ps)?-1:ps->arr[ps->top-1];
}

//计算栈中元素的个数 size
int size(Stack* ps)
{
	return ps->top;
}

//判断栈是否为满 isfull
int isfull(Stack* ps)
{
	return ps->top == ps->len;
}

//判断栈是否为空 isempty
int isempty(Stack* ps)
{
	return 0 == ps->top;
}
//出栈操作  pop 不考虑元素值为-1
int pop(Stack* ps)
{
	return isempty(ps)?-1:ps->arr[--ps->top];
}

//遍历
void print(Stack* ps)
{
	printf("栈中元素是：");
	int i = 0;
	for(i = 0; i < ps->top; i++)
	{
		printf("%d ",ps->arr[i]);
	}
	printf("\n");
}

//入栈操作
void push(Stack* ps,int data)
{
	if(ps->top >= ps->len)
	{
		printf("栈满了，入栈失败\n");
		return;
	}
	ps->arr[ps->top++] = data;
	//ps->top++;
}

//销毁堆栈的函数
void destroy(Stack* ps)
{
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
}

//创建堆栈的函数
Stack* create(int len)
{
	//动态申请堆栈大小
	Stack* ps = (Stack*)malloc(sizeof(Stack));
	//初始化成员
	ps->arr = (int*)malloc(len*sizeof(int));
	ps->len = len;
	ps->top = 0;
	//返回
	return ps;
}






