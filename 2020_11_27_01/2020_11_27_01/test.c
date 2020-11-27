#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = 1;
	while (1){
		a++;
		FILE * pf = fopen("D:/a.txt", "rb+");
		if (pf == NULL){
			perror("打开文件出错。");
			printf("%d\n",a);
			system("pause");
			return 1;
		}
	}
	
	////fwrite
	////size_t fwrite（const void * ptr，size_t size，size_t count，FILE * stream）;
	//char buf[1024] = "hahaha";
	//int n = fwrite(buf, 1, 10, pf);
	////buf[6]和之后的\0都被写入，变成空格
	////若数组大小只为9（定义时定义为buf[9]）
	////但是却要往文件中读入10个字符，会出错吗？
	////不会报错，但是是未定义行为，
	////buf[10]类似于野指针，会把该位置的值写入文件，
	////但是该位置原来有什么并不知道

	////fwrite的条件判断
	//if (n < 10){
	//	//不会进入这里
	//	perror("fwrite");
	//  system("pause");
	//}


	////fread
	////size_t fread（void * ptr，size_t size，size_t count，FILE * stream）;
	////返回成功读取的元素总数。
	////如果此数字与count参数不同，则在读取时发生读取错误或到达文件末尾。
	//char buf1[1024] = "\0";
	//int n1 = fread(buf1, 1, 1024, pf);
	////printf("%s\n", buf1);

	////fread的条件判断
	//if (n1 != 10){
	//	perror("fread");
	//	system("pause");
	//	return 1;
	//}
	//puts(buf1);
	//printf("%d\n", n1);


	////fprintf
	////int fprintf(FILE *stream, const char *format, ...)
	////如果成功，则返回写入的字符总数，否则返回一个负数。
	//char a = 'a';
	//int b = 2;
	//int c2 = fprintf(pf, "%c  %d", a, b);
	//fprintf(stdout, "%d\n", c2);


	////fscanf
	////int fscanf(FILE *stream, const char *format, ...) 
	////如果成功，该函数返回成功匹配和赋值的个数。
	////如果到达文件末尾或发生读错误，则返回 EOF。
	//int a, b;
	//char e, f;
	//int c1 = fscanf(pf, "%c %c %d %d", &e, &f, &a, &b);
	//if (c1 == EOF){
	//	perror("fscanf");
	//	return 1;
	//}
	//printf("%c\n%c\n%d\n%d\n", e, f, a, b);


	//fgets
	//char *fgets(char *str, int n, FILE *stream);
	//如果成功，该函数返回相同的 str 参数。
	//如果到达文件末尾或者没有读取到任何字符，str 的内容保持不变，并返回一个空指针。
	//如果发生错误，返回一个空指针。
	//fclose(pf);

	//char str[50];
	//printf("请输入一个字符串：");
	//gets(str);
	////printf("您输入的字符串是：%s", str);
	////puts(str);
	system("pause");
	return 0;
}