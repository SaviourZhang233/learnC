#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	//int arr[] = { 1, 2, 3, 4 };
	//printf("%d\n", sizeof(arr)); // 16
	//printf("%d\n", sizeof(arr + 0)); // 4 求 sizeof(int*)
	//printf("%d\n", sizeof(*arr)); // 4, 求 sizeof(int)
	//printf("%d\n", sizeof(arr + 1)); // 4, 求 sizeof(int*)
	//printf("%d\n", sizeof(arr[1])); // 4, 求 sizeof(int)
	//printf("%d\n", sizeof(&arr));// 4, 求 sizeof(int(*)[4]);

	//// 先算 &arr, 得到了数组指针 int(*)[4], 再解引用, 得到了 int[4]
	//printf("%d\n", sizeof(*&arr));// 16, 求 sizeof(int[4]);
	//// 先算 *arr, arr 会隐式转正首元素的指针(int*), 解引用得到了 int
	//// 再来取地址得到了 int*
	//printf("%d\n", sizeof(&*arr));// 4, 求 sizeof(int*)

	//printf("%d\n", sizeof(&arr + 1)); // 4, 求 sizeof(int(*)[4])
	//printf("%d\n", sizeof(&arr[0])); // 4, 求 sizeof(int*)
	//printf("%d\n", sizeof(&arr[0] + 1)); // 4, 求 sizeof(int*)

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

	//// 此处的操作均是未定义行为. arr 就不是一个 "字符串" 
	//// 必须是带有 \0 的 char 数组才是字符串. 
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
	//printf("%d\n", strlen(&arr + 1)); // 类型不匹配
	//printf("%d\n", strlen(&arr)); // 6  类型不匹配
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
	//printf("%d\n", strlen(*p)); // 类型不匹配
	//printf("%d\n", strlen(p[1])); // 类型不匹配
	//printf("%d\n", strlen(&p)); // 类型不匹配. 
	//printf("%d\n", strlen(&p[1] + 1)); // 4
	//printf("%d\n", strlen(*&p)); // 6
	//printf("%d\n", strlen(&*p)); // 6

	int arr[3][4] = { 0 };
	printf("%d\n", sizeof(arr)); // 48  sizeof(int[3][4])
	printf("%d\n", sizeof(arr[0])); // 16 sizeof(int[4])
	// arr[0] int[4], 再 + 1, 就把 int[4] 转成 int* 了
	printf("%d\n", sizeof(arr[0] + 1)); // 4 sizeof(int*)
	printf("%d\n", sizeof(&arr[0] + 1)); // 4 sizeof(int(*)[4])
	printf("%d\n", sizeof(arr[0][0])); // 4 sizeof(int)
	printf("%d\n", sizeof(*arr[0])); // 4, sizeof(int)
	// arr 是二维数组 int[3][4] => int(*)[4] => * => int[4]
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