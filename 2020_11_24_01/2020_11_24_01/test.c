#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ҫ��дһ�����������ַ����еĿո��滻Ϊ % 20��
//������ ��abc defgx yz�� ת���� ��abc%20defgx%20yz��
char* func1(char* str){
	char str1[100] = "\0";
	for (char* p = str; *p != '\0'; p++){
		if (*p == ' '){//�ҵ��ո�
			strcpy(str1, p + 1);//�ѿո����ַ����ȿ�����str1��
			strcpy(p, "%20");//�ڿո��λ�ÿ�����%20
			p += 3;//ָ�����3λ
			strcpy(p, str1);//��p��λ���ڿ�����str1
		}
	}
	return str;
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
	if ((p1 > p2) && (p2 + num > p1)){//�ص���������
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