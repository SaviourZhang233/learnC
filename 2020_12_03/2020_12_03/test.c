#include <stdio.h>
#include <stdlib.h>

struct A{
	int a : 2;
	int b : 5;
	int c : 20;
	char d : 6;
	int e : 30;
	char f : 3;
};

struct S{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};


int main(){
	//union{
	//	short k;
	//	char i[2];
	//}*s, a;
	//s = &a;
	//s->i[0] = 0x39;
	//s->i[1] = 0x38;
	//printf("%x\n", a.k);
	//printf("%x %x", a.i[0], a.i[1]);
	//struct A A1 = { 0x11, 0x11, 0x11, 0x11, 0x11 };
	//printf("sizeof(struct A) = %d\n", sizeof(struct A));
	struct S s = { 0 };
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	system("pause");
	return 0;
}