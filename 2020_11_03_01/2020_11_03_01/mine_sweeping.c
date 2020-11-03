#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 9
#define MAX_COL 9
#define MAX_MINE_NUM 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//菜单函数
int menu(){
	printf("--------------\n");
	printf("1.开始游戏\n");
	printf("2.退出游戏\n");
	printf("--------------\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//初始化两张地图
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
	//随机生成10个雷
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

//打印地图
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


//改变玩家所见地图信息
void updateMapInfor(char playerMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL],int row, int col){
	//定义所选位置周围的地雷的个数
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


//玩家操作,
//返回值代表玩家所选位置是否是雷
//是雷返回1，不是雷返回0
int playDo(char playerMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL]) {
	printf("输入横纵坐标选择没有雷的位置,(横 纵)\n");
	int row = 0;
	int col = 0;
	while (1){
		scanf("%d %d", &row, &col);
		if (playerMap[row][col] == '*'
			&&row >= 0 && row < MAX_ROW
			&&col >= 0 && col < MAX_COL) {
			//被选位置未被揭开,且被选位置没有越界
			break;
		}
		printf("您的位置输入有误，可能存在如下问题\n");
		printf("1.位置选择越界\n2.所选位置已经被揭开\n");
		printf("请您重新输入位置\n");
	}
	//判断是不是雷，如果是
	if (mineMap[row][col] == '1'){
		return 1;
	}
	else{//否则（不是雷）更新地图信息
		updateMapInfor(playerMap, mineMap, row, col);
		return 0;
	}
	
}

//判断玩家是否胜利(所有雷是否已经被找完),返回值为1代表胜利，0代表还未胜利
//判断方法为，检查玩家地图上未揭起的位置是否和雷的个数相等
//（可揭起的一定不是雷，未揭起的可能是雷）
//若未揭起的个数大于雷的个数说明游戏还未结束
int isWin(char playerMap[MAX_ROW][MAX_COL]){
	//玩家地图中草坪的个数，也就是未揭起位置的个数，初始化为0
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
	//玩家看见的地图
	char playerMap[MAX_ROW][MAX_COL];
	//埋雷地图
	char mineMap[MAX_ROW][MAX_COL];
	//1.初始化两张地图，
	//一张玩家看见的map1，草地全用*表示
	//一张地雷地图map2，地雷的位置随机生成，有雷为1，没雷为0
	initMap(playerMap, mineMap);
	//2.打印map1
	printMap(playerMap);
	//TODO
	printMap(mineMap);
	while (1){
		//3.玩家操作，输入坐标
		//判断玩家选择的位置是否是雷
		//若是则跳出循环结束
		if (playDo(playerMap, mineMap) == 1){
			printf("你输了\n");
			break;
		}
		//判断所有雷是否已经被找完
		//是，则游戏胜利
		if (isWin(playerMap)==1){
			printf("你赢了\n");
			break;
		}
		//否，则继续游戏
		//4.打印map1
		printMap(playerMap);
	}
	//5.判断游戏是否结束，否回到3
	//6.是，游戏结束，打印地雷位置图
	printMap(mineMap);
}

int main(){
	//菜单，1.开始游戏   2.退出游戏
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
			printf("您的输入有误，请重新输入\n");
		}
	}
	system("pause");
	return 0;
}