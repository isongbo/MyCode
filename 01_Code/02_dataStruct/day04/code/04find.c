//二分查找的实现
#include <stdio.h>

int find(int arr[],int left,int right,int data)
{
	//保证元素的个数大于等于1
	if(left <= right)
	{
		//1.计算中间元素,与目标元素进行比较
		int p = (left+right)/2;
		//1.1 如果中间元素与目标元素相等，则直接返回下标
		if(data == arr[p])
		{
			return p;
		}
		//1.2 如果中间元素小于目标元素,则去右边查找，重复上述过程
		else if(arr[p] < data)
		{
			return find(arr,p+1,right,data);
		}
		//1.3 如果中间元素大于目标元素，则去左边查找，重复上述过程
		else
		{
			return find(arr,left,p-1,data);
		}
	}
	return -1;//查找失败
}

int main(void)
{
	int arr[9] = {1,2,3,4,5,6,7,8,9};
	int res = find(arr,0,8,8);
	// 7
	printf("查找到的元素下标是：%d\n",res);
	return 0;
}
