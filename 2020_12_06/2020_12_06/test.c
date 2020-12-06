#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����ʵ��int atoi (const char* str);
/*
������˵����atoi() ������ɨ����� str �ַ���������ǰ��Ŀհ��ַ�������ո�tab�����ȣ���
ֱ���������ֻ��������Ųſ�ʼ��ת�����������������ֻ��ַ�������ʱ('\0')�Ž���ת��������������ء�

������ֵ������ת�������������
��� str ����ת���� int ���� str Ϊ���ַ�������ô������ 0��
*/
//�ж�c�Ƿ�Ϊ'1' '2' '3' '4' '5' '6' '7' '8' '9' '0'
//�Ƿ���1�����Ƿ���0
int func1(char* c){
	char c1[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	for (int i = 0; i < 10; i++){
		if (*c == c1[i]){
			return 1;
		}
	}
	return 0;
}

int myAtoi(const char* str){
	char* p = str;
	int flag = 0;
	double ret = 0;
	for (; *p != '\0'; p++){
		//if (*p == '-' || *p == '+' || func1(p) == 1){
		//	flag = 1;
		//}
		if (*p == '-'&&flag==0){
			flag = 1;
			for (p = p + 1; func1(p) == 1; p++){
				ret = ret * 10 + *p - '0';
			}
			if (ret >= INT_MIN&&ret <= INT_MAX){
				return (int)(-ret);
			}
		}
		else if (*p == '+'&&flag == 0){
			flag = 1;
			for (p = p + 1; func1(p) == 1; p++){
				ret = ret * 10 + *p - '0';
			}
			if (ret >= INT_MIN&&ret <= INT_MAX){
				return (int)ret;
			}
		}
		else if (func1(p) == 1 && flag == 0){
			flag = 1;
			ret = *p - '0';
			for (p = p + 1; func1(p) == 1; p++){
				ret = ret * 10 + *p - '0';
			}
			if (ret >= INT_MIN&&ret <= INT_MAX){
				return (int)ret;
			}
		}
	}
	return 0;
}


/*
char *strncat(char *dest, const char *src, size_t n) 
�� src ��ָ����ַ���׷�ӵ� dest ��ָ����ַ����Ľ�β��ֱ�� n �ַ�����Ϊֹ��
dest -- ָ��Ŀ�����飬�����������һ�� C �ַ��������㹻����׷�Ӻ���ַ�������������Ŀ��ַ���
src -- Ҫ׷�ӵ��ַ�����
n -- Ҫ׷�ӵ�����ַ�����
*/

char* myStrncat(char *dest, const char *src, size_t n){
	assert(dest != NULL&&src != NULL);
	char* str1 = dest;
	char* str2 = src;
	while (*str1 != '\0'){
		str1++;
	}
	int i = 0;
	for ( ; i < n; i++){
		*(str1 + i) = *(str2 + i);
	}
	*(str1+i) = '\0';
	return dest;
}

char* myStrncpy(char *dest, const char *src, size_t n){
	assert(dest != NULL&&src != NULL);
	char* str1 = dest;
	char* str2 = src;
	int i = 0;
	while (i < n&& *(str2 + i) != '\0') {
		*(str1 + i) = *(str2 + i);
		i++;
	}
	*(str1 + i) = '\0';
	return dest;
}

/*
Ѱ�ҵ���
һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
��дһ�������ҳ�������ֻ����һ�ε����֡�
*/
/*
�ҳ�һ��ֻ���ֹ�һ�ε����ֵ����⴦����������һ�����ְ��������е����ֶ����һ��
������������ε���û�����ص���������ô������������ֶ�ֻ������һ�Σ�
��ô��˵õ���Ӧ�������������Ľ���������������϶�����0��Ҫ��Ȼ��ȫ������ˣ���
��������һ������һλ��һ���ҳ�ֵΪ1��һλ������һλ��ֵ�������Ϊ���顣����1 2 3 4 1 2��
�����Ľ��Ӧ����3^4�õ���111����ô�����һλ�����ˡ����������λ����ô��һλ��1����1 3 1��
��0����2 4 2�����������������Ϊ1��ĳһλ�ֵ��飬������������ѯ����һ���ֱ���������.
�������������������ֱ�����������������ҵ�����������
*/
void findSingleDog(int arr[],int num){
	int sum = 0;
	for (int i = 0; i < num; i++){
		sum ^= arr[i];
	}
	int a = 0;
	while ((sum&(1 << a)) == 0){
		a++;
	}
	int arr1[50] = { 0 };
	int arr2[50] = { 0 };
	int j1 = 0;
	int j2 = 0;
	for (int i = 0; i < num; i++){
		if ((arr[i]&(1<<a))==0){
			arr1[j1] = arr[i];
			j1++;
		}
		else{
			arr2[j2] = arr[i];
			j2++;
		}
	}
	int ret = 0;
	for (int i = 0; i < j1; i++){
		ret ^= arr1[i];
	}
	printf("%d\n",ret);
	ret = 0;
	for (int i = 0; i < j2; i++){
		ret ^= arr2[i];
	}
	printf("%d\n", ret);
}

int main(){
	//char str[] = "abcdefgh \t 2147483648ds23-jsd\n";//int�����ֵΪ2147483647
	//char str1[] = "ashfjhjshhf \nhfhs123768fjksdj shf";
	//int ret =  myAtoi(str);
	//int ret1 = myAtoi(str1);
	//printf("%d\n", ret);
	//printf("%d\n", ret1);
	//char str1[10] = "abcd";
	//char str2[5] = "1234";
	//printf("%s\n", myStrncpy(str1, str2, 3));
	int arr[10] = { 1, 1, 2, 2, 3, 3, 4, 4, 52, 60 };
	findSingleDog(arr, 10);
	system("pause");
	return 0;
}