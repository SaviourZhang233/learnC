//#include <stdio.h>
//#include <stdlib.h>
//
//int main(){
//	char* p = "abcde";
//	printf("%s\n", p);
//	printf("%s\n", p + 1);
//	system("pause");
//	return 0;
//}


//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int main(){
//	int a, i;
//	int sum = 0;
//	int add = 0;
//	printf("请输出一个1-9的数字\n");
//	scanf("%d", &a);
//	for (i = 0; i < 5; i++){
//		add = add * 10 + a;
//		sum = sum + add;
//	}
//	printf("sum=%d\n", sum);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
///*
//在屏幕上打印杨辉三角。
//1
//1 1
//1 2 1
//1 3 3 1
//……
//*/
//void yanHuiSanJiao(int n){
//	int sanjiao[40][40];
//	for (int row = 0; row < n; row++){
//		sanjiao[row][0] = 1;
//		printf("%d ", sanjiao[row][0]);
//		for (int col = 1; col < row; col++){
//			sanjiao[row][col] = sanjiao[row - 1][col - 1] + sanjiao[row - 1][col];
//			printf("%d ", sanjiao[row][col]);
//		}
//		if (row>0){
//			sanjiao[row][row] = 1;
//			printf("%d ", sanjiao[row][row]);
//		}
//		printf("\n");
//	}
//}
//
//int main(){
//	yanHuiSanJiao(5);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
///*
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//以下为4个嫌疑犯的供词:
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
//*/
//
//
//int main(){
//	//创造一个数组，数组下标代表人，例如1代表A，2代表B
//	//people[0]来存放凶手编号
//	//数组存放的内容代表这个人说的话
//	int people[5];
//	for (int i = 1; i < 5; i++){
//		//每次进入循环都要将嫌疑人的发言改回来，回溯的思想
//		people[1] = -1;//A说：不是我。- 代表不是，1代表A
//		people[2] = 3;//B说：是C。3代表C
//		people[3] = 4;//C说：是D。4代表D
//		people[4] = -4;//D说：C在胡说。表示不是D，即-4，- 代表不是，4代表D
//		int num = 0;//用于记录凶手的个数
//		//代表i号说谎
//		people[i] = - people[i];
//		//进行判断，
//		//凶手只有一个，即该数组中正数只有一个
//		//不能有矛盾，例如不能4既是凶手又不是凶手（数组中既有4又有-4），即不能出现相反数
//		for (int j = 1; j < 5; j++){
//			if (people[j]>0){
//				people[0] = people[j];
//				num++;
//			}
//		}
//		if (num > 1){//凶手个数大于1
//			people[0] = 0;//凶手未找到
//			continue;//直接下一次
//		}
//		//凶手个数为1
//		for (int j = 1; j < 5; j++){
//			//判断这个人是不是和别人的供词有矛盾
//			if (-people[0] == people[j]){//有矛盾
//				people[0] = 0;//凶手未找到
//				break;//结束这一次循环
//			}
//		}
//		if (people[0] != 0){//凶手已经找到
//			break;
//		}
//	}
//	char murderer = (char)(people[0] + 'A' - 1);
//	printf("凶手是%c", murderer);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

/*
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
*/

int main(){
	system("pause");
	return 0;
}