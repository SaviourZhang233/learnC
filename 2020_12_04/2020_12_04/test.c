#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

enum sex{
	MALE,//����
	FEMALE = 20 ,//Ů��
	SECRET//����
};

int main()
{

	enum color { red = 1, green, blue };

	enum  color favorite_color;

	/* �û�����������ѡ����ɫ */
	printf("��������ϲ������ɫ: (1. red, 2. green, 3. blue): ");
	scanf("%u", &favorite_color);

	/* ������ */
	switch (favorite_color)
	{
	case red:
		printf("��ϲ������ɫ�Ǻ�ɫ");
		break;
	case green:
		printf("��ϲ������ɫ����ɫ");
		break;
	case blue:
		printf("��ϲ������ɫ����ɫ");
		break;
	default:
		printf("��û��ѡ����ϲ������ɫ");
	}
	system("pause");
	return 0;
}

//int main(){
//	MALE = 10;//����ö�ٵ�ֵ�ǲ����޸ĵ�
//	printf("MALE = %d\n", MALE);
//	printf("FEMALE = %d\n", FEMALE);
//	printf("SECRET = %d\n", SECRET);
//	system("pause");
//	return 0;
//}