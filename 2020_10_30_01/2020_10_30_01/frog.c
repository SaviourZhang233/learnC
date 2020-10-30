#include <stdio.h>
#include <stdlib.h>

//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
//求该青蛙跳上一个n级的台阶总共有多少种跳法。
int frog(int n){
	if (n == 1){
		return 1;
	}
	else{
		return 2 * frog(n - 1);
	}
}

int main(){
	int num = frog(10);
	printf("跳上10阶台阶共有%d种跳法\n", num);
	system("pause");
	return 0;
}