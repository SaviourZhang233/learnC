#include <stdio.h>
#include <stdlib.h>

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水
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
	printf("%d元能喝%d瓶饮料\n", 20, drinkGasWater(20));
	system("pause");
	return 0;
}