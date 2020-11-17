#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//�ַ����󳤶�
size_t myStrlen(char* str){
	if (str == NULL){
		return 0;
	}
	size_t len = 0;
	while (*str != '\0') {
		len++;
		str++;
	}
	return len;
}

//�ַ���ƴ�Ӻ�������sour�е����ݿ���dest�з���ֵ��dest
char* myStrcat(char* dest, const char* sour){
	if (sour == NULL || dest == NULL){
		return NULL;
	}
	char* p = dest;
	while (*p != '\0'){
		p++;
	}
	while (*sour != '\0'){
		*p = *sour;
		p++;
		sour++;
	}
	*p = '\0';
	return dest;
}

//�ַ�����������
char* myStrcpy(char* dest, const char* sour){
	if (dest == NULL || sour == NULL){
		return NULL;
	}
	char* p = dest;
	while (*sour != '\0'){
		*p = *sour;
		p++;
		sour++;
	}
	*p = '\0';
	return dest;
}

//�ַ����ȴ�С,
//str1<str2,���һ������0����
//str1>str2,���һ��С��0����
//str1=str2,���0
int myStrcmp(const char* str1, const char* str2){
	assert(str1 != NULL&&str2 != NULL);
	while (*str1 != '\0' || *str2 != '\0'){
		if (*str1 > *str2){
			return 1;
		}
		else if (*str1 < *str2){
			return -1;
		}
		str1++;
		str2++;
	}
	return (int)(*str1 - *str2);
	//�������ַ���Ҳ����
	//if (*str1 == '\0'&&*str2 == '\0'){
	//	return 0;
	//}
	//if (*str1 == '\0'){
	//	return -1;
	//}
	//	return 1;
}

//�����Ӵ�����str1�в���str2
//���ҵ�����str2��str1�е�λ��
//������ʧ�ܷ���NULL
char* myStrstr(char* str1, char* str2){
	if (str1 == NULL || str2 == NULL){
		return NULL;
	}
	char* p1 = str1;
	char* p2 = str2;
	char* p3 = p1;
	while (*p1 != '\0'){
		p3 = p1;
		p2 = str2;
		while (*p2 != '\0'&&*p3 != '\0'){
			if (*p2 == *p3){
				p2++;
				p3++;
			}
			else{
				break;
			}
		}
		//�ҵ���
		if (*p2 == '\0'){
			return p1;
		}
		p1++;
	}
	return NULL;
}

int main(){
	char str1[20] = "abcde";
	char str2[20] = "fghij";
	printf("len = %d\n", myStrlen(str1));
	printf("cpy = %s\n", myStrcpy(str1, str2));
	printf("cat = %s\n", myStrcat(str1, str2));
	char str3[20] = "zhangsan";
	char str4[20] = "zhangsanmao";
	char str5[20] = "zhangsao";
	char str6[20] = "lisi";
	printf("%d\n", myStrcmp(str3, str4));
	printf("%d\n", myStrcmp(str3, str5));
	printf("%d\n", myStrcmp(str3, str6));
	char str7[20] = "hahalaji";
	char str8[20] = "hal";
	char str9[20] = "jab";
	char* p = strstr(str7, str8);
	printf("%s\n", p);
	printf("%s\n", myStrstr(str7, str8));
	system("pause");
	return 0;
}