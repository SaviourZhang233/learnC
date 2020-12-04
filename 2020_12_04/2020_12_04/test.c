#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

enum sex{
	MALE,//男性
	FEMALE = 20 ,//女性
	SECRET//保密
};

int main()
{

	enum color { red = 1, green, blue };

	enum  color favorite_color;

	/* 用户输入数字来选择颜色 */
	printf("请输入你喜欢的颜色: (1. red, 2. green, 3. blue): ");
	scanf("%u", &favorite_color);

	/* 输出结果 */
	switch (favorite_color)
	{
	case red:
		printf("你喜欢的颜色是红色");
		break;
	case green:
		printf("你喜欢的颜色是绿色");
		break;
	case blue:
		printf("你喜欢的颜色是蓝色");
		break;
	default:
		printf("你没有选择你喜欢的颜色");
	}
	system("pause");
	return 0;
}

//int main(){
//	MALE = 10;//报错，枚举的值是不可修改的
//	printf("MALE = %d\n", MALE);
//	printf("FEMALE = %d\n", FEMALE);
//	printf("SECRET = %d\n", SECRET);
//	system("pause");
//	return 0;
//}