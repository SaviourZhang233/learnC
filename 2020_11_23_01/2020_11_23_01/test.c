#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//��һ�仰�ĵ��ʵ��ã������Ų��䡣
//����I am a pig.
//�仯Ϊpig. a am I
void func(char string[]){
	char s[100] = "\0";//����һ���µ��ַ�������ֹ�޸�ԭ�ַ���������
	char a[100][100] = { '\0' };//�����ά�����ÿһ���������һ������
	strcpy(s, string);
	char* p = strtok(s, " ");
	if (p == NULL){//˵��string��û�пո�
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

//��sour��λ�ÿ�ʼ����num���ֽڵ��ַ������Ƶ�dest��
//����ֵΪdest
//dest��sour�����ص�
void* myMemcpy(void* dest, const void* sour, size_t num){
	char* p1 = (char*)dest;
	char* p2 = (char*)sour;
	for (size_t i = 0; i < num; i++){
		*(p1 + i) = *(p2 + i);
	}
	return dest;
}

//��sour��λ�ÿ�ʼ����num���ֽڵ��ַ������Ƶ�dest��
//����ֵΪdest
//dest��sour�����ص�
void* myMemmove(void* dest, const void* sour, size_t num){
	char* p1 = (char*)dest;
	char* p2 = (char*)sour;
	if ((p1 > p2)&&(p2 + num > p1)){//�ص���������
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