//#include <stdio.h>
//#include <stdlib.h>
//
///*
//дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
//arr��һ������һά���顣
//*/
//void printArr(int arr[], int len){
//	int* p = arr;
//	for (int i = 0; i < len; i++){
//		printf("%d ", *(p + i));
//	}
//}
//
//
//int main(){
//	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
//	printArr(a, 7);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//дһ����������������һ���ַ��������ݡ�

void f(char* str){
	char* left = str;
	char* right = str + strlen(str) - 1;
	while (left < right){
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int main(){
	char str[] = "abcdefg";
	f(str);
	for (int i = 0; i < 7; i++){
		printf("%c ", str[i]);
	}
	system("pause");
	return 0;
}
