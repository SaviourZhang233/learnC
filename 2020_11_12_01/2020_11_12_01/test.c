#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
	return a + b;
}

int sub(int a, int b){
	return a - b;
}

int mul(int a, int b){
	return a*b;
}

int divi(int a, int b){
	return a / b;
}




int main(){
	typedef int(*P)(int, int);
	P p[5] = {
		NULL,
		add,
		sub,
		mul,
		divi
	};
	printf("������Ҫѡ�������\n");
	printf("1���ӷ�\t\t2������\n");
	printf("3���˷�\t\t4������\n");
	int choice = 0;
	scanf("%d", &choice);
	printf("����������\n");
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int res = p[choice](a, b);
	printf("res=%d", res);
	system("pause");
	return 0;
}