//使用链式存储结构实现栈的基本操作
#include "stack.h"

int main(void)
{
	//定义栈类型的变量
	Stack stack;
	stack.list.head = NULL;
	push(&stack,11);
	print(&stack); // 11
	push(&stack,22);
	print(&stack); // 22 11
	push(&stack,33);
	print(&stack); // 33 22 11
	
	printf("-------------------\n");
	printf("栈中的元素个数是：%d\n",size(&stack));
	printf("%s\n",isfull(&stack)?"栈满了":"栈没有满");
	printf("%s\n",isempty(&stack)?"栈空了":"栈没有空");
	printf("栈顶元素是：%d\n",peek(&stack));
	printf("出栈元素是：%d\n",pop(&stack));
	print(&stack);
	return 0;
}

