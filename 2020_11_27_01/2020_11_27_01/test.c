#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int a = 1;
	while (1){
		a++;
		FILE * pf = fopen("D:/a.txt", "rb+");
		if (pf == NULL){
			perror("���ļ�����");
			printf("%d\n",a);
			system("pause");
			return 1;
		}
	}
	
	////fwrite
	////size_t fwrite��const void * ptr��size_t size��size_t count��FILE * stream��;
	//char buf[1024] = "hahaha";
	//int n = fwrite(buf, 1, 10, pf);
	////buf[6]��֮���\0����д�룬��ɿո�
	////�������СֻΪ9������ʱ����Ϊbuf[9]��
	////����ȴҪ���ļ��ж���10���ַ����������
	////���ᱨ��������δ������Ϊ��
	////buf[10]������Ұָ�룬��Ѹ�λ�õ�ֵд���ļ���
	////���Ǹ�λ��ԭ����ʲô����֪��

	////fwrite�������ж�
	//if (n < 10){
	//	//�����������
	//	perror("fwrite");
	//  system("pause");
	//}


	////fread
	////size_t fread��void * ptr��size_t size��size_t count��FILE * stream��;
	////���سɹ���ȡ��Ԫ��������
	////�����������count������ͬ�����ڶ�ȡʱ������ȡ����򵽴��ļ�ĩβ��
	//char buf1[1024] = "\0";
	//int n1 = fread(buf1, 1, 1024, pf);
	////printf("%s\n", buf1);

	////fread�������ж�
	//if (n1 != 10){
	//	perror("fread");
	//	system("pause");
	//	return 1;
	//}
	//puts(buf1);
	//printf("%d\n", n1);


	////fprintf
	////int fprintf(FILE *stream, const char *format, ...)
	////����ɹ����򷵻�д����ַ����������򷵻�һ��������
	//char a = 'a';
	//int b = 2;
	//int c2 = fprintf(pf, "%c  %d", a, b);
	//fprintf(stdout, "%d\n", c2);


	////fscanf
	////int fscanf(FILE *stream, const char *format, ...) 
	////����ɹ����ú������سɹ�ƥ��͸�ֵ�ĸ�����
	////��������ļ�ĩβ�����������򷵻� EOF��
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
	//����ɹ����ú���������ͬ�� str ������
	//��������ļ�ĩβ����û�ж�ȡ���κ��ַ���str �����ݱ��ֲ��䣬������һ����ָ�롣
	//����������󣬷���һ����ָ�롣
	//fclose(pf);

	//char str[50];
	//printf("������һ���ַ�����");
	//gets(str);
	////printf("��������ַ����ǣ�%s", str);
	////puts(str);
	system("pause");
	return 0;
}