#include <stdio.h>
#include <stdlib.h>

//一只青蛙一次可以跳上 1 级台阶，也可以跳上2 级。
//求该青蛙跳上一个n 级的台阶总共有多少种跳法。
int howManyWays(int numOfSteps){//给出台阶的个数，求出多少种不同的跳法
	if (numOfSteps == 1){
		return 1;
	}
	else if (numOfSteps == 2){
		return 2;
	}
	else{
		return howManyWays(numOfSteps - 1) + howManyWays(numOfSteps - 2);
	}
}

int main(){
	int numOfSteps = 10;
	int num = 0;
	num = howManyWays(numOfSteps);
	printf("小青蛙跳%d个台阶共有%d种跳法\n", numOfSteps, num);
	system("pause");
	return 0;
}