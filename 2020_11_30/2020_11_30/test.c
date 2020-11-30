#include <stdio.h>//函数库里只有声明没有定义
#include <stdlib.h>
#include "sum.h"


//宏定义中#的作用在于把一个宏参数变成对应的字符串
#define PRINT(FORMAT,VALUE)\
	printf("the value of "#VALUE" is "FORMAT"\n", VALUE);

// 1. 使用宏定义常量
#define SIZE 10

// 2. 使用宏给运算符重命名
#define and &&
#define or ||

// 3. 使用宏重新定义类型的别名. 
// typedef unsigned int uint;
#define uint unsigned int

// 4. 宏还可以用来给关键字定义别名
// register 表示 "寄存器" 
// 这个关键字已经废弃了. 
#define reg register

// 5. 宏还能定义一段代码片段
//    这种用法和函数很像
//    \是换行
#define CHECK(ret) if (ret == 0) { \
	printf("执行失败\n"); \
	return 1; \
}

// 6. 宏还可以作为 "编译开关" 
//    可以根据条件让一些代码能编译或者不编译. 
//    结合条件编译来使用(一会介绍)
// _CRT_SECURE_NO_WARNINGS 就是一个编译开关
// 没有这个宏的定义的时候, VS 就会多编译一些对于 scanf 等函数安全检查的逻辑
// 有这个宏定义, 相关的检查代码就不被编译了. 
// 这段检查的代码在 stdio.h 里头. 所以必须把这个宏定义到 stdio.h 的上方

int main(){



	//extern关键词
	//在函数外部定义的变量叫做外部变量，又叫全局变量
	//其生命周期为程序的整个生存周期
	//然而，如果全局变量不在文件的开头定义，有效的作用范围将只限于其定义处到文件结束。
	//如果在定义点之前的函数想引用该全局变量，
	//则应该在引用之前用关键字 extern 对该变量作“外部变量声明”
	//表示该变量是一个已经定义的外部变量。
	//如下面g_val2,如果不加关键词extern声明的语句，编译将报错。
	//extern void print(char* str);
	//extern int g_val;
	//char string[10] = "abcdefg";
	//printf("%d\n", g_val);
	//printf("%d\n", g_val1);
	//extern int g_val2;
	//printf("%d\n", g_val2);
	//print(string);
	//print1(string);


	//预处理
	//预定义符号
	//这些基本都是语言内置的宏
	//预定义符号是预处理的一部分，所以显示的都是编译时候的信息而不是执行时候的信息
	//printf("file:%s\n", __FILE__);//进行编译的源文件
	//printf("line:%d\n", __LINE__);//当前编译的行号
	//printf("date:%s\n", __DATE__);//文件被编译的日期
	//printf("time:%s\n", __TIME__);//文件被编译的时间
	//printf("stdc:%d\n", __STDC__);//编译器是否遵循ANSI C，如果遵循其值为1，否则不遵循，显然VS不遵循


	int i = 10;
	PRINT("%d", i + 10);
	//#define PRINT(FORMAT,VALUE)\
	printf("the value of "#VALUE" is "FORMAT"\n", VALUE);
	system("pause");
	return 0;
}

int g_val2 = 2020;