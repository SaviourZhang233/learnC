#include <stdio.h>
#include <stdlib.h>


#define I 1
#define J 0
/*
#if ���ͳ������ʽ1
�����1
#elif ���ͳ������ʽ2
�����2
#elif ���ͳ������ʽ3
�����3
#else
�����4
#endif

	��δ������˼�ǣ������ʽ1����ֵΪ�棨��0�����Ͷԡ������1�����б��룬
	����ͼ��㡰���ʽ2�������Ϊ��Ļ��Ͷԡ������2�����б��룬
	Ϊ�ٵĻ��ͼ�������ƥ�䣬ֱ������ֵΪ��ı��ʽ��
	�������� #else����һ��� if else �ǳ����ơ�

*/


/*
#ifdef  ����
�����1
#else
�����2
#endif
	������˼�ǣ������ǰ�ĺ��ѱ��������
	��ԡ������1�����б��룬����ԡ������2�����б��롣
*/


/*
#ifndef ����
�����1
#else
�����2
#endif
	�� #ifdef ��ȣ������ǽ� #ifdef ��Ϊ�� #ifndef��
	������˼�ǣ������ǰ�ĺ�δ������
	��ԡ������1�����б��룬����ԡ������2�����б���
	���� #ifdef �Ĺ��������෴��
*/


//��Ҫע����ǣ�#if ��������ǡ����ͳ������ʽ������ #ifdef �� #ifndef �������ֻ����һ�������������������ġ�

/*
#undef ��
������������Ƴ��궨��
��һ���ִ�ĺ���Ҫ�����¶����ʱ�����Ƴ���
*/


/*
#if defined ����
�����
#endif
�жϸú���û�б�����
�������ִ�д���Σ���������
�����ڸı���ֵ֮ǰ�����ж�
����
*/
#define B 20
#if defined B //�жϺ�B�Ƿ񱻶���
#undef B //�������壬��������
#endif 
#define B 200 //�ı���ֵ


#define A 10
//#define A 20   ?���ᱨ����warning C4005: ��A��: ���ض���
#undef A
#define A 30
//��ʱ������

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


//#if������Ը����ͳ������ʽ
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
	//�����ʱ��#undef�Ƴ���A�ĺ궨�壬
	//��ô����Ĵ���ν���ֱ������
	//����һ��ע�ʹ���ķ���
#if A
	printf("hehehe\n");
	//����ͨ���ı�A��ֵ����ע�͡�������Ƭ��
#endif


//	printf("%d\n", A);


#ifdef A
	printf("A������\n");
#else 
	printf("Aδ������\n");
#endif

	printf("%d\n", B);
	system("pause");
	return 0;
}