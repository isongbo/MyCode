//sbrk函数的使用
#include <stdio.h>
#include <unistd.h>

int main(void)
{
		//sbrk函数返回所申请内存的首地址
		void* p1 = sbrk(4);
		void* p2 = sbrk(4);
		void* p3 = sbrk(4);
		void* p4 = sbrk(4);
		printf("p1 = %p,p2 = %p,p3 = %p,p4 = %p\n",p1,p2,p3,p4);

		//获取当前的内存末尾位置
		void* cur = sbrk(0);
		printf("cur = %p\n",cur);//p4+4地址
		
		printf("------------------------\n");
		void* p5 = sbrk(-4);
		printf("p5 = %p\n",p5);//上面的cur地址
		cur = sbrk(0);
		printf("cur = %p\n",cur);//p4地址

		printf("-----------------------\n");
		void* p6 = sbrk(-8);
		printf("p6 = %p\n",p6);//上面的cur地址
		cur = sbrk(0);
		printf("cur = %p\n",cur);//p2的地址
		
		printf("------------------------\n");
		printf("pid = %d\n",getpid());
		getchar();
		sbrk(4093);
		printf("分配了4093个字节，超过了一个内存页的大小\n");
		getchar();
		//释放了一个字节内存
		sbrk(-1);
		printf("释放了1个字节的内存，刚好一个内存页的大小\n");
		getchar();
		return 0;
}
