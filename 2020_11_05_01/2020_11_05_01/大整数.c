#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include<conio.h>

typedef struct bign{//结构体变量 
	int d[300];
	int len;//位数 
	char sign;//正负号 

}bign;//大整数结构体


//将一个数转化为大整数 
bign change(char str[]){
	bign a; int i;
	memset(a.d, 0, sizeof(a.d));
	a.len = 0;
	if (str[0] == '-'){
		a.sign = '-';
		a.len = strlen(str) - 1;
		for (i = 0; i<a.len; i++)
			a.d[i] = str[a.len - i] - '0';
	}
	else if (str[0] == '+'){
		a.sign = '+';
		a.len = strlen(str) - 1;
		for (i = 0; i<a.len; i++)
			a.d[i] = str[a.len - i] - '0';
	}

	else {
		a.sign = '+';
		a.len = strlen(str);
		for (i = 0; i<a.len; i++)
			a.d[i] = str[a.len - 1 - i] - '0';
	}
	return a;
}



//绝对值比较大小
int compare1(bign a, bign b){
	if (a.len>b.len) return 1;
	else if (a.len<b.len) return -1;
	else {
		for (int i = 1; a.len >= i; i++){
			if (a.d[a.len - i]>b.d[a.len - i]) return 1;
			else if (a.d[a.len - i]<b.d[a.len - i]) return -1;
		}
		return 0;
	}
}

//大小比较 
int compare(bign a, bign b){
	if (a.sign>b.sign) return -1;
	else if (a.sign<b.sign) return 1;
	else if (a.sign == '+') return compare1(a, b);
	else return -compare1(a, b);
}

//绝对值加法
bign add1(bign a, bign b){
	bign c;
	int carry = 0, i;
	int max_len = (a.len>b.len) ? a.len : b.len;
	for (i = 0; i <= max_len - 1; i++){
		c.d[i] = (a.d[i] + b.d[i] + carry) % 10;
		carry = (a.d[i] + b.d[i] + carry) / 10;
	}
	if (carry == 0) c.len = max_len;
	else {
		c.len = max_len + 1; c.d[c.len - 1] = carry;
	}
	return c;
}

//绝对值减法
bign sub1(bign a, bign b){
	bign c;
	int max_len;
	max_len = (a.len>b.len) ? a.len : b.len;
	for (int i = 0; i <= max_len - 1; i++){
		if (a.d[i]<b.d[i]){
			a.d[i + 1]--;
			a.d[i] += 10;
		}
		c.d[i] = a.d[i] - b.d[i];
	}
	if (c.d[max_len - 1] == 0) c.len = max_len - 1;
	else c.len = max_len;
	return c;
}

//绝对值乘法
bign multi1(bign a, bign b){
	bign c;
	memset(c.d, 0, sizeof(c.d));
	int carry = 0;
	for (int i = 0; i <= a.len - 1; i++){
		for (int j = 0; j <= b.len - 1; j++)
			c.d[i + j] = c.d[i + j] + a.d[i] * b.d[j];
	}
	for (int i = 0; i <= a.len + b.len - 2; i++){
		int k = c.d[i] + carry;
		c.d[i] = k % 10;
		carry = k / 10;
	}
	if (carry == 0) c.len = a.len + b.len - 1;
	else {
		c.len = a.len + b.len; c.d[c.len - 1] = carry;
	}
	return c;
}


//绝对值除法
bign  divis1(bign a, bign b){
	bign c, e;
	memset(c.d, 0, sizeof(c.d));
	memset(e.d, 0, sizeof(e.d));
	char x[300] = { "0" }; char y[300] = { "1" };
	c = change(x); e = change(y);
	while (compare1(a, b) == 1 || compare1(a, b) == 0){
		a = sub1(a, b);
		c = add1(c, e);
	}
	return c;
}

//输出函数
void print(bign a){
	printf("结果为：");
	if (a.sign == '-') printf("-");
	for (int i = 0; i<a.len; i++)
		printf("%d", a.d[a.len - i - 1]);
}

