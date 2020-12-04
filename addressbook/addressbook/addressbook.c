#define _CRT_SECURE_NO_WARNINGS
#define MAX_NUM 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{//联系人
	char name[1024];//姓名
	char num[64];//电话
}Per;

typedef struct addressbook{//通讯录
	int numOfPer;//联系人数
	Per per[MAX_NUM];//联系人列表
}Address;

/*
初始化通讯录
需要实现的操作是，
增加联系人
删除联系人
修改联系人姓名
修改联系人电话
查看联系人
*/

//定义全局变量address
Address address;

void initAddressBook(Address* address){//初始化通信录
	address->numOfPer = 0;
}

void showPreson(Address* address){//显示所有联系人
	printf("***************************************\n");
	printf("序号\t姓名\t\t电话号码\n");
	for (int i = 0; i < address->numOfPer; i++){
		printf("%3d\t", i + 1);
		printf("%s\t\t", address->per[i].name);
		printf("%s\n", address->per[i].num);
	}
	printf("共%d个联系人\n", address->numOfPer);
}

void addPreson(Address* address){//添加联系人
	printf("****************************************\n");
	printf("增加联系人");
	printf("请输入姓名：");
	char* p = NULL;
	p = gets((address->per)[address->numOfPer].name);
	fflush(stdin);//清除标准输入中的内容
	printf("请输入该联系人电话号码：");
	p = gets((address->per)[address->numOfPer].num);
	fflush(stdin);//清除标准输入中的内容
	address->numOfPer++;
	printf("添加成功\n");
}

void deletePreson(Address* address){//删除联系人
	printf("***************************************\n");
	printf("删除联系人");
	showPreson(address);
	printf("请输入要删除的联系人的序号：");
	int delNum = 0;
	scanf("%d", &delNum);
	fflush(stdin);//清除标准输入中的内容
	if (delNum > address->numOfPer || delNum <= 0){
		printf("您输入的序号有误\n");
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
	printf("删除成功\n");
}

void changeName(Address* address){//根据序号修改联系人姓名
	printf("***************************************\n");
	printf("修改联系人姓名\n");
	showPreson(address);
	printf("请输入序号进行修改：");
	int changeNum = 0;
	scanf("%d", &changeNum);
	fflush(stdin);//清除标准输入中的内容
	if (changeNum > address->numOfPer || changeNum <= 0){
		printf("您输入的序号有误\n");
		return;
	}
	char newName[1024] = "\0";
	printf("你要改成什么？");
	gets(newName);
	fflush(stdin);//清除标准输入中的内容
	strcpy(address->per[changeNum-1].name, newName);
	printf("修改成功\n");
}

void changeNum(Address* address){//根据序号修改联系人电话号码
	printf("***************************************\n");
	printf("修改联系人电话号码\n");
	showPreson(address);
	printf("请输入序号进行修改：");
	int changeNum = 0;
	scanf("%d", &changeNum);
	fflush(stdin);//清除标准输入中的内容
	if (changeNum > address->numOfPer || changeNum <= 0){
		printf("您输入的序号有误\n");
		return;
	}
	char newNum[64] = "\0";
	printf("你要改成什么？");
	gets(newNum);
	fflush(stdin);//清除标准输入中的内容
	strcpy(address->per[changeNum - 1].num, newNum);
	printf("修改成功\n");
}

void signOut(Address* address){
	exit(0);
}

int menu(){
	printf("***************************************\n");
	printf("1、添加联系人\n");
	printf("2、删除联系人\n");
	printf("3、查看所有联系人\n");
	printf("4、修改联系人姓名\n");
	printf("5、修改联系人电话号码\n");
	printf("6、退出\n");
	printf("请根据序号选择：");
	int choice = 0;
	scanf("%d", &choice);
	fflush(stdin);//清除标准输入中的内容
	return choice;
}



int main(){
	typedef void(*Pfunc)(Address*);
	Pfunc pf[6] = {//转移表
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
			printf("您的输入有误，请重新输入\n");
		}
	}
	system("pause");
	return 0;
}