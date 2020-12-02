#include <stdio.h>
#include <stdlib.h>

void sWap(void* left, void* right, int size){
	while (size){
		char tmp = *(char*)left;
		*(char*)left = *(char*)right;
		*(char*)right = tmp;
		size--;
		((char*)left)++;
		((char*)right)++;
	}
}
int Cmp1(const void* e1, const void* e2){//回调函数1，升序
	return (*(int*)e1) > (*(int*)e2);
}
int Cmp2(const void* e1, const void* e2){//回调函数1，降序
	return (*(int*)e1) < (*(int*)e2);
}
void myQsort(void* left, int len, int size, int(*Cmp)(void*, void*)){
	int i = 0;
	int j = 0;
	for (i = 0; i < len - 1; i++){//循环的趟数
		for (j = 0; j < len - i - 1; j++){//每趟比较的次数
			if (Cmp((char*)left + j * size, (char*)left + (j + 1) * size) > 0){//如果满足条件就进行交换
				sWap((char*)left + j * size, (char*)left + (j + 1) * size, size);
			}
		}
	}
}

int intCmp(const void *a, const void *b){
	return *(int *)a - *(int *)b; 
}

int doubleCmp(const void *a, const void * b){
	return (*(double *)a>*(double *)b ? 1 : -1);
}

int charCmp(const void *a, const void *b){
	return *(char *)a - *(char *)b;
}

struct A{
	int a : 2;
	int b : 5;
	int c : 10;
	int d : 30;
};

int main() {
	//int arr[7] = { 1, 3, 2, 4, 3, 6, 4 };
	////qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), Cmp);
	//myQsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), Cmp1);
	//int i = 0;
	//printf("升序：");
	//for (i = 0; i < 7; i++){
	//	printf("%d ", arr[i]);
	//}
	//printf("\n");
	//myQsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), Cmp2);
	//printf("降序：");
	//for (i = 0; i < 7; i++){
	//	printf("%d ", arr[i]);
	//}
	//char c[7] = { 'a', 'w', 'd', 'e', 'v', 't', 'b' };
	//int i[7] = { 34, 455, 451, 45, 1, 75, 41 };
	//double d[7] = { 12.23, 434.34, 34.34, 42.01, 223, 12.0, 23.04 };
	//qsort(c, 7, 1, charCmp);
	//qsort(i, 7, 4, intCmp);
	//qsort(d, 7, 8, doubleCmp);

	//for (int j = 0; j < 7; j++){
	//	printf("%c ", c[j]);
	//}
	//printf("\n");

	//for (int j = 0; j < 7; j++){
	//	printf("%d ", i[j]);
	//}
	//printf("\n");

	//for (int j = 0; j < 7; j++){
	//	printf("%.2f ", d[j]);
	//}
	//printf("\n");

	struct A a1;
	printf("%d\n", sizeof(a1));

	system("pause");
	return 0;
}

