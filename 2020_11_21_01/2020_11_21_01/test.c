#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int global = 2019;//全局变量
//void test()
//{
//	//static修饰局部变量
//	static int i = 0;
//	i++;
//	printf("%d ", i);
//}


int main(){
	//printf("%d\n", sizeof(char));//1
	//printf("%d\n", sizeof(short));//2
	//printf("%d\n", sizeof(int));//4
	//printf("%d\n", sizeof(long));//4
	//printf("%d\n", sizeof(long long));//8
	//printf("%d\n", sizeof(float));//4
	//printf("%d\n", sizeof(double));//8
	//printf("%d\n", sizeof(long double));//8
	//int local = 2018;//局部变量
	////下面定义的global会不会有问题？
	//int global = 2020;//局部变量
	//printf("global = %d\n", global);//2020
	//char arr1[] = "bit";
	//char arr2[] = { 'b', 'i', 't' };
	//char arr3[] = { 'b', 'i', 't', '\0' };
	//printf("%s\n", arr1);
	//printf("%s\n", arr2);
	//printf("%s\n", arr3);
	//在命令窗打印出c:\code\test.c
	//printf("c:\\code\\test.c");
	//问题1：在屏幕上打印一个单引号'，怎么做？
	//问题2：在屏幕上打印一个字符串，字符串的内容是一个双引号“，怎么做？
	//printf("'");
	//printf("\"");
	//printf("%d\n", strlen("abcdef"));//6
	// \32被解析成一个转义字符
	//printf("%d\n", strlen("c:\test\328\test.c"));//14
	/*int i = 0;
	for (i = 0; i<10; i++)
	{
		test();
	}*/
	//int i = 1;
	//while (i <= 10)
	//{
	//	if (i == 5)
	//		continue;
	//	printf("%d ", i);
	//	i = i + 1;
	//}
	/*int i = 1;
	while (i <= 10)
	{
		i = i + 1;
		if (i == 5)
			continue;
		printf("%d ", i);
	}*/
	int ch = 0;
	while ((ch = getchar()) != EOF)
		putchar(ch);
	system("pause");
	return 0;
}