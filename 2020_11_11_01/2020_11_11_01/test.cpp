//#define N 9
//#include <stdio.h>
//#include <stdlib.h>
//
///*
//��Ŀ����
//���һ���㷨��1��2������9��˳���ܱ䣩����֮�����+��-��ʲô�������룬ʹ�ü���������100�ĳ��򣬲�������еĿ����ԡ�
//����
//������
//���
//������п�����
//������磺
//��������λ��С�����
//1+2+3-4+5+6+78+9=100
//
//1+2+34-5+67-8+9=100
//1+23-4+5+6+78-9=100
//*/
//void fun(char op[], int sum, int prevadd, int a[], int i) {
//	if (i == N) {
//		if (sum == 100) {
//			printf("%d", a[0]);
//			for (int j = 1;j < N;j++) {
//				if (op[j] != ' ')
//					printf("%c", op[j]);
//				printf("%d", a[j]);
//			}
//			printf("=100\n");
//		}
//		return;
//	}
//	op[i] = '+';
//	sum += a[i];
//	fun(op, sum, a[i], a, i + 1);
//	sum -= a[i];
//	op[i] = '-';
//	sum -= a[i];
//	fun(op, sum, -a[i], a, i + 1);
//	sum += a[i];
//	op[i] = ' ';
//	sum -= prevadd;
//	int tmp;
//	if (prevadd > 0)
//		tmp = prevadd * 10 + a[i];
//	else
//		tmp = prevadd * 10 - a[i];
//	sum += tmp;
//	fun(op, sum, tmp, a, i + 1);
//	sum -= tmp;
//	sum += prevadd;
//}
//
//
//int main() {
//	int a[N];
//	char op[N];
//	for (int i = 0;i < N;i++) {
//		a[i] = i + 1;
//	}
//	fun(op, a[0], a[0], a, 1);
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
///*
//��Ŀ����
//��һ����n������������a������Ԫ�ؾ�����ͬ����������Ԫ�ص�ȫ���С�
//���մ�С������ֵ������ (n < 10)
//����
//��һ��ΪN
//�ڶ���ΪN������
//���
//���ȫ���򣬰��ֵ���������������ÿһ��һ��ȫ����������ÿ���������������м��ÿո����
//��������
//3
//1 2 3
//�������
//1 2 3
//1 3 2
//2 1 3
//2 3 1
//3 1 2
//3 2 1
//*/
//
//
//void swap(int& x, int& y) {
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//
//void dispasolution(int a[], int n) {
//	for (int i = 0;i < n ;i++) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
//void dfs(int a[], int n, int i) {
//	if (i >= n) {
//		dispasolution(a, n);
//	}
//	else {
//		for (int j = i;j < n;j++) {
//			swap(a[i], a[j]);
//			dfs(a, n, i + 1);
//			swap(a[i], a[j]);
//		}
//	}
//}
//
//int main() {
//	int a[100];
//	int n;
//	scanf("%d", &n);
//	for (int i = 0;i < n;i++) {
//		scanf("%d", &a[i]);
//	}
//	dfs(a, n, 0);
//	return 0;
//}

/*
��Ŀ����
	��n�������ֱ�Ϊ{w1��w2������wn}����Ʒ�����ǵļ�ֵ�ֱ�Ϊ{v1��v2������vn}������һ������ΪW�ı�����
	��ƴ���Щ��Ʒ��ѡȡһ������Ʒ����ñ����ķ�����ÿ����ƷҪôѡ��Ҫô��ѡ�У�Ҫ��ѡ�е���Ʒ�����ܹ��ŵ������У����������������ƾ������ļ�ֵ��Ѱ�������պ�ΪW�ķ���
����
��һ�а���һ�� n �� w����ʾ��Ʒ�����ͱ�������  n <=50
������n��ÿ���������֣���ʾÿ����Ʒ�������ͼ�ֵ
���
���������װ�ص�����ֵ
��������
4 6
5 4
3 4
2 3
1 1
�������
8
*/

#include<iostream>
#include<cstring> 
using namespace std;
int n;
double c;
double v[100];
double w[100];
double cw = 0.0;
double cv = 0.0;
double MAX_put = 0.0;
double ratio[100];//���� 
int order[100];
int put[100];


void knapsack()//����ֵ�������� 
{
	int i, j;
	int temporder = 0;
	double temp = 0.0;

	for (i = 1;i <= n;i++)
		ratio[i] = v[i] / w[i];
	for (i = 1;i <= n - 1;i++)
	{
		for (j = i + 1;j <= n;j++)
			if (ratio[i] < ratio[j])//���ݱ��ʽ������򣬾����ñ�ֵ������Ʒ 
			{
				temp = ratio[i];
				ratio[i] = ratio[i];
				ratio[j] = temp;

				temporder = order[i];
				order[i] = order[j];
				order[j] = temporder;

				temp = v[i];
				v[i] = v[j];
				v[j] = temp;

				temp = w[i];
				w[i] = w[j];
				w[j] = temp;
			}
	}
}

void backtrack(int i)
{
	double bound(int i);
	if (i > n)//i>n˵����Ʒȫ���ܱ����� 
	{
		MAX_put = cv;
		return;
	}
	if (cw + w[i] <= c)//δ���Ｋ������ 
	{
		cw += w[i];
		cv += v[i];
		put[i] = 1;
		backtrack(i + 1);
		cw -= w[i];
		cv -= v[i];
	}
	if (bound(i + 1) > MAX_put)
	{
		put[i] = 0;
		backtrack(i + 1);
	}
}

double bound(int i)
{
	double leftw = c - cw;
	double b = cv;
	while (i <= n && w[i] <= leftw)
	{
		leftw -= w[i];
		b += v[i];
		i++;
	}
	if (i <= n)
		b += v[i] / w[i] * leftw;
	return b;

}


int main()
{
	int i;
	//cout << "��������Ʒ����������������";
	cin >> n >> c;
	for (i = 1;i <= n;i++)
	{
		//cout << "�������" << i << "����Ʒ�����ͼ�ֵ��";
		cin >> w[i] >> v[i];
		order[i] = i;
	}
	knapsack();
	backtrack(1);
	cout << "����ֵΪ:" << MAX_put;
	//cout << "���뱳������Ʒ���Ϊ��";
	//for (i = 1;i <= n;i++)
	//{
	//	if (put[i] == 1)
	//		cout << order[i] << " ";
	//}
	return 0;
}