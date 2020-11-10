#include <stdio.h>
#include <stdlib.h>

/*
在屏幕上打印杨辉三角。

1 
1 1
1 2 1
1 3 3 1
……
*/
void yangHuiTriangle(int n){
	int data[30] = { 1 };
	int i, j;
	printf("1\n"); //第一行就直接打印了
	for (i = 1; i < n; i++) {//从第二行开始
		for (j = i; j > 0; j--) {//从后向前填，避免上一行的数据在使用前就被覆盖
			data[j] += data[j - 1]; //公式同上，由于变成了一维，公式也变简单了。
		}
		for (j = 0; j <= i; j++) {//这一行填完就直接打印了。
			printf("%d ", data[j]);
		}
		putchar('\n');
	}
}

int main(){
	yangHuiTriangle(10);
	system("pause");
	return 0;
}