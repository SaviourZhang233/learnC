#include <stdio.h>
#include <stdlib.h>

//��num�����Ӵ�pillar1�ƶ���pillar2�ϣ���ת��Ϊpillar3
//����������������Ϊ��1�̣���2��...
void hanoi(int num, char pillar1, char pillar2, char pillar3){
	if (num == 1){
		printf("����1�����Ӵ�%c�ƶ���%c��\n",pillar1,pillar2);
	}
	else if (num == 2){
		printf("����1�����Ӵ�%c�ƶ���%c��\n", pillar1, pillar3);
		printf("����2�����Ӵ�%c�ƶ���%c��\n", pillar1, pillar2);
		printf("����1�����Ӵ�%c�ƶ���%c��\n", pillar3, pillar2);
	}
	else {
		hanoi(num - 1, pillar1, pillar3, pillar2);
		printf("����%d�����Ӵ�%c�ƶ���%c��\n", num, pillar1, pillar2);
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
	printf("���ƶ�����%d��\n", hanoiNumber(4));
	system("pause");
	return 0;
}

