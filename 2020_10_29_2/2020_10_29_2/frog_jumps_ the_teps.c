#include <stdio.h>
#include <stdlib.h>

//һֻ����һ�ο������� 1 ��̨�ף�Ҳ��������2 ����
//�����������һ��n ����̨���ܹ��ж�����������
int howManyWays(int numOfSteps){//����̨�׵ĸ�������������ֲ�ͬ������
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
	printf("С������%d��̨�׹���%d������\n", numOfSteps, num);
	system("pause");
	return 0;
}