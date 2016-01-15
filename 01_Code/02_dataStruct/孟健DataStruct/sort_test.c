
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*冒泡排序*/
void bubble_sort(int *data, int size)
{
	int i = 0;
	int j = 0;
	
	for(i=0; i<size-1; i++)
	{
		/*默认序列有序*/
		int ordered = 1;

		for(j=0; j<size-1-i; j++)
		{
			if(data[j+1] < data[j])
			{
				int swap = data[j];
				data[j] = data[j+1];
				data[j+1] = swap;
				
				/*标识序列为无序*/
				ordered = 0;
			}
		}
		if(ordered == 1)
		{
			break;
		}
	}
}

/*插入排序*/
void insert_sort(int *data, int size)
{
	int i = 0;
	int j = 0;

	for(i=1; i<size; i++)
	{
		int inserted = data[i];
		/*把i位置的值和前面i-1数据进行排序*/
		for(j=i; j>0; j--)
		{
			if(inserted <(data[j-1]))
			{
				/*后移大数*/
				data[j] = data[j-1];
			}
			else
			{
				break;
			}
		}
		/*如果发生了数据后移*/
		if(j != i)
		{
			/*取出的元素插入合适的位置*/
			data[j] = inserted;
		}


	}
}

/*选择排序
 不断的将子序列中“最小”数据放在“第一个”位置
 */
void select_sort(int *data, int size)
{
	int i = 0;
	
	for(i=0; i<size-1; i++)
	{
		/*min是最小元素的下标*/
		int min = i;

		int j = 0;
		for(j=i+1; j<size; j++)
		{
			if(data[j] < data[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			int swap = data[i];
			data[i] = data[min];
			data[min] = swap;
		}
	}
}
/*快速排序,算法实现过程参考PPT 63页*/
void quick_sort(int data[],  int left, int right)
{
	int p = (left+right)/2;
	int pivot = data[p];
	
	int i = left;
	int j = right;

	while(i<j)
	{
		for(; i<p && pivot>=data[i]; i++);
		
		if(i<p)
		{
			data[p] = data[i];
			p = i;
		}

		for(; j>p && pivot<=data[j]; j--);
		if(j>p)
		{
			data[p] = data[j];
			p = j;
		}
	}
	data[p] = pivot;

	if(p-left >1)
	{
		quick_sort(data, left, p-1);
	}
	if(right-p >1)
	{
		quick_sort(data, p+1, right);
	}


}

/*外部合并排序*/
void outer_merge(int data1[], int size1, int data2[], 
		         int size2, int data3[])
{
	int i = 0;
	int j = 0;
	int k = 0;

	while(1)
	{
		if(i<size1 && j<size2)
		{
			if(data2[j]<data1[i])
			{
				data3[k++] = data2[j++];
			}
			else
			{
				data3[k++] = data1[i++];
			}
		}
		else if(i<size1)
		{
			data3[k++] = data1[i++];
		}
		else if(j<size2)
		{
			data3[k++] = data2[j++];
		}
		else
		{
			break;
		}

	}

}

/*内部合并排序*/
void inner_merge(int data[], int left, int mid, int right)
{
	int size = (right - left + 1) * sizeof(int);
	int *data3 = malloc(size);

	outer_merge(data+left, mid-left+1,
			    data+mid+1, right-mid,
				data3);

	memcpy(data+left, data3, size);

	free(data3);
	data3 = NULL;
}

/*归并排序 参考PPT 68页*/
void merge_sort(int data[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right)/2;
		
		merge_sort(data, left, mid);
		merge_sort(data, mid+1,right);

		inner_merge(data, left, mid, right);
	}
}


int main(void)
{
	/*初始化产生随机数的初始值*/
	srand(time(NULL));
	int data[10];
	int i = 0;
	int size = sizeof(data) /sizeof(data[0]);

	for(; i<10; i++)
	{
		data[i] = rand() % 100;
		printf("%2d ", data[i]);
	}
	printf("\n");

	//bubble_sort(data, size);
	//insert_sort(data,size);
	//select_sort(data, size);
	//quick_sort(data,0,size-1);
	merge_sort(data, 0, size-1);

	for(i=0; i<size; i++)
	{
		printf("%2d ", data[i]);
	}
	printf("\n");

	return 0;
}

