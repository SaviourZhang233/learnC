#include <stdio.h>
#include <stdlib.h>

//struct A{
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	int d : 30;
//};

//struct A{
//	char c1;
//	int i;
//	char c2;
//};
#pragma pack(1)//修改默认对齐数为1
struct S1{
	char c1;
	int i;
	char c2;
};

struct S2{
	double d;
	char c;
	int i;
};

struct S3{
	char c1;
	struct S2 s2;
	double d;
};
#pragma pack()//取消对默认对齐数的设置，还原为默认
int main(){
	//int aa[2][5] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//int *ptr1 = (int *)(&aa + 1);
	//int *ptr2 = (int *)(*(aa + 1));
	//int *ptr3 = (int *)(aa + 1);
	//printf("%d,%d,%d", *(ptr1 - 1), *(ptr2 - 1), *(ptr3 - 1));
	//struct A a1 = { 0 };
	//a1.a = 3;
	//a1.b = 31;
	//a1.c = 1023;
	//a1.d = 1073741823;
	printf("sizeof(S1) = %d\n", sizeof(struct S1));
	printf("sizeof(S2) = %d\n", sizeof(struct S2));
	printf("sizeof(S3) = %d\n", sizeof(struct S3));
	system("pause");
	return 0;
}