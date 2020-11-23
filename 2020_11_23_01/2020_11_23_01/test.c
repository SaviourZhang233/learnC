#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//将一句话的单词倒置，标点符号不变。
//例如I am a pig.
//变化为pig. a am I
void func(char string[]){
	char s[100] = "\0";//定义一个新的字符串，防止修改原字符串的内容
	char a[100][100] = { '\0' };//这个二维数组的每一行用来存放一个单词
	strcpy(s, string);
	char* p = strtok(s, " ");
	if (p == NULL){//说明string中没有空格
		printf("%s",s);
		return;
	}
	//strcpy(a[99], p);
	//int i = 98;
	//while (p != NULL){
	//	p = strtok(NULL, " ");
	//	strcpy(a[i], p);
	//	i--;
	//}
	int i = 99;
	do{ 
		strcpy(a[i], p);
		p = strtok(NULL, " ");
		i--;
	} while (p != NULL);
	for (; i <= 98; i++){
		printf("%s ", a[i]);
	}
	printf("%s", a[99]);
	return;
}

//从sour的位置开始复制num个字节的字符，复制到dest中
//返回值为dest
//dest和sour不能重叠
void* myMemcpy(void* dest, const void* sour, size_t num){
	char* p1 = (char*)dest;
	char* p2 = (char*)sour;
	for (size_t i = 0; i < num; i++){
		*(p1 + i) = *(p2 + i);
	}
	return dest;
}

//从sour的位置开始复制num个字节的字符，复制到dest中
//返回值为dest
//dest和sour可以重叠
void* myMemmove(void* dest, const void* sour, size_t num){
	char* p1 = (char*)dest;
	char* p2 = (char*)sour;
	if ((p1 > p2)&&(p2 + num > p1)){//重叠，倒叙存放
		for (size_t i = num - 1; i >= 0; i--) {
			*(p1 + i) = *(p2 + i);
		}
		return dest;
	}
	else{
		myMemcpy(dest, sour, num);
		return dest;
	}
}

int main(){
	//char str1[] = "I am a pig.";
	//func(str1);
	//printf("\n");
	//char str2[] = "pig.";
	//func(str2);
	//char str1[] = "abcde";
	//char str2[6] = "\0";
	//printf("%s", myMemcpy(str2, str1, 6));
	//int arr1[4] = { 1, 2, 3, 4 };
	//int arr2[4] = { 0, 0, 0, 0 };
	//myMemcpy(arr2, arr1, 4);
	//for (int i = 0; i < 4; i++){
	//	printf("%d ", arr2[i]);
	//}
	char str3[10] = "abcdefghi";
	myMemmove(str3 + 2, str3, 6);
	printf("%s", str3 + 2);
	system("pause");
	return 0;
}