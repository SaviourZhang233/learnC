#include <stdio.h>
#include <stdlib.h>


#define I 1
#define J 0
/*
#if 整型常量表达式1
程序段1
#elif 整型常量表达式2
程序段2
#elif 整型常量表达式3
程序段3
#else
程序段4
#endif

	这段代码的意思是：“表达式1”的值为真（非0），就对“程序段1”进行编译，
	否则就计算“表达式2”，结果为真的话就对“程序段2”进行编译，
	为假的话就继续往下匹配，直到遇到值为真的表达式，
	或者遇到 #else。这一点和 if else 非常类似。

*/


/*
#ifdef  宏名
程序段1
#else
程序段2
#endif
	它的意思是，如果当前的宏已被定义过，
	则对“程序段1”进行编译，否则对“程序段2”进行编译。
*/


/*
#ifndef 宏名
程序段1
#else
程序段2
#endif
	与 #ifdef 相比，仅仅是将 #ifdef 改为了 #ifndef。
	它的意思是，如果当前的宏未被定义
	则对“程序段1”进行编译，否则对“程序段2”进行编译
	这与 #ifdef 的功能正好相反。
*/


//需要注意的是，#if 后面跟的是“整型常量表达式”，而 #ifdef 和 #ifndef 后面跟的只能是一个宏名，不能是其他的。

/*
#undef 宏
这个命令用于移除宏定义
当一个现存的宏需要被重新定义的时候，先移除它
*/


/*
#if defined 宏名
代码段
#endif
判断该宏有没有被定义
如果有则执行代码段，否则跳过
可以在改变宏的值之前进行判断
例如
*/
#define B 20
#if defined B //判断宏B是否被定义
#undef B //若被定义，则撤销定义
#endif 
#define B 200 //改变宏的值


#define A 10
//#define A 20   ?不会报错，但warning C4005: “A”: 宏重定义
#undef A
#define A 30
//此时不报错

int main(){
//#if K
//	printf("hehehe\n");
//#elif J
//	printf("hahaha\n");
//#elif K
//	printf("xixixi\n");
//#else
//	printf("lalala\n");
//#endif


//#if后面可以跟整型常量表达式
//#if 1
//	printf("hehehe\n");
//#elif J
//	printf("hahaha\n");
//#elif K
//	printf("xixixi\n");
//#else
//	printf("lalala\n");
//#endif


#undef A
	//如果此时用#undef移除对A的宏定义，
	//那么下面的代码段将会直接跳过
	//这是一种注释代码的方法
#if A
	printf("hehehe\n");
	//可以通过改变A的值来“注释”掉代码片段
#endif


//	printf("%d\n", A);


#ifdef A
	printf("A被定义\n");
#else 
	printf("A未被定义\n");
#endif

	printf("%d\n", B);
	system("pause");
	return 0;
}