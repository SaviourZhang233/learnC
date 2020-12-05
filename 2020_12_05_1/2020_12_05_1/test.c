#include <stdio.h>
#include <stdlib.h>

union Un{
	char c;
	int i;
};

union Un1{
	char c[5];
	int i;
};

union Un2{
	short c[7];
	int i;
};


int main(){
	//下面输出的结果是什么？
	//printf("%d\n", sizeof(union Un1));
	//printf("%d\n", sizeof(union Un2));
	//判断大小端
	union Un un;
	un.i = 0x11223344;
	un.c = 0x55;
	printf("%x\n", un.i);
	system("pause");
	return 0;
}