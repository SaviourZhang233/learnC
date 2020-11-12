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
	printf("请输入要选择的运算\n");
	printf("1、加法\t\t2、减法\n");
	printf("3、乘法\t\t4、除法\n");
	int choice = 0;
	scanf("%d", &choice);
	printf("输入两个数\n");
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int res = p[choice](a, b);
	printf("res=%d", res);
	system("pause");
	return 0;
}