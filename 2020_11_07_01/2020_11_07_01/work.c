//#include <stdio.h>
//#include <stdlib.h>
//
///*
//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子:
//1999 2299
//输出例子:7
//*/
//
////先将两个数按位异或，不同的位为1，相同的位为0
////在记录得到的二进制数有几个1
////方法为 将得到的数依次和（这里以4位为例）0001，0010，0100，1000做 & 运算
////结果不等于0，则该位为1
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
////获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
//void f(int a){
//	printf("偶数位置序列");
//	for (int i = (sizeof(int)* 8 - 1); i >= 1; i -= 2){
//		printf("%d ", (a >> i) & 1);
//	}
//	printf("\n");
//	printf("奇数位置序列");
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
//写一个函数返回参数二进制中 1 的个数。
//比如： 15    0000 1111    4 个 1
//*/
//
////方法为 将该数数依次和（这里以4位为例）0001，0010，0100，1000做 & 运算
////结果不等于0，则该位为1
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

//不允许创建临时变量，交换两个整数的内容
//利用a^b^a == b这个性质
int main(){
	int a = 0;
	int b = 0;
	printf("请输入两个数a，b\n");
	scanf("%d %d", &a, &b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("交换后的数为a=%d，b=%d", a, b);
	system("pause");
	return 0;
}