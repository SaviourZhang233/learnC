#define MAX_ROW 3
#define MAX_COLUMN 3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu(){
	printf("----------------------------\n");
	printf("1.开始游戏\n");
	printf("2.退出游戏\n");
	printf("----------------------------\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//棋盘初始化，无落子
void initBoard(char newBoard[MAX_ROW][MAX_COLUMN]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COLUMN; col++){
			newBoard[row][col] = ' ';
		}
	}
}

void printBoard(char chessBoard[MAX_ROW][MAX_COLUMN]) {
	// 把棋盘打印出来. 
	//for (int row = 0; row < MAX_ROW; row++) {
	//	for (int col = 0; col < MAX_COL; col++) {
	//		// 注意: 使用 %c 来打印字符
	//		printf("%c ", chessBoard[row][col]);
	//	}
	//	printf("\n");
	//}
	// 上面的代码虽然能够打印出棋盘, 但是都是空格, 看不清. 
	// 最好让元素能有边框
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("| %c | %c | %c |\n", chessBoard[row][0],
			chessBoard[row][1], chessBoard[row][2]);
		printf("+---+---+---+\n");
	}
}

////打印棋盘
//void printboard(char board[max_row][max_column]){
//	for (int row = 0; row < max_row; row++){
//		for (int col = 0; col < max_column;col++){
//			printf("%c", board[row][col]);
//		}
//		printf("\n");
//	}
//}

//玩家落子,全场棋子数+1
void playerDo(char board[MAX_ROW][MAX_COLUMN], int* numberOfPieces){
	int row = 0;
	int col = 0;
	while (1){
		printf("请您落子（行 列） 注意：行列值均属于[0,2]\n");
		scanf("%d %d", &row, &col);
		//判断是否越界
		if (row < 0 || row >= MAX_ROW ||
			col < 0 || col >= MAX_COLUMN){
			printf("您的子飞出棋盘，请重新落子\n");
		}//判断玩家落子位置是否已经有子
		else if (board[row][col] != ' '){
			printf("您落子的位置已经有子,请重新落子\n");
		}
		else{
			break;
		}
	}
	board[row][col] = 'x';
	*numberOfPieces++;
}

//电脑落子,全场棋子数+1
void computerDo(char board[MAX_ROW][MAX_COLUMN], int* numberOfPieces){
	printf("电脑落子\n");
	int row = 0;
	int col = 0;
	while (1){
		row = rand() % 3;
		col = rand() % 3;
		if (board[row][col] == ' '){
			//该位置无子
			break;
		}
	}
	board[row][col] = 'o';
	*numberOfPieces++;
}

//判断棋盘是否下满，1表示下满，0表示未下满
int isFull(int numberOfPieces){
	if (numberOfPieces == 9)
		return 1;
	else
		return 0;
}

//判断胜负，返回值为'x'玩家赢，返回值为'o'电脑赢，返回值为'*'平手
char whoIsWiner(char board[MAX_ROW][MAX_COLUMN]){
	//判断所有行
	for (int row = 0; row < MAX_ROW; row++){
		if (board[row][0] == board[row][1] ||
			board[row][1] == board[row][2]){
			return board[row][0];
		}
	}
	//判断所有列
	for (int col = 0; col < MAX_COLUMN; col++){
		if (board[0][col] == board[1][col] ||
			board[1][col] == board[2][col]){
			return board[0][col];
		}
	}
	//判断所有对角线
	if (board[1][1] == board[0][0] ||
		board[2][2] == board[0][0]){
		return board[0][0];
	}
	if (board[0][2] == board[1][1] ||
		board[1][1] == board[2][0]){
		return board[1][1];
	}
	return '*';
}

void game(){
	char board[MAX_ROW][MAX_COLUMN];
	//char winer = '*';
	//棋盘上棋子的个数，游戏刚开始的时候棋盘上棋子的个数为0
	int numberOfPieces = 0;
	printf("游戏开始\n");
	//1.初始化棋盘
	initBoard(board);
	//2.打印棋盘
	printBoard(board);
	while (1){
		//3.玩家落子（行，列），玩家的子用x表示
		playerDo(board, &numberOfPieces);
		//4.打印棋盘
		printBoard(board);
		//5.判断棋盘是否下满,如果下满了，判断胜负
		if (isFull(numberOfPieces) == 1){
			if (whoIsWiner(board) == 'o'){//电脑胜
				printf("你输了\n");
				return;
			}
			if (whoIsWiner(board) == 'x'){//玩家胜
				printf("你赢了\n");
				return;
			}
			if (whoIsWiner(board) == '*'){//平手
				printf("你和电脑势均力敌\n");
				return;
			}
		}
		//6.电脑随机落子，电脑的子用o表示
		computerDo(board, &numberOfPieces);
		//7.打印棋盘
		printBoard(board);
		//8.判断棋盘是否下满,如果下满了，判断胜负
		if (isFull(numberOfPieces) == 1){
			if (whoIsWiner(board) == 'o'){//电脑胜
				printf("你输了\n");
				return;
			}
			if (whoIsWiner(board) == 'x'){//玩家胜
				printf("你赢了\n");
				return;
			}
			if (whoIsWiner(board) == '*'){//平手
				printf("你和电脑势均力敌\n");
				return;
			}
		}
	}
}
int main(){
	int chioce;
	srand((unsigned int)time(0));
	while (1){
		//菜单，1.进行游戏；2.退出游戏
		chioce = menu();
		if (chioce == 1){
			game();
			break;
		}
		else if (chioce == 2){
			printf("再见\n");
			break;
		}
		else{
			printf("您的输入有误，请重新输入\n");
		}
	}
	system("pause");
	return 0;
}