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
//	printf("�����һ��1-9������\n");
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
//����Ļ�ϴ�ӡ������ǡ�
//1
//1 1
//1 2 1
//1 3 3 1
//����
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
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//����Ϊ4�����ɷ��Ĺ���:
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
//*/
//
//
//int main(){
//	//����һ�����飬�����±�����ˣ�����1����A��2����B
//	//people[0]��������ֱ��
//	//�����ŵ����ݴ��������˵�Ļ�
//	int people[5];
//	for (int i = 1; i < 5; i++){
//		//ÿ�ν���ѭ����Ҫ�������˵ķ��ԸĻ��������ݵ�˼��
//		people[1] = -1;//A˵�������ҡ�- �����ǣ�1����A
//		people[2] = 3;//B˵����C��3����C
//		people[3] = 4;//C˵����D��4����D
//		people[4] = -4;//D˵��C�ں�˵����ʾ����D����-4��- �����ǣ�4����D
//		int num = 0;//���ڼ�¼���ֵĸ���
//		//����i��˵��
//		people[i] = - people[i];
//		//�����жϣ�
//		//����ֻ��һ������������������ֻ��һ��
//		//������ì�ܣ����粻��4���������ֲ������֣������м���4����-4���������ܳ����෴��
//		for (int j = 1; j < 5; j++){
//			if (people[j]>0){
//				people[0] = people[j];
//				num++;
//			}
//		}
//		if (num > 1){//���ָ�������1
//			people[0] = 0;//����δ�ҵ�
//			continue;//ֱ����һ��
//		}
//		//���ָ���Ϊ1
//		for (int j = 1; j < 5; j++){
//			//�ж�������ǲ��Ǻͱ��˵Ĺ�����ì��
//			if (-people[0] == people[j]){//��ì��
//				people[0] = 0;//����δ�ҵ�
//				break;//������һ��ѭ��
//			}
//		}
//		if (people[0] != 0){//�����Ѿ��ҵ�
//			break;
//		}
//	}
//	char murderer = (char)(people[0] + 'A' - 1);
//	printf("������%c", murderer);
//	system("pause");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

/*
5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
Aѡ��˵��B�ڶ����ҵ�����
Bѡ��˵���ҵڶ���E���ģ�
Cѡ��˵���ҵ�һ��D�ڶ���
Dѡ��˵��C����ҵ�����
Eѡ��˵���ҵ��ģ�A��һ��
����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
*/

int main(){
	system("pause");
	return 0;
}