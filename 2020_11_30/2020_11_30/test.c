#include <stdio.h>//��������ֻ������û�ж���
#include <stdlib.h>
#include "sum.h"


//�궨����#���������ڰ�һ���������ɶ�Ӧ���ַ���
#define PRINT(FORMAT,VALUE)\
	printf("the value of "#VALUE" is "FORMAT"\n", VALUE);

// 1. ʹ�ú궨�峣��
#define SIZE 10

// 2. ʹ�ú�������������
#define and &&
#define or ||

// 3. ʹ�ú����¶������͵ı���. 
// typedef unsigned int uint;
#define uint unsigned int

// 4. �껹�����������ؼ��ֶ������
// register ��ʾ "�Ĵ���" 
// ����ؼ����Ѿ�������. 
#define reg register

// 5. �껹�ܶ���һ�δ���Ƭ��
//    �����÷��ͺ�������
//    \�ǻ���
#define CHECK(ret) if (ret == 0) { \
	printf("ִ��ʧ��\n"); \
	return 1; \
}

// 6. �껹������Ϊ "���뿪��" 
//    ���Ը���������һЩ�����ܱ�����߲�����. 
//    �������������ʹ��(һ�����)
// _CRT_SECURE_NO_WARNINGS ����һ�����뿪��
// û�������Ķ����ʱ��, VS �ͻ�����һЩ���� scanf �Ⱥ�����ȫ�����߼�
// ������궨��, ��صļ�����Ͳ���������. 
// ��μ��Ĵ����� stdio.h ��ͷ. ���Ա��������궨�嵽 stdio.h ���Ϸ�

int main(){



	//extern�ؼ���
	//�ں����ⲿ����ı��������ⲿ�������ֽ�ȫ�ֱ���
	//����������Ϊ�����������������
	//Ȼ�������ȫ�ֱ��������ļ��Ŀ�ͷ���壬��Ч�����÷�Χ��ֻ�����䶨�崦���ļ�������
	//����ڶ����֮ǰ�ĺ��������ø�ȫ�ֱ�����
	//��Ӧ��������֮ǰ�ùؼ��� extern �Ըñ��������ⲿ����������
	//��ʾ�ñ�����һ���Ѿ�������ⲿ������
	//������g_val2,������ӹؼ���extern��������䣬���뽫����
	//extern void print(char* str);
	//extern int g_val;
	//char string[10] = "abcdefg";
	//printf("%d\n", g_val);
	//printf("%d\n", g_val1);
	//extern int g_val2;
	//printf("%d\n", g_val2);
	//print(string);
	//print1(string);


	//Ԥ����
	//Ԥ�������
	//��Щ���������������õĺ�
	//Ԥ���������Ԥ�����һ���֣�������ʾ�Ķ��Ǳ���ʱ�����Ϣ������ִ��ʱ�����Ϣ
	//printf("file:%s\n", __FILE__);//���б����Դ�ļ�
	//printf("line:%d\n", __LINE__);//��ǰ������к�
	//printf("date:%s\n", __DATE__);//�ļ������������
	//printf("time:%s\n", __TIME__);//�ļ��������ʱ��
	//printf("stdc:%d\n", __STDC__);//�������Ƿ���ѭANSI C�������ѭ��ֵΪ1��������ѭ����ȻVS����ѭ


	int i = 10;
	PRINT("%d", i + 10);
	//#define PRINT(FORMAT,VALUE)\
	printf("the value of "#VALUE" is "FORMAT"\n", VALUE);
	system("pause");
	return 0;
}

int g_val2 = 2020;