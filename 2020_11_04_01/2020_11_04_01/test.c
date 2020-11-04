/*#include <stdio.h>

//编写一个程序，输出2~1000之间的完全数
//完全数即该数字除本身外的各因子之和正好等于该数本身
//例如：6 = 1 + 2 + 3

//写一个求出个因数的函数，将因数用累加的方法加起来，并返回该累加值；
int factor(int num) {
int ret = 0;
for (int i = 1;i < num;i++) {
if (num % i == 0) {//可被整除，说明是因数
//累加起来
ret += i;
}
}
return ret;
}

int main() {
for(int num=2;num<=1000;num++){
if(num==factor(num)){
printf("%d ",num);
}
}
return 0;
}*/

//#include <stdio.h>
/*
//在象棋算式里，不同的棋子代表不同的数，有以下算式，设计一个算法求这些棋子各代表哪些数字。
//每个数字范围为0-9，请求出各棋子所代表的数字
//        兵  炮  马  卒
//    +
//        兵  炮  车  卒
//--------------------------
//   车  卒  马  兵  卒
//输入
//无输入，按题目要求完成即可
//输出
//输出按照兵、炮、马、卒、车的顺序输出各棋子代表的数字，单纯只要数字！每个数字间用空格间隔
void f(){
int bing=1;
int pao=0;
int ma=0;
int zu=0;
int che=1;
for(;bing<=9;bing++){
for(;pao<=9;pao++){
for(;ma<=9;ma++){
for(;zu<=9;zu++){
for(;che<=9;che++){
if((zu+10*ma+100*pao+1000*che)+(zu+10*che+100*pao+1000*bing)==(zu+10*bing+100*ma+1000*zu+10000*che)){
printf("%d %d %d %d %d",bing,pao,ma,zu,che);
return;
}
}
}
}
}

}


}

int main(){
f();
return 0;
}
*/
/*
#include <stdio.h>

/*
题目描述
给定一个整数数列，数列中连续相同的最长整数序列算成一段，问数列中共有多少段？
输入

输入的第一行包含一个整数n，表示数列中整数的个数。
第二行包含n个整数a1 a2 … an，表示给定的数列，相邻的整数之间用一个空格分隔。


输出
输出一个整数，表示给定的数列有多少个段。
样例输入
8
8 8 8 0 12 12 8 0
样例输出
5
*/

//定义一个累加器，从头到尾遍历数列，如果不一样，累加器加一，返回累加结果 

/*int f(int num[],int len){
int ret=0;
int tmp=num[0];
for(int i=0;i<len;i++){
tmp=num[i];
if(tmp!=num[i+1]){
ret++;
}

}
return ret;
}


int main(){
int a[10000];
int len=0;
scanf("%d",&len);
for(int i=0;i<len;i++){
scanf("%d",&a[i]);
}
printf("%d",f(a,len));
return 0;
}
*/

//#include <stdio.h>

/*
题目描述
给定n个不同的整数，问这些数中有多少对整数，它们的值正好相差1。 （N<=1000)
输入
给定n个不同的整数，问这些数中有多少对整数，它们的值正好相差1。
输出
输出一个整数，表示值正好相差1的数对的个数。
样例输入
6
10 2 6 3 7 8
样例输出
3
*/
/*
void choice(int a[],int n){
int i,j,temp;
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
}

int f(int a[],int n){
int tmp=0;
for(int i=0;i<n-1;i++){
if(a[i+1]-a[i]==1){
tmp++;
}
}
return tmp;
}

int main(){
int num[10000];
int len=0;
scanf("%d",&len);
for(int i=0;i<len;i++){
scanf("%d",&num[i]);
}
choice(num,len);
printf("%d",f(num,len));
return 0;
}

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//题目描述
//有n个小朋友围成一圈玩游戏，小朋友从1至n编号，2号小朋友坐在1号小朋友的顺时针方向，3号小朋友坐在2号小朋友的顺时针方向，……，1号小朋友坐在n号小朋友的顺时针方向。
//游戏开始，从1号小朋友开始顺时针报数，接下来每个小朋友的报数是上一个小朋友报的数加1。若一个小朋友报的数为k的倍数或其末位数（即数的个位）为k，则该小朋友被淘汰出局，不再参加以后的报数。当游戏中只剩下一个小朋友时，该小朋友获胜。
//例如，当n = 5 k = 2时：
//1号小朋友报数1；
//2号小朋友报数2淘汰；
//3号小朋友报数3；
//4号小朋友报数4淘汰；
//5号小朋友报数5；
//1号小朋友报数6淘汰；
//3号小朋友报数7；
//5号小朋友报数8淘汰；
//3号小朋友获胜。
//给定n和k，请问最后获胜的小朋友编号为多少？
//
//数据规模和约定：对于所有评测用例，1≤n≤ 1000，1≤k≤ 9。
//
//输入
//输入一行，包括两个整数n和k，意义如题目所述
//输出
//输出一行，包含一个整数，表示获胜的小朋友编号
//样例输入
//5 2
//样例输出
//3

int f(int a[],int n,int k){
	for (int i = 1; i <= n; i++){
		a[i] = 1;
	}
	int num = 0;
	int jsq = 0;
	int noc = n;
	while (1){
		for (int i = 1; i <= n; i++){
			if (a[i] == 1){
				num++;
				if (num%k == 0){
					a[i] = 0;
					noc--;
					if (noc == 1){
						goto flag;
					}
				}
			}
		}
	}
	flag:
		for (int i = 0; i <= n; i++){
			if (a[i] == 1){
				return i;
			}
		}
	return 0;
}

int main(){
	int a[1000];
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	printf("%d", f(a, n, k));
	system("pause");
	return 0;
}







