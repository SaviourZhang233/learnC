#include <stdio.h>
#include <stdlib.h>

//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
//�����������һ��n����̨���ܹ��ж�����������
int frog(int n){
	if (n == 1){
		return 1;
	}
	else{
		return 2 * frog(n - 1);
	}
}

int main(){
	int num = frog(10);
	printf("����10��̨�׹���%d������\n", num);
	system("pause");
	return 0;
}