void page_title(){
	printf("\t\t* * * * * *堂吉诃德小组大整数计算器* * * * * *\t\t\n\n");
}

void return_confirm(){
	printf("\n按任意键返回...");
	getch();
}

void error(){
	system("cls");
	page_title();
	printf("你输入的序号有误\n");
	return_confirm();
	system("cls");
}

//加法
void add(){
	getchar();
	system("cls");
	bign a, b, c;
	char x[300], y[300];
	page_title();
	printf("大整数加法\n");
	printf("请输入要计算的两个数\n ");
	gets(x);
	printf("+\n ");
	gets(y);
	a = change(x);
	b = change(y);
	if (a.sign == '+'&&b.sign == '+'){
		c = add1(a, b); c.sign = '+';
	}
	if (a.sign == '-'&&b.sign == '-'){
		c = add1(a, b); c.sign = '-';
	}
	if (a.sign == '+'&&b.sign == '-'){
		if (compare1(a, b) == -1){
			c = sub1(b, a); c.sign = '-';
		}
		else{
			c = sub1(a, b); c.sign = '+';
		}
	}
	if (a.sign == '-'&&b.sign == '+'){
		if (compare1(a, b) == 1){
			c = sub1(a, b); c.sign = '-';
		}
		else {
			c = sub1(b, a); c.sign = '+';
		}
	}
	print(c);
	return_confirm(); system("cls");
}

//减法
void sub(){
	getchar();
	system("cls");
	bign a, b, c;
	char x[300], y[300];
	page_title();
	printf("大整数减法\n");
	printf("请输入要计算的两个数\n ");
	gets(x);
	printf("-\n ");
	gets(y);
	a = change(x);
	b = change(y);
	if (a.sign == '-'&&b.sign == '+'){
		c = add1(a, b); c.sign = '-';
	}
	if (a.sign == '+'&&b.sign == '-'){
		c = add1(a, b); c.sign = '+';
	}
	if (a.sign == '+'&&b.sign == '+'){
		if (compare1(a, b) == -1){
			c = sub1(b, a); c.sign = '-';
		}
		else {
			c = sub1(a, b); c.sign = '+';
		}
	}
	if (a.sign == '-'&&b.sign == '-'){
		if (compare1(a, b) == 1){
			c = sub1(a, b); c.sign = '-';
		}
		else{
			c = sub1(b, a); c.sign = '+';
		}
	}
	print(c);
	return_confirm(); system("cls");
}

//乘法
void  multi(){
	getchar();
	system("cls");
	bign a, b, c;
	char x[300], y[300];
	page_title();
	printf("大整数乘法\n");
	printf("请输入要计算的两个数\n ");
	gets(x);
	printf("×\n ");
	gets(y);
	a = change(x);
	b = change(y);
	c = multi1(a, b);
	if (a.sign == b.sign) c.sign = '+';
	else c.sign = '-';
	print(c);
	return_confirm(); system("cls");
}

//除法
void  divis(){
	getchar();
	system("cls");
	bign a, b, c;
	char x[300], y[300];
	page_title();
	printf("大整数除法\n");
	printf("请输入要计算的两个数\n ");
	gets(x);
	printf("÷\n ");
	gets(y);
	a = change(x);
	b = change(y);
	c = divis1(a, b);
	if (a.sign == b.sign) c.sign = '+';
	else c.sign = '-';
	print(c);
	return_confirm(); system("cls");
}

int main(){

menu:page_title();
	printf("按数字键选择你要进行的操作\n\n");
	printf("\t1.加法\t\n");
	printf("\t2.减法\t\n");
	printf("\t3.乘法\t\n");
	printf("\t4.除法\t\n");
	printf("\t5.退出\t\n");
	printf("请按数字键：\n");
	switch (getchar()){
	case'1':add(); break;
	case'2':sub(); break;
	case'3':multi(); break;
	case'4':divis(); break;
	case'5':exit(0); break;
	default:error();
	}
	goto menu;
	return 0;
}