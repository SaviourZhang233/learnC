#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char *GetMemory(void){
//	char p[] = "hello world";
//	return p;
//}
//void Test(void){
//	char *str = NULL;
//	str = GetMemory();//GetMemory()返回局部变量的地址，是未定义行为
//	printf(str);
//}
////调用Test会发生什么情况？
////由于GetMemory()调用结束之后p被释放，所以printf极大可能有问题
//
//void GetMemory1(char *p){
//	p = (char *)malloc(100);
//}
//void Test1(void){
//	char *str = NULL;
//	GetMemory1(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
////调用Test1会发生什么情况？
////上面代码存在内存泄露
////上面代码可能会崩溃，即使GetMemory函数返回，str依然为NULL
////GetMemory函数无法把malloc开辟的100个字节带回来

//void test(){
//	int *p = (int *)malloc(100);
//	p++;
//	free(p);//p不再指向动态内存的起始位置//}

int main(){
	//char* p = NULL;
	//p = (char*)malloc(0);
	//if (p == NULL){
	//	printf("分配失败\n");
	//}
	//else{
	//	printf("分配成功\n");//可见malloc可以分配0字节大小的空间
	//	free(p);
	//}

	//char* p1 = NULL;
	//p1 = (char*)malloc(1);
	//free(p1);
	//free(p1);//再次释放报错

	//char a = 'a';
	//char* p2 = &a;
	//free(p2);//不能free非动态申请的变量，未定义行为

	//free(NULL);//free释放NULL或者指向NULL的指针时什么都不做，没有错

	//int* i = NULL;
	//i = (int*)malloc(4);
	//printf("0x%p\n", i);
	//free(i);
	//printf("0x%p\n", i);//被释放前后指向的空间是相同的

	//void* calloc(size_t num,size_t size) 
	////申请num个size大小的空间，并且把空间的每个字节初始化为0
	////void* memset(void* str, int c, size_t n) 
	////复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符。
	////calloc=malloc+memset
	//int* i1 = NULL;
	//i1 = (int*)malloc(4);
	//printf("%d\n", *i1);//未定义行为
	//int* i2 = NULL;
	//i2 = (int*)calloc(1, 4);
	//printf("%d\n", *i2);//输出0
	//memset(i1, 0, 4);
	//printf("%d\n", *i1);//输出0
	//free(i1);
	//free(i2);

	//Test();

	//char str1[10] = "hehehe";
	//printf(str1);
	//printf("\n");//可以
	//int a = 10;
	////printf(a);//不行，会报错

	//int num = 0;
	//printf("请输入元素个数：");
	//scanf("%d", &num);
	//int arr[num];
	//int num = 0;
	//printf("请输入元素的个数：");
	//scanf("%d", &num);
	//int* arr =(int*)malloc(sizeof(int)*num);
	//if (arr != NULL){//判断是否分配成功
	//	printf("分配成功");
	//	//操作
	//}

	//int num = 5;
	//int* p1 = (int*)calloc(num, sizeof(int));
	//int* p2 = (int*)malloc(sizeof(int)*num);
	//if (p1 != NULL){//分配成功
	//	printf("calloc分配情况:");
	//	for (int i = 0; i < num; i++){
	//		printf("%d\t", p1[i]);
	//	}
	//	printf("\n");
	//}
	//if (p2 != NULL){//分配成功
	//	printf("malloc分配情况:");
	//	for (int i = 0; i < num; i++){
	//		printf("%d\t", p2[i]);
	//	}
	//	printf("\n");
	//}
	//free(p1);
	//free(p2);

	int *ptr = malloc(100);
	if (ptr != NULL){
		//业务处理
	}
	else{
		printf("分配失败\n");
	}
	//扩展容量
	//代码1
	//ptr = realloc(ptr, 1000);//这样可以吗？(如果申请失败会如何？)
	/*
	不可以，如果分配失败了，realloc 会返回 NULL，
	那么将意味着我们malloc出来的空间的地址将丢失
	（以前该地址存放在指针 ptr 中），将会造成内存泄漏。
	*/
	//改用代码2
	//代码2
	int*p = NULL;
	p = realloc(ptr, 1000);
	if (p != NULL)
	{
		ptr = p;
	}
	//业务处理
	free(ptr);

	system("pause");
	return 0;
}