/*
   结构体演示
   */
#include <stdio.h>
#include <string.h>
/*struct phone {
	char manu[20];
	float price;
};
typedef struct phone  phone;*/
typedef struct /*phone*/ {
	char manu[20];
	float price;
} phone;
//#define   phone         struct phone
int main() {
	//struct phone ph;
	phone iphone6 = {}, ph = {}, ph1 = {"Apple", 5000.0f};
	phone *p_phone = NULL;
	strcpy(iphone6.manu, "Apple");
	iphone6.price = 5000.0f;
	printf("厂家是%s\n", iphone6.manu);
	printf("价格是%g\n", iphone6.price);
	p_phone = &iphone6;
	printf("厂家是%s\n", p_phone->manu);
	printf("价格是%g\n", p_phone->price);
	ph = iphone6;
	printf("厂家是%s\n", ph.manu);
	printf("价格是%g\n", ph.price);
	printf("厂家是%s\n", ph1.manu);
	printf("价格是%g\n", ph1.price);
	return 0;
}




