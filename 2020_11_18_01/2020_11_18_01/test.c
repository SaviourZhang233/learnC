#include <stdio.h>
#include <stdlib.h>

//int checkData(int *p)
//{
//	int tmp[7] = { 0 }; //��Ǳ���ʵ���ǹ�ϣ����˼·��һ��ʼÿ��Ԫ�ض���0��
//
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//		if (tmp[p[i]]) //������λ�õı���Ѿ���1��������ظ���ֱ�ӷ���0��
//		{
//			return 0;
//		}
//		tmp[p[i]] = 1; //������ǣ�������λ�ñ��Ϊ1��
//	}
//	return 1; //ȫ��������Ҳû�г����ظ������������OK��
//}
//
//int main()
//{
//	int p[5]; //0 1 2 3 4�ֱ����a b c d e
//
//	for (p[0] = 1; p[0] <= 5; p[0]++)
//	{
//		for (p[1] = 1; p[1] <= 5; p[1]++)
//		{
//			for (p[2] = 1; p[2] <= 5; p[2]++)
//			{
//				for (p[3] = 1; p[3] <= 5; p[3]++)
//				{
//					for (p[4] = 1; p[4] <= 5; p[4]++) //���ѭ������
//					{
//						//����������˵����������ڱȽϱ���ʽֻ��0��1������������Ҫ������������ֻ��һ��Ϊ�棬������ñȽϱ���ʽ��ֵ�ܺ�Ϊ1�ķ�ʽֱ���ж��������˻�Ҫ�ж����ܲ��С�
//						if ((p[1] == 2) + (p[0] == 3) == 1 && //B�ڶ����ҵ���
//							(p[1] == 2) + (p[4] == 4) == 1 && //�ҵڶ���E����
//							(p[2] == 1) + (p[3] == 2) == 1 && //�ҵ�һ��D�ڶ�
//							(p[2] == 5) + (p[3] == 3) == 1 && //C����ҵ���
//							(p[4] == 4) + (p[0] == 1) == 1 && //�ҵ��ģ�A��һ
//							checkData(p) //���ܲ���
//							)
//						{
//							for (int i = 0; i < 5; i++)
//							{
//								printf("%d ", p[i]);
//							}
//							putchar('\n');
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}
/*
5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ����������
Aѡ��˵��B�ڶ����ҵ�����
Bѡ��˵���ҵڶ���E���ģ�
Cѡ��˵���ҵ�һ��D�ڶ���
Dѡ��˵��C����ҵ�����
Eѡ��˵���ҵ��ģ�A��һ��
����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
*/

//void bubbleSort(int arr[], int len) {
//	int i, j;
//	for (i = 0; i<len - 1; i++)
//	for (j = 0; j<len - 1 - i; j++) { 
//		if (arr[j] > arr[j + 1]) {
//			int tmp = arr[j];
//			arr[j] = arr[j + 1];
//			arr[j + 1] = tmp;
//		}
//	}
//}
//
////�ж������Ƿ�����������ظ�
////���ظ�����1�����ظ�����0
//int isReason(int a[5]){
//	//���ܸı�����
//	int b[5] = { 0 };
//	for (int i = 0; i < 5; i++){
//		b[i] = a[i];
//	}
//	//�жϷ���Ϊ�������ڱ���һ��
//	//���ֱ�ӱ����������Ƿ��ظ���Ҫ����ѭ��
//	//���Բ��ø�Ч�������㷨
//	bubbleSort(b, 5);
//	for (int i = 0; i < 4; i++){
//		if (b[i] == b[i + 1]){
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main(){
//	int rank[5] = { 0 };//��������0��4���δ�ŵ���A��E������
//	for (rank[0] = 1; rank[0] <= 5; rank[0]++){
//		for (rank[1] = 1; rank[1] <= 5; rank[1]++){
//			for (rank[2] = 1; rank[2] <= 5; rank[2]++){
//				for (rank[3] = 1; rank[3] <= 5; rank[3]++){
//					for (rank[4] = 1; rank[4] <= 5; rank[4]++){ //���ѭ������,���θı�����
//						//����˵���������Ϊÿ����ֻ��һ���ǶԵģ����ԾͲ���==1�ķ�ʽ�ж�
//						if ((rank[1] == 2) + (rank[0] == 3) == 1 && //B�ڶ����ҵ���
//							(rank[1] == 2) + (rank[4] == 4) == 1 && //�ҵڶ���E����
//							(rank[2] == 1) + (rank[3] == 2) == 1 && //�ҵ�һ��D�ڶ�
//							(rank[2] == 5) + (rank[3] == 3) == 1 && //C����ҵ���
//							(rank[4] == 4) + (rank[0] == 1) == 1 && //�ҵ��ģ�A��һ
//							isReason(rank) == 0 //�Ƿ����
//							){
//							for (int i = 0; i < 5; i++){
//								printf("%d ", rank[i]);
//							}
//							printf("\n");
//						}
//						
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

//#define N 1e-4
// ����˼·����ȥ��һ�� int ����͵�ַ��Ӧ���ֽ�, �����Ǹ�λ���ǵ�λ
void isBigEnd() {
	int num = 0x11223344;
	int* p = &num;
	char* p2 = (char*)p;
	if (*p2 == 0x11) {
		printf("�Ǵ��\n");
		return;
	}
	printf("��С��\n");
	return;
	// ��������д������һ�еİ汾. ����������. 
	// return *((char*)(&num)) == 0x11;
}

int main(){
	//float a = 19.0;
	//float b = a / 7.0;
	//if (b * 7.0 == a) {
	//	printf("���!\n");
	//} else {
	//	printf("�����\n");
	//}
	//float a = 19.0;
	//float b = a / 7.0;
	//if (b * 7.0 - a < N && b * 7.0 - a > -N) {
	//	printf("���, �˴������ϸ����, �����������\n");
	//} else {
	//	printf("�����\n");
	//}
	//int a = 0x11223344;
	isBigEnd();
	system("pause");
	return 0;
}