#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int global = 2019;//ȫ�ֱ���
//void test()
//{
//	//static���ξֲ�����
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
	//int local = 2018;//�ֲ�����
	////���涨���global�᲻�������⣿
	//int global = 2020;//�ֲ�����
	//printf("global = %d\n", global);//2020
	//char arr1[] = "bit";
	//char arr2[] = { 'b', 'i', 't' };
	//char arr3[] = { 'b', 'i', 't', '\0' };
	//printf("%s\n", arr1);
	//printf("%s\n", arr2);
	//printf("%s\n", arr3);
	//�������ӡ��c:\code\test.c
	//printf("c:\\code\\test.c");
	//����1������Ļ�ϴ�ӡһ��������'����ô����
	//����2������Ļ�ϴ�ӡһ���ַ������ַ�����������һ��˫���š�����ô����
	//printf("'");
	//printf("\"");
	//printf("%d\n", strlen("abcdef"));//6
	// \32��������һ��ת���ַ�
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