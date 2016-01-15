//使用顺序存储结构实现各种操作
#include "arr.h"

//定义数组存放元素,规定元素值为0时表示无效元素
int arr[20] = {0};
//定义变量记录数组下标
int pos = 0;
//定义变量记录元素个数
int num = 0;

//编写函数实现删除指定位置的元素
void del(int top)
{
	//1.判断下标是否有效
	if(top < 0 || top > 19 || 0 == num)
	{
		printf("删除元素失败\n");
		return; //break;
	}
	//2.移动后续元素对指定位置进行覆盖
	int i = 0;
	for(i = top; i < 19; i++)
	{
		arr[i] = arr[i+1];
	}
	//3.将最后一个位置元素置为0
	arr[i] = 0;
	num--;
}

//编写函数实现查找指定元素的下标
int find(int data)
{
	int i = 0;
	for(i = 0; i < 20; i++)
	{
		if(arr[i] == data)
		{
			//printf("元素%d已找到,下标为:%d\n",data,i);
			//break;
			return i;
		}
	}
	return -1;//表示失败
}

//编写函数实现修改指定位置的元素为新元素值
void modify(int top,int newData)
{
	//判断坐标是否合法，元素是否有效
	if(top < 0 || top > 19 || 0 == arr[top])
	{
		printf("修改元素失败\n");
		return;
	}
	arr[top] =  newData;
}

//编写函数实现随机访问功能
void randNum(void)
{
	//1.设置随机种子
	srand(time(0));
	//2.生成随机的下标
	int n = rand()%20;
	//3.根据随机下标打印具体的元素值
	printf("随机访问的元素是：%d,下标是：%d\n",arr[n],n);
}

//编写函数遍历数组中所有元素
void travel(void)
{
	int i = 0;
	printf("数组中的有效元素：");
	for(i = 0; i < 20; i++)
	{
		if(0 != arr[i])
		{
			printf("%d ",arr[i]);
		}
	}
	printf("\n");
}

//编写函数实现向数组指定位置插入指定元素
void insert(int top,int data)
{
	//1.判断下标是否合法
	if(top < 0 || top >= 20 || 20 == num)
	{
		printf("下标不合法,插入元素%d失败\n",data);
		return;
	}
	//2.判断指定位置是否有元素
	//2.1 如果没有有效元素，则直接赋值
	if(0 == arr[top])
	{
		arr[top] = data;
		num++;
		return;
	}
	//2.2 如果有,则将存在的元素后移
	int i = 0;
	for(i = 19; i > top; i--)
	{
		arr[i] = arr[i-1];
	}
	arr[top] = data;
	num++;
}







