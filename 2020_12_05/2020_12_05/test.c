#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char *GetMemory(void){
//	char p[] = "hello world";
//	return p;
//}
//void Test(void){
//	char *str = NULL;
//	str = GetMemory();//GetMemory()���ؾֲ������ĵ�ַ����δ������Ϊ
//	printf(str);
//}
////����Test�ᷢ��ʲô�����
////����GetMemory()���ý���֮��p���ͷţ�����printf�������������
//
//void GetMemory1(char *p){
//	p = (char *)malloc(100);
//}
//void Test1(void){
//	char *str = NULL;
//	GetMemory1(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
////����Test1�ᷢ��ʲô�����
////�����������ڴ�й¶
////���������ܻ��������ʹGetMemory�������أ�str��ȻΪNULL
////GetMemory�����޷���malloc���ٵ�100���ֽڴ�����

//void test(){
//	int *p = (int *)malloc(100);
//	p++;
//	free(p);//p����ָ��̬�ڴ����ʼλ��//}

int main(){
	//char* p = NULL;
	//p = (char*)malloc(0);
	//if (p == NULL){
	//	printf("����ʧ��\n");
	//}
	//else{
	//	printf("����ɹ�\n");//�ɼ�malloc���Է���0�ֽڴ�С�Ŀռ�
	//	free(p);
	//}

	//char* p1 = NULL;
	//p1 = (char*)malloc(1);
	//free(p1);
	//free(p1);//�ٴ��ͷű���

	//char a = 'a';
	//char* p2 = &a;
	//free(p2);//����free�Ƕ�̬����ı�����δ������Ϊ

	//free(NULL);//free�ͷ�NULL����ָ��NULL��ָ��ʱʲô��������û�д�

	//int* i = NULL;
	//i = (int*)malloc(4);
	//printf("0x%p\n", i);
	//free(i);
	//printf("0x%p\n", i);//���ͷ�ǰ��ָ��Ŀռ�����ͬ��

	//void* calloc(size_t num,size_t size) 
	////����num��size��С�Ŀռ䣬���Ұѿռ��ÿ���ֽڳ�ʼ��Ϊ0
	////void* memset(void* str, int c, size_t n) 
	////�����ַ� c��һ���޷����ַ��������� str ��ָ����ַ�����ǰ n ���ַ���
	////calloc=malloc+memset
	//int* i1 = NULL;
	//i1 = (int*)malloc(4);
	//printf("%d\n", *i1);//δ������Ϊ
	//int* i2 = NULL;
	//i2 = (int*)calloc(1, 4);
	//printf("%d\n", *i2);//���0
	//memset(i1, 0, 4);
	//printf("%d\n", *i1);//���0
	//free(i1);
	//free(i2);

	//Test();

	//char str1[10] = "hehehe";
	//printf(str1);
	//printf("\n");//����
	//int a = 10;
	////printf(a);//���У��ᱨ��

	//int num = 0;
	//printf("������Ԫ�ظ�����");
	//scanf("%d", &num);
	//int arr[num];
	//int num = 0;
	//printf("������Ԫ�صĸ�����");
	//scanf("%d", &num);
	//int* arr =(int*)malloc(sizeof(int)*num);
	//if (arr != NULL){//�ж��Ƿ����ɹ�
	//	printf("����ɹ�");
	//	//����
	//}

	//int num = 5;
	//int* p1 = (int*)calloc(num, sizeof(int));
	//int* p2 = (int*)malloc(sizeof(int)*num);
	//if (p1 != NULL){//����ɹ�
	//	printf("calloc�������:");
	//	for (int i = 0; i < num; i++){
	//		printf("%d\t", p1[i]);
	//	}
	//	printf("\n");
	//}
	//if (p2 != NULL){//����ɹ�
	//	printf("malloc�������:");
	//	for (int i = 0; i < num; i++){
	//		printf("%d\t", p2[i]);
	//	}
	//	printf("\n");
	//}
	//free(p1);
	//free(p2);

	int *ptr = malloc(100);
	if (ptr != NULL){
		//ҵ����
	}
	else{
		printf("����ʧ��\n");
	}
	//��չ����
	//����1
	//ptr = realloc(ptr, 1000);//����������(�������ʧ�ܻ���Σ�)
	/*
	�����ԣ��������ʧ���ˣ�realloc �᷵�� NULL��
	��ô����ζ������malloc�����Ŀռ�ĵ�ַ����ʧ
	����ǰ�õ�ַ�����ָ�� ptr �У�����������ڴ�й©��
	*/
	//���ô���2
	//����2
	int*p = NULL;
	p = realloc(ptr, 1000);
	if (p != NULL)
	{
		ptr = p;
	}
	//ҵ����
	free(ptr);

	system("pause");
	return 0;
}