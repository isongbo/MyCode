//使用顺序存储结构实现堆栈的操作
#include "stack.h"

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



