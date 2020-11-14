#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	//int arr[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(arr)); // 16
	//printf("%d\n", sizeof(arr + 0)); // 4 �� sizeof(int*)
	//printf("%d\n", sizeof(*arr)); // 4, �� sizeof(int)
	//printf("%d\n", sizeof(arr + 1)); // 4, �� sizeof(int*)
	//printf("%d\n", sizeof(arr[1])); // 4, �� sizeof(int)
	//printf("%d\n", sizeof(&arr));// 4, �� sizeof(int(*)[4]);

	//// ���� &arr, �õ�������ָ�� int(*)[4], �ٽ�����, �õ��� int[4]
	//printf("%d\n", sizeof(*&arr));// 16, �� sizeof(int[4]);
	//// ���� *arr, arr ����ʽת����Ԫ�ص�ָ��(int*), �����õõ��� int
	//// ����ȡ��ַ�õ��� int*
	//printf("%d\n", sizeof(&*arr));// 4, �� sizeof(int*)

	//printf("%d\n", sizeof(&arr + 1)); // 4, �� sizeof(int(*)[4])
	//printf("%d\n", sizeof(&arr[0])); // 4, �� sizeof(int*)
	//printf("%d\n", sizeof(&arr[0] + 1)); // 4, �� sizeof(int*)

	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//printf("%d\n", sizeof(arr)); // 6, sizeof(char[6])
	//printf("%d\n", sizeof(arr + 0)); // 4, sizeof(char*)
	//printf("%d\n", sizeof(*arr)); // 1, sizeof(char)
	//printf("%d\n", sizeof(arr + 1)); // 4
	//printf("%d\n", sizeof(arr[1]));// 1, sizeof(char)
	//printf("%d\n", sizeof(&arr));// 4, sizeof(char(*)[6])
	//printf("%d\n", sizeof(*&arr)); // 6, sizeof(char[6])
	//printf("%d\n", sizeof(&*arr));// 4, sizeof(char*)
	//printf("%d\n", sizeof(&arr[1] + 1)); // 4, sizeof(char*)
	//printf("%d\n", sizeof(&arr + 1)); // 4, sizeof(char(*)[6]);

	//// �˴��Ĳ�������δ������Ϊ. arr �Ͳ���һ�� "�ַ���" 
	//// �����Ǵ��� \0 �� char ��������ַ���. 
	//printf("%d\n", strlen(arr));
	//printf("%d\n", strlen(arr + 0));
	//printf("%d\n", strlen(*arr));
	//printf("%d\n", strlen(arr[1]));
	//printf("%d\n", strlen(&arr));
	//printf("%d\n", strlen(&arr + 1));
	//printf("%d\n", strlen(&arr[0] + 1));

	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr)); // 7, sizeof(char[7]);
	//printf("%d\n", sizeof(arr + 0)); // 4, sizeof(char*)
	//printf("%d\n", sizeof(*arr)); // 1, sizeof(char)
	//printf("%d\n", sizeof(arr[1])); // 1, sizeof(char)
	//printf("%d\n", sizeof(&arr[0] + 1)); // 4, sizeof(char*)
	//printf("%d\n", sizeof(&arr)); // 4 sizeof(char(*)[7])
	//printf("%d\n", sizeof(*&arr)); // 7 sizeof(char[7])
	//printf("%d\n", sizeof(&*arr)); // 4 sizeof(char*)
	//printf("%d\n", sizeof(&arr + 1)); // 4 sizeof(char(*)[7])

	//printf("%d\n", strlen(arr)); // 6
	//printf("%d\n", strlen(arr + 1)); // 5
	//printf("%d\n", strlen(&arr + 1)); // ���Ͳ�ƥ��
	//printf("%d\n", strlen(&arr)); // 6  ���Ͳ�ƥ��
	//printf("%d\n", strlen(&arr[0])); // 6
	//printf("%d\n", strlen(*&arr)); // 6
	//printf("%d\n", strlen(&*arr)); // 6
	//printf("%d\n", strlen(&arr[1] + 1));// 4

	//char* p = "abcdef";
	//printf("%d\n", sizeof(p)); // 4 sizeof(char*)
	//printf("%d\n", sizeof(p + 1)); // 4 sizeof(char*)
	//printf("%d\n", sizeof(*p)); // 1 sizeof(char)
	//printf("%d\n", sizeof(p[0])); // 1 sizeof(char)
	//printf("%d\n", sizeof(&p)); // 4 sizeof(char**)
	//printf("%d\n", sizeof(&p[1] + 1)); // 4 sizeof(char*)
	//printf("%d\n", sizeof(*&p)); // 4 sizeof(char*)
	//printf("%d\n", sizeof(&*p)); // 4 sizeof(char*)

	//printf("%d\n", strlen(p)); // 6
	//printf("%d\n", strlen(p + 1)); // 5
	//printf("%d\n", strlen(*p)); // ���Ͳ�ƥ��
	//printf("%d\n", strlen(p[1])); // ���Ͳ�ƥ��
	//printf("%d\n", strlen(&p)); // ���Ͳ�ƥ��. 
	//printf("%d\n", strlen(&p[1] + 1)); // 4
	//printf("%d\n", strlen(*&p)); // 6
	//printf("%d\n", strlen(&*p)); // 6

	int arr[3][4] = { 0 };
	printf("%d\n", sizeof(arr)); // 48  sizeof(int[3][4])
	printf("%d\n", sizeof(arr[0])); // 16 sizeof(int[4])
	// arr[0] int[4], �� + 1, �Ͱ� int[4] ת�� int* ��
	printf("%d\n", sizeof(arr[0] + 1)); // 4 sizeof(int*)
	printf("%d\n", sizeof(&arr[0] + 1)); // 4 sizeof(int(*)[4])
	printf("%d\n", sizeof(arr[0][0])); // 4 sizeof(int)
	printf("%d\n", sizeof(*arr[0])); // 4, sizeof(int)
	// arr �Ƕ�ά���� int[3][4] => int(*)[4] => * => int[4]
	printf("%d\n", sizeof(*arr)); // 16 sizeof(int[4])
	// arr + 1 => int(*)[4] => * => int[4]
	printf("%d\n", sizeof(*(arr + 1))); // 16 sizeof(int[4])
	// arr => int[3][4] => int(*)[4] => * => int[4] => +1 => int*
	printf("%d\n", sizeof(*arr + 1));
	// arr[0] => int[4] => & => int(*)[4] => +1 => int(*)[4]
	printf("%d\n", sizeof(&arr[0] + 1)); // 4 sizeof(int(*)[4])
	// arr[0] => int[4] => +1  => int*  => * => int
	printf("%d\n", sizeof(*(arr[0] + 1)));// 4
	system("pause");
	return 0;
}