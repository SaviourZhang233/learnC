//#include <stdio.h>
//#include <stdlib.h>
//
//void bubbleSort(int num[], int len){
//	for (int i = len-1; i > 0; i--){
//		for (int j = 0; j < i ; j++){
//			if (num[j]>num[j + 1]){
//				int tmp = num[j];
//				num[j] = num[j + 1];
//				num[j + 1] = tmp;
//			}
//
//		}
//	}
//}
//
//int main(){
//	int a[10] = { 78, 14, 7, 9, 145, 75, 54, 16, 72, 46 };
//	bubbleSort(a, 10);
//	for (int i = 1; i < 10; i++){
//		printf("%d ", a[i]);
//	}
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
///*
//创建一个整形数组，完成对数组的操作
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。
//要求：自己设计以上函数的参数，返回值。
//*/
//
//void init(int num[], int len){
//	for (int i = 0; i < len; i++){
//		num[i] = 0;
//	}
//}
//
//void print(int num[], int len){
//	for (int i = 0; i < len; i++){
//		printf("%d ", num[i]);
//	}
//	printf("\n");
//}
//
//void reverse(int num[], int len){
//	int left = 0;
//	int right = len - 1;
//	while (left < right){
//		int tmp = num[left];
//		num[left] = num[right];
//		num[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//int main(){
//	int a[10] = { 78, 14, 7, 9, 145, 75, 54, 16, 72 };
//	reverse(a, 9);
//	print(a, 9);
//	init(a, 9);
//	print(a, 9);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
void swapArr(int a[], int b[], int len){
	for (int i = 0; i < len; i++){
		int tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
}

void print(int num[], int len){
	for (int i = 0; i < len; i++){
		printf("%d ", num[i]);
	}
	printf("\n");
}

int main(){
	int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int b[7] = { 7, 6, 5, 4, 3, 2, 1 };
	swapArr(a, b, 7);
	print(a, 7);
	print(b, 7);
	system("pause");
	return 0;
}