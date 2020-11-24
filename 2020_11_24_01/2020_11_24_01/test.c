#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//要求写一个函数，将字符串中的空格替换为 % 20。
//样例： “abc defgx yz” 转换成 “abc%20defgx%20yz”
char* func1(char* str){
	char str1[100] = "\0";
	for (char* p = str; *p != '\0'; p++){
		if (*p == ' '){//找到空格
			strcpy(str1, p + 1);//把空格后的字符串先拷贝到str1中
			strcpy(p, "%20");//在空格的位置拷贝上%20
			p += 3;//指针后移3位
			strcpy(p, str1);//在p的位置在拷贝上str1
		}
	}
	return str;
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
	if ((p1 > p2) && (p2 + num > p1)){//重叠，倒叙存放
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
	char a[100] = "abc defgx yz";
	func1(a);
	printf("%s\n", a);
	char str3[10] = "abcdef";
	myMemmove(str3 + 2, str3, 6);
	printf("%s", str3 + 2);
	system("pause");
	return 0;
}