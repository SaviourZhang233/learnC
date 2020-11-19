//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
///*
//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
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
дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 =AABCD��s2 = BCDAA������1
����s1=abcd��s2=ACBD������0.
AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA
AABCD����һ���ַ��õ�DAABC
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
	printf("str1�Ƿ�Ϊstr2��������%d\n", isStrLift(str1, str2));
	printf("str1�Ƿ�Ϊstr3��������%d\n", isStrLift(str1, str3));
	printf("str1�Ƿ�Ϊstr4��������%d\n", isStrLift(str1, str4));
	system("pause");
	return 0;
}