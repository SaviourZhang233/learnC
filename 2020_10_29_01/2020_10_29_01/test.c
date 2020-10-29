#include <stdio.h>
#include <stdlib.h>

//将num个盘子从pillar1移动到pillar2上，中转柱为pillar3
//盘子依上自下依次为第1盘，第2盘...
void hanoi(int num, char pillar1, char pillar2, char pillar3){
	if (num == 1){
		printf("将第1个盘子从%c移动到%c上\n",pillar1,pillar2);
	}
	else if (num == 2){
		printf("将第1个盘子从%c移动到%c上\n", pillar1, pillar3);
		printf("将第2个盘子从%c移动到%c上\n", pillar1, pillar2);
		printf("将第1个盘子从%c移动到%c上\n", pillar3, pillar2);
	}
	else {
		hanoi(num - 1, pillar1, pillar3, pillar2);
		printf("将第%d个盘子从%c移动到%c上\n", num, pillar1, pillar2);
		hanoi(num - 1, pillar2, pillar3, pillar1);
	}
}

int hanoiNumber(int n){
	if (n == 1){
		return 1;
	}
	else if (n == 2){
		return 3;
	}
	else{
		return 2 * hanoiNumber(n - 1) + 1;
	}
}

int main(){
	int numberOfPlates = 4;
	char pillarA = 'a';
	char pillarB = 'b';
	char pillarC = 'c';
	hanoi(numberOfPlates, pillarA, pillarB, pillarC);
	printf("共移动盘子%d次\n", hanoiNumber(4));
	system("pause");
	return 0;
}

