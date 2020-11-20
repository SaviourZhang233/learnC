#include <stdio.h>
#include <stdlib.h>

void myqsort(void * base, size_t nitems, size_t size, int(*compar)(const void *, const void *)){
	int i, j;
	char * st = (char *)base; //void *不方便加减，用char *加减轻松且字节跳转为1，方便控制。
	char tmp[16]; //考虑到long double类型，临时空间做成16字节比较保险
	for (i = 0; i < nitems - 1; i++){
		for (j = 0; j < nitems - 1 - i; j++) {//冒泡常用循环头
			if (compar(st + j * size, st + (j + 1) * size)) {//比较的时候跳转注意乘size
				memcpy(tmp, st + j * size, size); //交换操作用memcpy完成就不会出问题。
				memcpy(st + j * size, st + (j + 1) * size, size);
				memcpy(st + (j + 1) * size, tmp, size);
			}
		}
	}
}

int main(){
	system("pause");
	return 0;
}