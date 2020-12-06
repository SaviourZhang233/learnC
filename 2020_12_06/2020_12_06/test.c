#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//自我实现int atoi (const char* str);
/*
【函数说明】atoi() 函数会扫描参数 str 字符串，跳过前面的空白字符（例如空格，tab缩进等），
直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。

【返回值】返回转换后的整型数；
如果 str 不能转换成 int 或者 str 为空字符串，那么将返回 0。
*/
//判断c是否为'1' '2' '3' '4' '5' '6' '7' '8' '9' '0'
//是返回1，不是返回0
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
把 src 所指向的字符串追加到 dest 所指向的字符串的结尾，直到 n 字符长度为止。
dest -- 指向目标数组，该数组包含了一个 C 字符串，且足够容纳追加后的字符串，包括额外的空字符。
src -- 要追加的字符串。
n -- 要追加的最大字符数。
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
寻找单身狗
一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
编写一个函数找出这两个只出现一次的数字。
*/
/*
找出一个只出现过一次的数字的问题处理方法就是找一个数字把里面所有的数字都异或一遍
，利用异或两次等于没异或的特点来处理。那么如果有两个数字都只出现了一次，
那么如此得到的应该是两个数异或的结果。首先这个结果肯定不是0（要不然就全都配对了），
所以里面一定至少一位是一。找出值为1的一位，以这一位的值将结果分为两组。例如1 2 3 4 1 2，
异或完的结果应该是3^4得到的111，那么随便找一位就行了。例如找最低位，那么这一位是1的有1 3 1，
是0的有2 4 2，由于是利用异或结果为1的某一位分的组，所以两个待查询数字一定分别在两组中.
所以再找两个变量，分别异或两组数，即可找到这两个数。
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
	//char str[] = "abcdefgh \t 2147483648ds23-jsd\n";//int的最大值为2147483647
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