#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 9
#define MAX_COL 9
#define MAX_MINE_NUM 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�˵�����
int menu(){
	printf("--------------\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.�˳���Ϸ\n");
	printf("--------------\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//��ʼ�����ŵ�ͼ
void initMap(char playerMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			playerMap[row][col] = '*';
		}
	}
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			mineMap[row][col] = '0';
		}
	}
	//�������10����
	int mineNum = 0;
	while (mineNum<MAX_MINE_NUM){
		int row = rand() % 9;
		int col = rand() % 9;

		if (mineMap[row][col] == '0'){
			mineMap[row][col] = '1';
			mineNum++;
		}
	}
}

//��ӡ��ͼ
void printMap(char theMap[MAX_ROW][MAX_COL]){
	printf("  |");
	for (int col = 0; col < MAX_COL; col++){
		printf("%d |", col);
	}
	printf("\n");
	printf("--+--+--+--+--+--+--+--+--+--+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("%d ", row);
		printf("|");
		for (int col = 0; col < MAX_COL; col++){
			printf("%c |", theMap[row][col]);
		}
		printf("\n");
		printf("--+--+--+--+--+--+--+--+--+--+\n");
	}
}


//�ı����������ͼ��Ϣ
void updateMapInfor(char playerMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL],int row, int col){
	//������ѡλ����Χ�ĵ��׵ĸ���
	int numOfMine = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c <= col + 1; c++){
			if (r >= 0 && r < MAX_ROW
				&&c >= 0 && c < MAX_COL
				&&mineMap[r][c] == '1'){
				numOfMine++;
			}
		}
	}
	playerMap[row][col] = numOfMine + '0';
}


//��Ҳ���,
//����ֵ���������ѡλ���Ƿ�����
//���׷���1�������׷���0
int playDo(char playerMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL]) {
	printf("�����������ѡ��û���׵�λ��,(�� ��)\n");
	int row = 0;
	int col = 0;
	while (1){
		scanf("%d %d", &row, &col);
		if (playerMap[row][col] == '*'
			&&row >= 0 && row < MAX_ROW
			&&col >= 0 && col < MAX_COL) {
			//��ѡλ��δ���ҿ�,�ұ�ѡλ��û��Խ��
			break;
		}
		printf("����λ���������󣬿��ܴ�����������\n");
		printf("1.λ��ѡ��Խ��\n2.��ѡλ���Ѿ����ҿ�\n");
		printf("������������λ��\n");
	}
	//�ж��ǲ����ף������
	if (mineMap[row][col] == '1'){
		return 1;
	}
	else{//���򣨲����ף����µ�ͼ��Ϣ
		updateMapInfor(playerMap, mineMap, row, col);
		return 0;
	}
	
}

//�ж�����Ƿ�ʤ��(�������Ƿ��Ѿ�������),����ֵΪ1����ʤ����0����δʤ��
//�жϷ���Ϊ�������ҵ�ͼ��δ�����λ���Ƿ���׵ĸ������
//���ɽ����һ�������ף�δ����Ŀ������ף�
//��δ����ĸ��������׵ĸ���˵����Ϸ��δ����
int isWin(char playerMap[MAX_ROW][MAX_COL]){
	//��ҵ�ͼ�в�ƺ�ĸ�����Ҳ����δ����λ�õĸ�������ʼ��Ϊ0
	int numOfGrass = 0;
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			if (playerMap[row][col] == '*'){
				numOfGrass++;
			}
		}
	}
	if (numOfGrass == MAX_MINE_NUM){
		return 1;
	}
	return 0;
}

void game(){
	//��ҿ����ĵ�ͼ
	char playerMap[MAX_ROW][MAX_COL];
	//���׵�ͼ
	char mineMap[MAX_ROW][MAX_COL];
	//1.��ʼ�����ŵ�ͼ��
	//һ����ҿ�����map1���ݵ�ȫ��*��ʾ
	//һ�ŵ��׵�ͼmap2�����׵�λ��������ɣ�����Ϊ1��û��Ϊ0
	initMap(playerMap, mineMap);
	//2.��ӡmap1
	printMap(playerMap);
	//TODO
	printMap(mineMap);
	while (1){
		//3.��Ҳ�������������
		//�ж����ѡ���λ���Ƿ�����
		//����������ѭ������
		if (playDo(playerMap, mineMap) == 1){
			printf("������\n");
			break;
		}
		//�ж��������Ƿ��Ѿ�������
		//�ǣ�����Ϸʤ��
		if (isWin(playerMap)==1){
			printf("��Ӯ��\n");
			break;
		}
		//���������Ϸ
		//4.��ӡmap1
		printMap(playerMap);
	}
	//5.�ж���Ϸ�Ƿ��������ص�3
	//6.�ǣ���Ϸ��������ӡ����λ��ͼ
	printMap(mineMap);
}

int main(){
	//�˵���1.��ʼ��Ϸ   2.�˳���Ϸ
	int choice = 0;
	srand((unsigned int)time(0));
	while (1){
		choice = menu();
		if (choice == 1){
			game();
			break;
		}
		else if (choice == 2){
			break;
		}
		else{
			printf("����������������������\n");
		}
	}
	system("pause");
	return 0;
}