//使用顺序存储结构实现堆栈的操作
#include <stdio.h>
#include <stdlib.h>

//定义堆栈的数据类型
typedef struct Stack
{
	//int arr[5];
	int* arr;//保存数组的首地址
	int len;//保存数组的长度
	int top;//保存数组的下标
}Stack;

//创建堆栈的函数
Stack* create(int len);
//销毁堆栈的函数
void destroy(Stack* ps);
//入栈操作
void push(Stack* ps,int data);
//遍历
void print(Stack* ps);
//计算栈中元素的个数 size
int size(Stack* ps);
//判断栈是否为满 isfull
int isfull(Stack* ps);
//判断栈是否为空 isempty
int isempty(Stack* ps);
//出栈操作  pop
int pop(Stack* ps);
//查看栈顶元素
int peek(Stack* ps);

int main(void)
{
	Stack* ps = create(5);
	push(ps,11);
	print(ps); // 11
	push(ps,22);
	print(ps); // 11 22
	push(ps,33);
	print(ps); // 11 22 33
	push(ps,44);
	print(ps); // 11 22 33 44
	push(ps,55);
	print(ps); // 11 22 33 44 55
	push(ps,66); //入栈失败 

	printf("-----------------------\n");
	printf("栈中元素个数是：%d\n",size(ps));
	printf("%s\n",isempty(ps)?"栈空了":"栈没有空");
	printf("%s\n",isfull(ps)?"栈满了":"栈没有满");
	printf("出栈的元素是：%d\n",pop(ps));
	print(ps); // 11 22 33 44
	printf("栈顶元素是：%d\n",peek(ps));
	print(ps); // 11 22 33 44

	destroy(ps);
	return 0;
}

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






