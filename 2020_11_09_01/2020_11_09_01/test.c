#include <stdio.h>
#include <stdlib.h>

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ
int drinkGasWater(int money){
	int numOfGasWat = money/1;
	int numOfBottle = numOfGasWat;
	while (numOfBottle >= 2){
		numOfGasWat += numOfBottle / 2;
		numOfBottle = numOfBottle % 2 + numOfBottle / 2;
	}
	return numOfGasWat;
}


int main(){
	printf("%dԪ�ܺ�%dƿ����\n", 20, drinkGasWater(20));
	system("pause");
	return 0;
}