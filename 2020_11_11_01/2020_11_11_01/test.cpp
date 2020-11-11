//#define N 9
//#include <stdio.h>
//#include <stdlib.h>
//
///*
//题目描述
//设计一个算法在1，2，…，9（顺序不能变）数字之间插入+或-或什么都不插入，使得计算结果总是100的程序，并输出所有的可能性。
//输入
//无输入
//输出
//输出所有可能性
//输出例如：
//（按照首位大小输出）
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
//题目描述
//有一个含n个整数的数组a，所有元素均不相同，求其所有元素的全排列。
//按照从小到大的字典序输出 (n < 10)
//输入
//第一行为N
//第二行为N个数字
//输出
//输出全排序，按字典序输出，输出按照每一行一次全排序的情况，每个序列两个数字中间用空格隔开
//样例输入
//3
//1 2 3
//样例输出
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
题目描述
	有n个重量分别为{w1，w2，…，wn}的物品，它们的价值分别为{v1，v2，…，vn}，给定一个容量为W的背包。
	设计从这些物品中选取一部分物品放入该背包的方案，每个物品要么选中要么不选中，要求选中的物品不仅能够放到背包中，而且满足重量限制具有最大的价值。寻找重量刚好为W的方案
输入
第一行包括一个 n 和 w，表示物品数量和背包容量  n <=50
接下来n行每行两个数字，表示每个物品的重量和价值
输出
输出背包可装载的最大价值
样例输入
4 6
5 4
3 4
2 3
1 1
样例输出
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
double ratio[100];//比率 
int order[100];
int put[100];


void knapsack()//按比值进行排序 
{
	int i, j;
	int temporder = 0;
	double temp = 0.0;

	for (i = 1;i <= n;i++)
		ratio[i] = v[i] / w[i];
	for (i = 1;i <= n - 1;i++)
	{
		for (j = i + 1;j <= n;j++)
			if (ratio[i] < ratio[j])//根据比率进行排序，尽量拿比值最大的物品 
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
	if (i > n)//i>n说明物品全都能被放入 
	{
		MAX_put = cv;
		return;
	}
	if (cw + w[i] <= c)//未到达极限容量 
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
	//cout << "请输入物品数量及背包容量：";
	cin >> n >> c;
	for (i = 1;i <= n;i++)
	{
		//cout << "请输入第" << i << "件物品重量和价值：";
		cin >> w[i] >> v[i];
		order[i] = i;
	}
	knapsack();
	backtrack(1);
	cout << "最大价值为:" << MAX_put;
	//cout << "放入背包的物品编号为：";
	//for (i = 1;i <= n;i++)
	//{
	//	if (put[i] == 1)
	//		cout << order[i] << " ";
	//}
	return 0;
}