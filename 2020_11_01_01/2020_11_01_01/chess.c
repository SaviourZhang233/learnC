#define MAX_ROW 3
#define MAX_COLUMN 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu(){
	printf("----------------------------\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.�˳���Ϸ\n");
	printf("----------------------------\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//���̳�ʼ����������
void initBoard(char newBoard[MAX_ROW][MAX_COLUMN]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COLUMN; col++){
			newBoard[row][col] = ' ';
		}
	}
}

void printBoard(char chessBoard[MAX_ROW][MAX_COLUMN]) {
	// �����̴�ӡ����. 
	//for (int row = 0; row < MAX_ROW; row++) {
	//	for (int col = 0; col < MAX_COL; col++) {
	//		// ע��: ʹ�� %c ����ӡ�ַ�
	//		printf("%c ", chessBoard[row][col]);
	//	}
	//	printf("\n");
	//}
	// ����Ĵ�����Ȼ�ܹ���ӡ������, ���Ƕ��ǿո�, ������. 
	// �����Ԫ�����б߿�
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("| %c | %c | %c |\n", chessBoard[row][0],
			chessBoard[row][1], chessBoard[row][2]);
		printf("+---+---+---+\n");
	}
}



//�������
void playerDo(char board[MAX_ROW][MAX_COLUMN], int* numberOfPieces){
	int row = 0;
	int col = 0;
	while (1){
		printf("�������ӣ��� �У� ע�⣺����ֵ������[0,2]\n");
		scanf("%d %d", &row, &col);
		//�ж��Ƿ�Խ��
		if (row < 0 || row >= MAX_ROW ||
			col < 0 || col >= MAX_COLUMN){
			printf("�����ӷɳ����̣�����������\n");
		}//�ж��������λ���Ƿ��Ѿ�����
		else if (board[row][col] != ' '){
			printf("�����ӵ�λ���Ѿ�����,����������\n");
		}
		else{
			break;
		}
	}
	board[row][col] = 'x';
	*numberOfPieces = *numberOfPieces + 1;
	printf("��������%d��\n", *numberOfPieces);
}

//��������
void computerDo(char board[MAX_ROW][MAX_COLUMN], int* numberOfPieces){
	printf("��������\n");
	int row = 0;
	int col = 0;
	while (1){
		row = rand() % 3;
		col = rand() % 3;
		if (board[row][col] == ' '){
			//��λ������
			break;
		}
	}
	board[row][col] = 'o';
	*numberOfPieces = *numberOfPieces + 1;
}

//�ж������Ƿ�������1��ʾ������0��ʾδ����
int isfull(int numberOfPieces){
	if (numberOfPieces == 9)
		return 1;
	else
		return 0;
}

//�ж�ʤ��������ֵΪ'x'���Ӯ������ֵΪ'o'����Ӯ������ֵΪ'*'ƽ��,����ֵΪ' '����
char whoIsWiner(char board[MAX_ROW][MAX_COLUMN],int numberOfPieces){
	//�ж�������
	for (int row = 0; row < MAX_ROW; row++){
		if (board[row][0] != ' '&&
			board[row][0] == board[row][1] &&
			board[row][1] == board[row][2]){
			return board[row][0];
		}
	}
	//�ж�������
	for (int col = 0; col < MAX_COLUMN; col++){
		if (board[0][col] != ' '&&
			board[0][col] == board[1][col] &&
			board[1][col] == board[2][col]){
			return board[0][col];
		}
	}
	//�ж����жԽ���
	if (board[1][1] != ' '&&
		board[1][1] == board[0][0] &&
		board[2][2] == board[0][0]){
		return board[0][0];
	}
	if (board[1][1] != ' '&&
		board[0][2] == board[1][1] &&
		board[1][1] == board[2][0]){
		return board[1][1];
	}
	//�ж������Ƿ�����
	if (isfull(numberOfPieces) == 0){
		return ' ';
	}

	return '*';
}

void game(){
	char board[MAX_ROW][MAX_COLUMN];
	char winer = ' ';
	////���������ӵĸ�������Ϸ�տ�ʼ��ʱ�����������ӵĸ���Ϊ0
	int numberOfPieces = 0;
	printf("��Ϸ��ʼ\n");
	//1.��ʼ������
	initBoard(board);
	//2.��ӡ����
	printBoard(board);
	while (1){
		//3.������ӣ��У��У�����ҵ�����x��ʾ
		playerDo(board, &numberOfPieces);
		//4.��ӡ����
		printBoard(board);
		//5.�ж�ʤ��
		//if (isFull(numberOfPieces) == 1){
		//	if (whoIsWiner(board) == 'o'){//����ʤ
		//		printf("������\n");
		//		return;
		//	}
		//	if (whoIsWiner(board) == 'x'){//���ʤ
		//		printf("��Ӯ��\n");
		//		return;
		//	}
		//	if (whoIsWiner(board) == '*'){//ƽ��
		//		printf("��͵����ƾ�����\n");
		//		return;
		//	}
		//}
		winer = whoIsWiner(board, numberOfPieces);
		if (winer != ' '){
			break;
		}
		//6.����������ӣ����Ե�����o��ʾ
		computerDo(board, &numberOfPieces);
		//7.��ӡ����
		printBoard(board);
		//8.�ж�ʤ��
		winer = whoIsWiner(board, numberOfPieces);
		if (winer != ' '){
			break;
		}
		//if (isFull(numberOfPieces) == 1){
		//	if (whoIsWiner(board) == 'o'){//����ʤ
		//		printf("������\n");
		//		return;
		//	}
		//	if (whoIsWiner(board) == 'x'){//���ʤ
		//		printf("��Ӯ��\n");
		//		return;
		//	}
		//	if (whoIsWiner(board) == '*'){//ƽ��
		//		printf("��͵����ƾ�����\n");
		//		return;
		//	}
		//}
	}
	if (winer == 'x'){
		printf("��Ӯ��\n");
	}
	if (winer == 'o'){
		printf("������\n");
	}
	if (winer == '*'){
		printf("ƽ��\n");
	}
}

int main(){
	int chioce;
	srand((unsigned int)time(0));
	while (1){
		//�˵���1.������Ϸ��2.�˳���Ϸ
		chioce = menu();
		if (chioce == 1){
			game();
			break;
		}
		else if (chioce == 2){
			printf("�ټ�\n");
			break;
		}
		else{
			printf("����������������������\n");
		}
	}
	system("pause");
	return 0;
}