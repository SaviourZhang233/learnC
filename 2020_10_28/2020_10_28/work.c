#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
//
////����:һ������1����Ȼ��������1���������⣬���ܱ�������Ȼ����������
//int isPrime(int number){//����ֵΪ1����������Ϊ0����������
//	int res = 1;
//	if (number == 0 || number == 1){
//		res = 0;
//	}
//	else{
//		for (int i = 2; i <= (int)(sqrt(number)); i++){
//			if (number%i == 0){
//				res = 0;
//				break;
//			}
//		}
//	}
//	return res;
//}
//
//int main(){
//	for (int i = 100; i <= 200; i++){
//		if (isPrime(i) == 1){
//			printf("%d ", i);
//		}
//	}
//	system("pause");
//	return 0;
//}
//void swap(int *p1, int *p2){
//	int tmp = 0;
//	tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//int main(){
//	int a = 10;
//	int b = 20;
//	swap(&a, &b);
//	printf("a=%d,b=%d\n", a, b);
//	system("pause");
//	return 0;
//}

//void printMulTable(int line){
//	for (int i = 1; i <= line; ++i){
//		for (int j = 1; j <= i; ++j){
//			printf("%d*%d=%d\t", j, i, j*i);
//		}
//		printf("\n");
//	}
//}
//
//int main(){
//	int input;
//	printf("�����ӡ���˼��ĳ˷���");
//	scanf("%d", &input);
//	printMulTable(input);
//	system("pause");
//	return 0;
//}

//void printEachDigit(int number){
//	if (number < 9){
//		printf("%d ", number);
//	}
//	else{
//		printEachDigit(number / 10);
//	}
//	printf("%d ", number % 10);
//}
//int main(){
//	int a = 1234;
//	printEachDigit(a);
//	system("pause");
//	return 0;
//}
//int fac1(int n){//�ǵݹ�
//	int res = 1;
//	for (int i = 1; i <= n; i++){
//		res *= i;
//	}
//	return res;
//}
//
//int fac2(int n){//�ݹ�
//	if (n == 1){
//		return 1;
//	}
//	else{
//		return n*fac2(n - 1);
//	}
//}
//
//int main(){
//	int n = 10;
//	printf("�ǵݹ�10!=%d\n", fac1(10));
//	printf("  �ݹ�10!=%d\n", fac2(10));
//	system("pause");
//	return 0;
//}

//int myStrlen1(char arr[]){//�ǵݹ�
//	int len = 0;
//	while (arr[len] != '\0'){
//		len++;
//	}
//	return len;
//}
//
//int myStrlen2(char arr[]){//�ݹ�
//	if (*arr == '\0'){
//		return 0;
//	}
//	else{
//		return 1 + myStrlen2(arr + 1);
//	}
//}
//
//int main(){
//	char arr[] = "abcdefg";
//	printf("�ǵݹ�arr.len=%d\n", myStrlen1(arr));
//	printf("  �ݹ�arr.len=%d\n", myStrlen2(arr));
//	system("pause");
//	return 0;
//}

//void reverse_string(char* string){
//	if (*string == '\0'){
//
//	}
//	else{
//		reverse_string(1 + string);
//	}
//	printf("%c ", *string);
//}
//
//int main(){
//	char string[] = "abcde";
//	reverse_string(string);
//	system("pause");
//	return 0;
//}

//int DigitSum(int n){
//	if (n < 10){
//		return n;
//	}
//	else{
//		return n % 10 + DigitSum(n / 10);
//	}
//}
//
//int main(){
//	int i = 1729;
//	printf("%d\n", DigitSum(i));
//	system("pause");
//	return 0;
//}

//int pow(int n, int k){
//	if (k == 1){
//		return n;
//	}
//	else{
//		return n*pow(n, k - 1);
//	}
//}
//
//int main(){
//	int n = 3;
//	int k = 4;
//	printf("%d��%d�η�Ϊ%d\n", n, k, pow(n, k));
//	system("pause");
//	return 0;
//}

int fibonacci(int n){
	if (n == 1){
		return 1;
	}
	else if (n == 2){
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main(){
	int input = 0;
	printf("������ڼ���쳲�������\n");
	scanf("%d", &input);
	printf("���Ϊ:%d\n", fibonacci(input));
	system("pause");
	return 0;
}