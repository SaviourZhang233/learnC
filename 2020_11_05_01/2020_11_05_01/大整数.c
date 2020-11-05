#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include<conio.h>

typedef struct bign{//�ṹ����� 
	int d[300];
	int len;//λ�� 
	char sign;//������ 

}bign;//�������ṹ��


//��һ����ת��Ϊ������ 
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



//����ֵ�Ƚϴ�С
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

//��С�Ƚ� 
int compare(bign a, bign b){
	if (a.sign>b.sign) return -1;
	else if (a.sign<b.sign) return 1;
	else if (a.sign == '+') return compare1(a, b);
	else return -compare1(a, b);
}

//����ֵ�ӷ�
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

//����ֵ����
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

//����ֵ�˷�
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


//����ֵ����
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

//�������
void print(bign a){
	printf("���Ϊ��");
	if (a.sign == '-') printf("-");
	for (int i = 0; i<a.len; i++)
		printf("%d", a.d[a.len - i - 1]);
}

void page_title(){
	printf("\t\t* * * * * *�ü�ڭ��С�������������* * * * * *\t\t\n\n");
}

void return_confirm(){
	printf("\n�����������...");
	getch();
}

void error(){
	system("cls");
	page_title();
	printf("��������������\n");
	return_confirm();
	system("cls");
}

//�ӷ�
void add(){
	getchar();
	system("cls");
	bign a, b, c;
	char x[300], y[300];
	page_title();
	printf("�������ӷ�\n");
	printf("������Ҫ�����������\n ");
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

//����
void sub(){
	getchar();
	system("cls");
	bign a, b, c;
	char x[300], y[300];
	page_title();
	printf("����������\n");
	printf("������Ҫ�����������\n ");
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

//�˷�
void  multi(){
	getchar();
	system("cls");
	bign a, b, c;
	char x[300], y[300];
	page_title();
	printf("�������˷�\n");
	printf("������Ҫ�����������\n ");
	gets(x);
	printf("��\n ");
	gets(y);
	a = change(x);
	b = change(y);
	c = multi1(a, b);
	if (a.sign == b.sign) c.sign = '+';
	else c.sign = '-';
	print(c);
	return_confirm(); system("cls");
}

//����
void  divis(){
	getchar();
	system("cls");
	bign a, b, c;
	char x[300], y[300];
	page_title();
	printf("����������\n");
	printf("������Ҫ�����������\n ");
	gets(x);
	printf("��\n ");
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
	printf("�����ּ�ѡ����Ҫ���еĲ���\n\n");
	printf("\t1.�ӷ�\t\n");
	printf("\t2.����\t\n");
	printf("\t3.�˷�\t\n");
	printf("\t4.����\t\n");
	printf("\t5.�˳�\t\n");
	printf("�밴���ּ���\n");
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