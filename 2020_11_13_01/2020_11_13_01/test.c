//#include <stdio.h>
//#include <stdlib.h>
//
//void test1(int a){
//	printf("����\n");
//}
//
//int main(){
//	typedef void(*P)(int a);
//	P p = test1;
//	p(1);
//	(*p)(1);
//	P p1 = &test1;
//	p1(1);
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int add(int a, int b){
//	return a + b;
//}
//
//int sub(int a, int b){
//	return a - b;
//}
//
//int mul(int a, int b){
//	return a*b;
//}
//
//int divi(int a, int b){
//	return a / b;
//}
//
//int main(){
//	printf("������Ҫѡ�������\n");
//	printf("1���ӷ�\t\t2������\n");
//	printf("3���˷�\t\t4������\n");
//	int choice = 0;
//	scanf("%d", &choice);
//	printf("����������\n");
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int res = 0;
//	if (choice == 1){
//		res = add(a, b);
//	}
//	else if (choice == 2){
//		res = sub(a, b);
//	}
//	else if (choice == 3){
//		res = mul(a, b);
//	}
//	else if (choice == 4){
//		res = divi(a, b);
//	}
//	printf("res=%d", res);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

typedef int(*Cmp)(int a, int b);

void bubbleSort2(int arr[], int size, Cmp cmp) {
	for (int bound = 0; bound < size; bound++) {
		for (int cur = size - 1; cur > bound; cur--) {
			// cur - 1 ��λ����ǰ
			// cur ��λ���ں�
			// ������� cmp �ĺ�������ֵ Ϊ 1
			if (cmp(arr[cur - 1], arr[cur]) == 1) {
				int tmp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
				arr[cur] = tmp;
			}
		}
	}
}

// ���������������
// a Ӧ���� b ֮ǰ, ���ú������� -1
// a Ӧ���� b ֮��, ���ú������� 1
// a �� b һ����, �ͷ��� 0
int less(int a, int b) {
	if (a == b) {
		return 0;
	}
	if (a < b) {
		return -1;
	}
	return 1;
}

int main(){
	int arr[] = { 9, 5, 2, 7 };
	bubbleSort2(arr, 4, less);
	for (int i = 0; i < 4; i++) {
		printf("%d\n", arr[i]);
	}
	system("pause");
	return 0;
}