//#include <stdio.h>
//#include <stdlib.h>
//
///*
//���ʵ�֣�����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//��������:
//1999 2299
//�������:7
//*/
//
////�Ƚ���������λ��򣬲�ͬ��λΪ1����ͬ��λΪ0
////�ڼ�¼�õ��Ķ��������м���1
////����Ϊ ���õ��������κͣ�������4λΪ����0001��0010��0100��1000�� & ����
////���������0�����λΪ1
//int f(int m, int n){
//	int a = m^n;
//	int b = 1;
//	int ret = 0;
//	while (b != 0){
//		if ((a&b) != 0) {
//			ret++;
//		}
//		b <<= 1;
//	}
//	return ret;
//}
//
//int main(){
//	printf("%d\n", f(1999, 2299));
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
////��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
//void f(int a){
//	printf("ż��λ������");
//	for (int i = (sizeof(int)* 8 - 1); i >= 1; i -= 2){
//		printf("%d ", (a >> i) & 1);
//	}
//	printf("\n");
//	printf("����λ������");
//	for (int i = (sizeof(int)* 8 - 2); i >= 0; i -= 2){
//		printf("%d ", (a >> i) & 1);
//	}
//}
//
//int main(){
//	f(10);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
///*
//дһ���������ز����������� 1 �ĸ�����
//���磺 15    0000 1111    4 �� 1
//*/
//
////����Ϊ �����������κͣ�������4λΪ����0001��0010��0100��1000�� & ����
////���������0�����λΪ1
//int f(int a){
//	int ret = 0;
//	int b = 1;
//	while (b != 0){
//		if ((a&b) != 0) {
//			ret++;
//		}
//		b <<= 1;
//	}
//	return ret;
//}
//
//
//int main(){
//	printf("%d\n", f(15));
//	system("pause");
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//����������ʱ������������������������
//����a^b^a == b�������
int main(){
	int a = 0;
	int b = 0;
	printf("������������a��b\n");
	scanf("%d %d", &a, &b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("���������Ϊa=%d��b=%d", a, b);
	system("pause");
	return 0;
}