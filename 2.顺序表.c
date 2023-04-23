//
////SeqList.h
//#pragma once
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//typedef int SLDateType;
//
////��̬˳���
//typedef struct SeqList
//{
//	SLDateType* a;
//	int size;//��ʾ�����д洢�˶��ٸ���Ч����
//	int capacity; //����ʵ���ܴ����ݵĿռ�����
//}SL;
//
////�ӿں���--��������Ǹ���STL�ߵ�
//
////��ʼ��
//void SeqListInit(SL* ps);
//
////��ӡ
//void SeqListPrint(SL* ps);
////��̬�ص�:������˾Ͳ��ò��� ȱ��:�����ٵĺ����أ��������ȷ��
////N��С�˲��� N�������˷�
//
////����
//void SeqListDestroy(SL* ps);
//
////β������
//void SeqListPushBack(SL* ps, SLDateType x);
//
////β��ɾ��
//void SeqListPopBack(SL* ps);
//
////ͷ������
//void SeqListPushFront(SL* ps, SLDateType x);
//
////ͷ��ɾ��
//void SeqListPopFront(SL* ps);
//
////�������
//void SeqListCheckCapacity(SL* ps);
//
////�ҵ��˷���xλ���±� û���ҵ�����-1
//int SeqListFind(SL* ps, SLDateType x);
//
////ָ��pos�±�λ�ò���
//void SeqListInsert(SL* ps, int pos, SLDateType x);
//
////ɾ��posλ�õ�����
//void SeqListErase(SL* ps, int pos);
//
//
////SeqList.c
//#define _CRT_SECURE_NO_WARNINGS 1
////
//#include "SeqList.h"
////
////��ӡ
//void SeqListPrint(SL* ps)
//{
//	for (int i = 0; i < ps->size; ++i)
//	{
//		printf("%d ", ps->a[i]);
//	}
//	printf("\n");
//}
////
////��ʼ��
//void SeqListInit(SL* ps)
//{
//	ps->a = NULL;
//	ps->size = ps->capacity = 0;
//}
////
////����
//void SeqListDestroy(SL* ps)
//{
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->size = 0;
//	printf("���ٳɹ�\n");
//}
////
////����Ƿ���Ҫ����
//void SeqListCheckCapacity(SL* ps)
//{
//	//���û�пռ���߿ռ䲻�������
//	if (ps->size == ps->capacity)
//	{
//		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		SLDateType* tmp = (SLDateType*)realloc(ps->a, newcapacity * sizeof(SLDateType));
//		if (tmp == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//
//		ps->a = tmp;
//		ps->capacity = newcapacity;
//	}
//}
////
////β������
//void SeqListPushBack(SL* ps, SLDateType x)
//{
//	//SeqListCheckCapacity(ps);
//	//ps->a[ps->size] = x;
//	//ps->size++;
//	//β����Լ򻯳�
//	SeqListInsert(ps, ps->size, x);
//}
////
////β��ɾ��
//void SeqListPopBack(SL* ps)
//{
//	assert(ps->size > 0);
//	ps->size--;
//}
////
////ͷ������
//void SeqListPushFront(SL* ps, SLDateType x)
//{
//	////����費��Ҫ����
//	//SeqListCheckCapacity(ps);
//	////Ų������
//	//int end = ps->size - 1;
//	//while (end >= 0)
//	//{
//	//	ps->a[end + 1] = ps->a[end];
//	//	--end;
//	//}
//	//ps->a[0] = x;
//	//ps->size++;
//	//ͷ����Լ򻯳�
//	SeqListInsert(ps, 0, x);
//}
////
////ͷ��ɾ��
//void SeqListPopFront(SL* ps)
//{
//	////��ǰŲ��size--
//	//assert(ps->size > 0);
//	//int begin = 1;
//	//while (begin < ps->size)
//	//{
//	//	ps->a[begin - 1] = ps->a[begin];
//	//	++begin;
//	//}
//	//ps->size--;
//	SeqListErase(ps, 0);
//}
////
////���� �����±�
//int SeqListFind(SL* ps, SLDateType x)
//{
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->a[i] == x)
//		{
//			return i;
//		}
//	}
//	return -1;
//}
////
////ָ��pos�±�λ�ò���
//void SeqListInsert(SL* ps, int pos, SLDateType x)
//{
//	assert(pos >= 0 && pos <= ps->size);
//	//��������
//	SeqListCheckCapacity(ps);
//	int end = ps->size - 1;
//	while (end >= pos)
//	{
//		ps->a[end + 1] = ps->a[end];
//		--end;
//	}
//	ps->a[pos] = x;
//	ps->size++;
//}
////
////ɾ��posλ�õ�����
//void SeqListErase(SL* ps, int pos)
//{
//	assert(ps->size > 0);
//	assert(pos >= 0 && pos <= ps->size);
//	int begin = pos + 1;
//	while (begin < ps->size)
//	{
//		ps->a[begin - 1] = ps->a[begin];
//		++begin;
//	}
//	ps->size--;
//}
////
////
////test.c
//#define _CRT_SECURE_NO_WARNINGS 1
////
//#include "SeqList.h"
////
//void Menu()
//{
//	printf("*******************************\n");
//	printf("***   1.ͷ��    2.ͷɾ      ***\n");
//	printf("***   3.β��    4.βɾ      ***\n");
//	printf("***   5.pos���� 6.pos��ɾ   ***\n");
//	printf("***   7.����    8.��ӡ      ***\n");
//	printf("***        0.�˳�           ***\n");
//	printf("*******************************\n");
//	printf("��ѡ��:>");
//}
////
//enum Option
//{
//	EXIT,//0
//	PUSHFRONT,//1
//	POPFRONT,//2
//	PUSHBACK,//3
//	POPBACK,//4
//	INSERT,//5
//	ERASE,//6
//	FIND,//7
//	PRINT//8
//};
////
////
//void MenuTest()
//{
//	SL s1;
//	int n = 0;
//	int x = 0;
//	int pos = 0;
//	int num = 0;
//	SeqListInit(&s1);
//	while (1)
//	{
//		Menu();
//		int input = 0;
//		scanf("%d", &input);
//		switch (input)
//		{
//		case PUSHFRONT:
//			printf("���ĸ�������Ϊ������־\n");
//			printf("��ѡ��:>");
//			scanf("%d", &n);
//			printf("��������Ҫͷ������� ��%d����:\n", n);
//			scanf("%d", &x);
//			while (x != n)
//			{
//				SeqListPushFront(&s1, x);
//				scanf("%d", &x);
//			}
//			break;
//		case POPFRONT:
//			SeqListPopFront(&s1);
//			break;
//		case PUSHBACK:
//			printf("���ĸ�������Ϊ������־\n");
//			printf("��ѡ��:>");
//			scanf("%d", &n);
//			printf("��������Ҫβ������� ��%d����:\n", n);
//			scanf("%d", &x);
//			while (x != n)
//			{
//				SeqListPushBack(&s1, x);
//				scanf("%d", &x);
//			}
//			break;
//		case POPBACK:
//			SeqListPopBack(&s1);
//			break;
//		case PRINT:
//			SeqListPrint(&s1);
//			break;
//		case INSERT:
//			printf("����ģʽ:1.�������� ���������ǰ���� 2.�����±� ������±괦����\n");
//			printf("��ѡ��(1����2)>:");
//			scanf("%d", &n);
//			while (1)
//			{
//				if (n == 1)
//				{
//					printf("����������\n");
//					printf("��ѡ��:>");
//					scanf("%d", &num);
//					int pos = SeqListFind(&s1, num);
//					if (pos != -1)
//					{
//						printf("������Ҫ���������\n");
//						printf("��ѡ��:>");
//						scanf("%d", &x);
//						SeqListInsert(&s1, pos, x);
//						break;
//					}
//					else
//					{
//						printf("δ�ҵ�������\n");
//						printf("������ѡ��\n");
//					}
//				}
//				else
//				{
//					SL* ps = &s1;
//					printf("Ҫ�������ݵ��±�\n");
//					printf("��ѡ��>:");
//					scanf("%d", &pos);
//					if (pos >= 0 && pos <= ps->size)
//					{
//						printf("������Ҫ���������\n");
//						printf("��ѡ��>:");
//						scanf("%d", &x);
//						SeqListInsert(&s1, pos, x);
//						break;
//					}
//					else
//						printf("���±겻���� ����������\n");
//				}
//			}
//			break;
//		case ERASE:
//			printf("����ģʽ:1.�������� ɾ��������� 2.�����±� ɾ������±��Ӧ������\n");
//			printf("��ѡ��(1����2)>:");
//			scanf("%d", &n);
//			while (1)
//			{
//				if (n == 1)
//				{
//					printf("��������Ҫɾ��������\n");
//					printf("��ѡ��>:");
//					scanf("%d", &num);
//					int pos = SeqListFind(&s1, num);
//					if (pos != -1)
//					{
//						SeqListErase(&s1, pos);
//						break;
//					}
//					else
//					{
//						printf("δ�ҵ�������\n");
//						printf("������ѡ��>:");
//					}
//				}
//				else
//				{
//					SL* ps = &s1;
//					printf("��������Ҫɾ�����ݵ��±�\n");
//					printf("��ѡ��>:");
//					scanf("%d", &pos);
//					if (pos >= 0 && pos <= ps->size)
//					{
//						SeqListErase(&s1, pos);
//						break;
//					}
//					else
//						printf("���±겻���� ����������\n");
//				}
//			}
//			break;
//		case FIND:
//			printf("����������Ҫ�ҵ�����\n");
//			printf("��ѡ��>:");
//			scanf("%d", &x);
//			int pos = SeqListFind(&s1, x);
//			if (pos != -1)
//			{
//				printf("�費��Ҫ�޸�����(1.�޸� 0.���޸�)\n");
//				printf("��ѡ��(1/0)>:");
//				scanf("%d", &num);
//				if (num == 0)
//					printf("�����ݵ��±�Ϊ%d\n", pos);
//				else
//				{
//					printf("�����ݵ��±�Ϊ%d\n", pos);
//					printf("����������Ҫ�ĺ������\n");
//					printf("��ѡ��>:");
//					scanf("%d", &x);
//					SL* Find = &s1;
//					Find->a[pos] = x;
//				}
//			}
//			else
//				printf("δ�ҵ�������\n");
//			break;
//		case EXIT:
//			printf("�˳�����\n");
//			return 0;
//			break;
//		default:
//			printf("�޴�ѡ�� ����������\n");
//			break;
//		}
//	}
//	SeqListDestroy(&s1);
//}
//int main()
//{
//	MenuTest();
//	return 0;
//}
////
////#include "SeqList.h"
////void TestSeqList1()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//1 2 3 4 5β�� 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//��ӡ 1 2 3 4 5 
////	SeqListPrint(&s1);
////}
////
////void TestSeqList2()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//1 2 3 4 5ͷ��
////	SeqListPushFront(&s1, 1);
////	SeqListPushFront(&s1, 2);
////	SeqListPushFront(&s1, 3);
////	SeqListPushFront(&s1, 4);
////	SeqListPushFront(&s1, 5);
////	//��ӡ 5 4 3 2 1
////	SeqListPrint(&s1);
////}
////
////void TestSeqList3()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//1 2 3 4 5β�� 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//β��ɾ��2��
////	SeqListPopBack(&s1);
////	SeqListPopBack(&s1);
////	//��ӡ 1 2 3
////	SeqListPrint(&s1);
////	//β����ɾ��4�� ��assert����
////	SeqListPopBack(&s1);
////	SeqListPopBack(&s1);
////	SeqListPopBack(&s1);
////	SeqListPopBack(&s1);
////}
////
////void TestSeqList4()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//1 2 3 4 5β�� 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//ͷ��ɾ��2��
////	SeqListPopFront(&s1);
////	SeqListPopFront(&s1);
////	//��ӡ3 4 5
////	SeqListPrint(&s1);
////	//ͷ����ɾ��4�� assert����
////	SeqListPopFront(&s1);
////	SeqListPopFront(&s1);
////	SeqListPopFront(&s1);
////	SeqListPopFront(&s1);
////}
////
////void TestSeqList5()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//1 2 3 4 5β�� 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//����3
////	int pos = SeqListFind(&s1, 3);
////	if (pos != -1)
////		printf("�����ݵ��±�Ϊ%d\n", pos);
////	else
////		printf("û�и�����\n");
////	//����6
////	pos = SeqListFind(&s1, 6);
////	if (pos != -1)
////		printf("�����ݵ��±�Ϊ%d\n", pos);
////	else
////		printf("û�и�����\n");
////	//�ҵ�3���ĳ�30
////	pos = SeqListFind(&s1, 3);
////	if (pos != -1)
////	{
////		//����һ���ṹ��ָ��
////		SL* Find = &s1;
////		//����
////		Find->a[pos] = 30;
////	}
////	else
////		printf("û�и�����");
////	//��ӡ1 2 30 4 5
////	SeqListPrint(&s1);
////}
////
////TestSeqList6()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//β��1 2 3
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	//��ӡ1 2 3
////	SeqListPrint(&s1);
////	//ͷ��1 2 3
////	SeqListPushFront(&s1, 1);
////	SeqListPushFront(&s1, 2);
////	SeqListPushFront(&s1, 3);
////	//��ӡ3 2 1 1 2 3
////	SeqListPrint(&s1);
////}
////
////TestSeqList7()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//1 2 3 4 5β�� 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//���±�Ϊ2��λ�ò���20
////	//Ҳ����3��ǰ�����20
////	SeqListInsert(&s1, 2, 20);
////	//��ӡ1 2 20 3 4 5
////	SeqListPrint(&s1);
////	//���Խ��
////	SeqListInsert(&s1, 7, 20);
////	//��ӡ
////	SeqListPrint(&s1);
////}
////
////TestSeqList8()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//1 2 3 4 5β�� 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//��4��ǰ�����40
////	//����pos����4���±�
////	int pos = SeqListFind(&s1, 4);
////	if (pos != -1)
////		SeqListInsert(&s1, pos, 40);
////	else
////		printf("�޴�����");
////	//��ӡ1 2 3 40 4 5
////	SeqListPrint(&s1);
////	//��7��ǰ�����70
////	//˳�����û��7
////	pos = SeqListFind(&s1, 7);
////	if (pos != -1)
////		SeqListInsert(&s1, pos, 70);
////	else
////		printf("�޴����� ����ʧ��\n");
////	//��ӡ1 2 3 40 4 5
////	SeqListPrint(&s1);
////}
////
////TestSeqList9()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//1 2 3 4 5β�� 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//ͷɾ2��
////	SeqListPopFront(&s1);
////	SeqListPopFront(&s1);
////	//��ӡ3 4 5
////	SeqListPrint(&s1);
//// 	//��ͷɾ4��
////    SeqListPopFront(&s1);
////    SeqListPopFront(&s1);
////    SeqListPopFront(&s1);
////    SeqListPopFront(&s1);
////}
////
////TestSeqList10()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//1 2 3 4 5β�� 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//ɾ���±�Ϊ2������
////	//Ҳ����ɾ��3
////	SeqListErase(&s1, 2);
////	//��ӡ1 2 4 5
////	SeqListPrint(&s1);
////	//ɾ���±�Ϊ7������
////	//Խ��
////	SeqListErase(&s1, 7);
////}
////
////TestSeqList11()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//1 2 3 4 5β�� 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//ɾ��4
////	int pos = SeqListFind(&s1, 4);
////	if (pos != -1)
////		SeqListErase(&s1, pos);
////	else
////		printf("�޴����� ɾ��ʧ��\n");
////	//��ӡ1 2 3 5
////	SeqListPrint(&s1);
////	//ɾ��7
////	pos = SeqListFind(&s1, 7);
////	if (pos != -1)
////		SeqListErase(&s1, pos);
////	else
////		printf("�޴����� ɾ��ʧ��\n");
////	//��ӡ1 2 3 5
////	SeqListPrint(&s1);
////}
////
////TestSeqList12()
////{
////	//����һ���ṹ�� 
////	SL s1;
////	//��ַ��ʼ���ṹ��
////	SeqListInit(&s1);
////	//1 2 3 4 5β�� 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//��ӡ1 2 3 4 5
////	SeqListPrint(&s1);
////	//����
////	SeqListDestroy(&s1);
////	//ֻ��ӡ\n
////	SeqListPrint(&s1);
////}
////
////int main()
////{
////	TestSeqList1();
////	TestSeqList2();
////	TestSeqList3();
////	TestSeqList4();
////	TestSeqList5();
////	TestSeqList6();
////	TestSeqList7();
////	TestSeqList8();
////  TestSeqList9();
////	TestSeqList10();
////	TestSeqList11();
////	TestSeqList12();
////	return 0;
////}