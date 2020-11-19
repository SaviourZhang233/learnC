//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
///*
//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//*/
//
//char* StrliftRound(char arr[], int num) {
//	int len = strlen(arr);
//	char str1[1024] = { 0 };
//	strncpy(str1, arr, num);
//	strcpy(arr, arr + num);
//	strcat(arr, str1);
//	return arr;
//}
//
//int main() {
//	char a[] = "ABCD";
//	char* p = StrliftRound(a, 1);
//	printf("%s\n", p);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

/*
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1
给定s1=abcd和s2=ACBD，返回0.
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC
*/
int isStrLift(char str1[], char str2[]) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2) {
		return 0;
	}
	for (int i = 1;i < len1;i++) {
		if (strncmp(str1, str2 + len1 - i, i) == 0) {
			if (strncmp(str1 + i, str2, len1 - i) == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	return 0;
}


int main() {
	char str1[] = "abcde";
	char str2[] = "deabc";
	char str3[] = "cedba";
	char str4[] = "cdeaa";
	printf("str1是否为str2的左旋？%d\n", isStrLift(str1, str2));
	printf("str1是否为str3的左旋？%d\n", isStrLift(str1, str3));
	printf("str1是否为str4的左旋？%d\n", isStrLift(str1, str4));
	system("pause");
	return 0;
}