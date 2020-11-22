#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	default: b = 0;
//		break;
//	case 1: b = 30;
//		break;
//	case 2: b = 20;
//		break;
//	case 3: b = 16;
//		break;
//	
//	}
//	return b;
//}

//int binarySearch(int arr[], int len, int num){
//	int left = 0;
//	int right = len - 1;
//	int mid = (left + right) / 2;
//	while (left <= right){
//		mid = (left + right) / 2;
//		if (arr[mid] > num){
//			right = mid - 1;
//		}
//		if (arr[mid] < num){
//			left = mid + 1;
//		}
//		if (arr[mid] == num){
//			return mid;
//		}
//	}
//	return -1;
//}

//void chengfakoujue(){
//	for (int i = 1; i <= 9; i++){
//		for (int j = 1; j <= i; j++){
//			printf("%d*%d=%d\t", i, j, i*j);
//		}
//		printf("\n");
//	}
//}

//int menu(){
//	printf("***********************\n");
//	printf("1.开始游戏\n2.结束游戏\n");
//	printf("请选择你的操作\n");
//	printf("***********************\n");
//	int choice = 0;
//	scanf("%d", &choice);
//	return choice;
//}
//
//void guessNumber(){
//	int num = rand() % 100 + 1;
//	int yourGuess = 0;
//	while (1){
//		printf("请输入你猜测的数字：");
//		scanf("%d", &yourGuess);
//		if (yourGuess > num){
//			printf("你猜大了\n");
//		}
//		if (yourGuess < num){
//			printf("你猜小了\n");
//		}
//		if (yourGuess == num){
//			printf("你猜对了\n");
//			return;
//		}
//	}
//}
//将一句话的单词进行倒置，标点符号不变
//例如I am a pig.输出为pig. a am I
void func1(char arr[]){
	char a[100][100] = {"\0"};//二维数组，每一行用来存放每一个单词
	char* p1 = arr;
	char* p2 = arr;
	int i = 99;
	while (*p1 != '\0'){
		if (*p1 == ' '){
			strncpy(a[i], p2 , p1 - p2);
			p1++;
			p2 = p1;
			i--;
		}
		p1++;
	}
	strncpy(a[i], p2 , p1 - p2);
	for (; i <= 98; i++){
		printf("%s ", a[i]);
	}
	printf("%s", a[99]);
}

void func2(char arr[]){
	char string[10] = "\0";//为了不改变原来字符串的值，所以新创建一个
	int len = strlen(arr);
	strcpy(string , arr);
	char* p = string + len - 1;
	for (; p > string; p--){
		if (*p == ' '){
			printf("%s ", p + 1);
			*p = '\0';
		}
	}
	printf("%s", p);
}

int main(){
	char string[] = "I am a pig.";
	func1(string);
	printf("\n");
	func2(string);
	//srand((unsigned)time(0));
	/*int a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	printf("%d\n", binarySearch(a, 8, 4));
	printf("%d\n", binarySearch(a, 8, 2));
	printf("%d\n", binarySearch(a, 8, 7));
	printf("%d\n", binarySearch(a, 8, 10));*/
	/*printf("%d\n", func(2));
	printf("%d\n", func(0));*/
	//chengfakoujue();
	//switch (menu()){
	//	case 1:
	//		guessNumber();
	//		break;
	//	case 2:
	//		break;
	//}
	system("pause");
	return 0;
}