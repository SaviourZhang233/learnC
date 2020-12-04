#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{//��ϵ��
	char name[1024];//����
	char num[64];//�绰
}Per;

typedef struct addressbook{//ͨѶ¼
	int numOfPer;//��ϵ����
	Per per[MAX_NUM];//��ϵ���б�
}Address;

/*
��ʼ��ͨѶ¼
��Ҫʵ�ֵĲ����ǣ�
������ϵ��
ɾ����ϵ��
�޸���ϵ������
�޸���ϵ�˵绰
�鿴��ϵ��
*/

//����ȫ�ֱ���address
Address address;

void initAddressBook(Address* address){//��ʼ��ͨ��¼
	address->numOfPer = 0;
}

void showPreson(Address* address){//��ʾ������ϵ��
	printf("***************************************\n");
	printf("���\t����\t\t�绰����\n");
	for (int i = 0; i < address->numOfPer; i++){
		printf("%3d\t", i + 1);
		printf("%s\t\t", address->per[i].name);
		printf("%s\n", address->per[i].num);
	}
	printf("��%d����ϵ��\n", address->numOfPer);
}

void addPreson(Address* address){//�����ϵ��
	printf("****************************************\n");
	printf("������ϵ��");
	printf("������������");
	char* p = NULL;
	p = gets((address->per)[address->numOfPer].name);
	fflush(stdin);//�����׼�����е�����
	printf("���������ϵ�˵绰���룺");
	p = gets((address->per)[address->numOfPer].num);
	fflush(stdin);//�����׼�����е�����
	address->numOfPer++;
	printf("��ӳɹ�\n");
}

void deletePreson(Address* address){//ɾ����ϵ��
	printf("***************************************\n");
	printf("ɾ����ϵ��");
	showPreson(address);
	printf("������Ҫɾ������ϵ�˵���ţ�");
	int delNum = 0;
	scanf("%d", &delNum);
	fflush(stdin);//�����׼�����е�����
	if (delNum > address->numOfPer || delNum <= 0){
		printf("��������������\n");
		return;
	}
	if (delNum == address->numOfPer){
		address->numOfPer--;
	}
	if (delNum < address->numOfPer){
		strcpy(address->per[delNum - 1].name, address->per[address->numOfPer - 1].name);
		strcpy(address->per[delNum - 1].num, address->per[address->numOfPer - 1].num);
		address->numOfPer--;
	}
	printf("ɾ���ɹ�\n");
}

void changeName(Address* address){//��������޸���ϵ������
	printf("***************************************\n");
	printf("�޸���ϵ������\n");
	showPreson(address);
	printf("��������Ž����޸ģ�");
	int changeNum = 0;
	scanf("%d", &changeNum);
	fflush(stdin);//�����׼�����е�����
	if (changeNum > address->numOfPer || changeNum <= 0){
		printf("��������������\n");
		return;
	}
	char newName[1024] = "\0";
	printf("��Ҫ�ĳ�ʲô��");
	gets(newName);
	fflush(stdin);//�����׼�����е�����
	strcpy(address->per[changeNum-1].name, newName);
	printf("�޸ĳɹ�\n");
}

void changeNum(Address* address){//��������޸���ϵ�˵绰����
	printf("***************************************\n");
	printf("�޸���ϵ�˵绰����\n");
	showPreson(address);
	printf("��������Ž����޸ģ�");
	int changeNum = 0;
	scanf("%d", &changeNum);
	fflush(stdin);//�����׼�����е�����
	if (changeNum > address->numOfPer || changeNum <= 0){
		printf("��������������\n");
		return;
	}
	char newNum[64] = "\0";
	printf("��Ҫ�ĳ�ʲô��");
	gets(newNum);
	fflush(stdin);//�����׼�����е�����
	strcpy(address->per[changeNum - 1].num, newNum);
	printf("�޸ĳɹ�\n");
}

void signOut(Address* address){
	exit(0);
}

int menu(){
	printf("***************************************\n");
	printf("1�������ϵ��\n");
	printf("2��ɾ����ϵ��\n");
	printf("3���鿴������ϵ��\n");
	printf("4���޸���ϵ������\n");
	printf("5���޸���ϵ�˵绰����\n");
	printf("6���˳�\n");
	printf("��������ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	fflush(stdin);//�����׼�����е�����
	return choice;
}



int main(){
	typedef void(*Pfunc)(Address*);
	Pfunc pf[6] = {//ת�Ʊ�
		NULL, addPreson, deletePreson, showPreson, changeName, changeNum,
	};
	while (1){
		int choice = menu();
		if (choice <= 5 && choice >= 1){
			pf[choice](&address);
		}
		else if (choice == 6){
			break;
		}
		else {
			printf("����������������������\n");
		}
	}
	system("pause");
	return 0;
}