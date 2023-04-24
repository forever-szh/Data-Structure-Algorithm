////SList.h
//#pragma once
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//typedef int SLTDateType;
//
//typedef struct SListNode
//{
//	SLTDateType data;
//	struct SListNode* next;
//}SLTNode;
//
////��ӡ����
//void SListPrint(SLTNode* phead);
//
////β��
//void SListPushBack(SLTNode** pphead, SLTDateType x);
//
////ͷ��
//void SListPushFront(SLTNode** pphead, SLTDateType x);
//
////βɾ
//void SListPopBack(SLTNode** pphead);
//
////ͷɾ
//void SListPopFront(SLTNode** pphead);
//
////����
//SLTNode* SListFind(SLTNode* phead, SLTDateType x);
//
////��posλ��֮ǰȥ����һ���ڵ�
//void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//
////��pos֮�����һ���ڵ� ������ʺ� Ҳ����
//void SListInsertAfter(SLTNode* pos, SLTDateType x);
//
////��posλ��ɾ��
//void SListErase(SLTNode** pphead, SLTNode* pos);
//
////��pos֮���λ��ɾ��
//void SListEraseAfter(SLTNode* pos);
//
////����
//void SListDestroy(SLTNode** pphead);
//
//
////SList.c
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "SList.h"
//
////����һ���ڵ�
//SLTNode* BuyListNode(SLTDateType x)
//{
//	//������
//	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
//	if (newnode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	//������
//	newnode->data = x;
//	//β���ſ�ָ��
//	newnode->next = NULL;
//	return newnode;
//}
//
////��ӡ
//void SListPrint(SLTNode* phead)
//{
//	//�ṹ��ָ�� ����next
//	SLTNode* cur = phead;
//	while (cur != NULL)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//}
//
////β��
//void SListPushBack(SLTNode** pphead, SLTDateType x)
//{
//	//���������plist ������
//	//ͷָ��ĵ�ַ������Ϊ��
//	//�����ǿ����� ��ָ��ĵ�ַҲ��Ϊ��
//	//����㴫����plist ��ô&plistΪ��
//	//��ֹ��һ��ָ�� ����ط�Ӧ�ô�����ָ��
//	assert(pphead);
//	SLTNode* newnode = BuyListNode(x);
//	if (*pphead == NULL)
//	{
//		//������������ǿ�ָ�� Ҳ����˵����û������
//		//�൱�ڰ�����ṹ����Ϊ�׸�ָ��
//		*pphead = newnode;
//	}
//	//int->int*
//	//int*->int**
//	else
//	{
//		//�ҵ�β�ڵ�
//		SLTNode* tail = *pphead;
//		while (tail->next != NULL)
//		{
//			//β�ڵ�˵��nextָ��Ϊ��
//			//ͨ��ѭ���ҵ�
//			tail = tail->next;
//		}
//		//�ٰ�������ĵ�ַ��β�ڵ��nextָ��
//		tail->next = newnode;
//	}
//}
//
////ͷ��
//void SListPushFront(SLTNode** pphead, SLTDateType x)
//{
//	assert(pphead);
//	//����
//	SLTNode* newnode = BuyListNode(x);
//	//�Ȱѵڶ���λ�õ�ָ�����һ��λ�õ�ָ��next
//	newnode->next = *pphead;
//	//����������Ľڵ���Ϊͷ��ַ
//	*pphead = newnode;
//}
//
////βɾ
////������ֻ��1������ʱ prev��ǰ1�� ���ǿ�ָ�� ��ʱ��prev���н�����
////�ᱨ�� ���Ҫ��������
//void SListPopBack(SLTNode** pphead)
//{
//	assert(pphead);
//	assert(*pphead != NULL);
//	//˵�������ֻ��1���ڵ��� ͷ����nextָ��ΪNULL
//	if ((*pphead)->next == NULL)
//	{
//		//ֱ�Ӱ���1�����ݻ���ϵͳ
//		free(*pphead);
//		*pphead = NULL;
//	}
//	//˵���ڵ�������1������
//	else
//	{
//		SLTNode* prev = NULL;
//		SLTNode* tail = *pphead;
//		while (tail->next != NULL)//while(tail->next)Ҳ���� 
//		{
//			//����ǰ��һ����������
//			//����prev��Ϊβ����ǰһ��
//			prev = tail;
//			tail = tail->next;
//		}
//		free(tail);
//		tail = NULL;
//		//û�а�ǰһ����nextָ���Ϊ��ָ��Ļ�
//		//�ȵ�tail���������ٺ� ���nextָ���ָ��һ���Ѿ�����ϵͳ�Ŀռ�
//		//��ô�Ļ� ���nextָ����ΪҰָ�� �Ƿ�����
//		prev->next = NULL;
//	}
//}
//
////ͷɾ
//void SListPopFront(SLTNode** pphead)
//{
//	assert(pphead);
//	//��plistΪNULL��ʱ�� �����ûᱨ�� 
//	assert(*pphead != NULL);
//	//��plist�ᵽ��һ�� ��next������
//	SLTNode* next = (*pphead)->next;
//	//�ͷ�
//	free(*pphead);
//	//�ٰ���һ����Ϊplist
//	*pphead = next;
//}
//
////���� Ҳ�����޸� �ҵ�����޸�ֵ����data
//SLTNode* SListFind(SLTNode* phead, SLTDateType x)
//{
//	//ͷ���õ�
//	SLTNode* cur = phead;
//	while (cur)
//	{
//		//����
//		if (cur->data == x)
//		{
//			return cur;
//		}
//		//û�ҵ���һֱ������
//		else
//		{
//			cur = cur->next;
//		}
//	}
//	//���û�ҵ� ���ؿ�
//	return NULL;
//}
//
////��posλ��֮ǰȥ����һ���ڵ�
//void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
//{
//	assert(pphead);
//	assert(pos);
//	SLTNode* newnode = BuyListNode(x);
//	//�������ͷ��
//	if (*pphead == pos)
//	{
//		//ԭ����ͷ�����µĽڵ��next
//		newnode->next = *pphead;
//		//�µĽڵ��Ϊplist
//		*pphead = newnode;
//	}
//	//����ͷ��
//	else
//	{
//		//�ҵ�pos��ǰһ��λ��
//		SLTNode* posPrev = *pphead;
//		while (posPrev->next != pos)
//		{
//			//����posǰһ��λ�þ�������
//			posPrev = posPrev->next;
//		}
//		//posPrev newnode pos������
//		posPrev->next = newnode;
//		newnode->next = pos;
//	}
//}
//
////��pos֮�����һ���ڵ� ������ʺ� Ҳ����
//void SListInsertAfter(SLTNode* pos, SLTDateType x)
//{
//	//posΪ�� ���벻��
//	assert(pos);
//	//������һ���½ڵ�
//	SLTNode* newnode = BuyListNode(x);
//	//������
//	////�Ȱ�pos����һ����ַ����newnode
//	//newnode->next = pos->next;
//	////�ٰ�newnode�ĵ�ַ����pos
//	//pos->next = newnode;
//	//����
//	SLTNode* posNext = pos->next;
//	pos->next = newnode;
//	newnode->next = posNext;
//}
//
////��posλ��ɾ��
//void SListErase(SLTNode** pphead, SLTNode* pos)
//{
//	assert(pphead);
//	assert(pos);
//	//ͷɾ���⴦��
//	if (*pphead == pos)
//	{
//		//plistָ����һ��
//		*pphead = pos->next;
//		//ɾ��pos Ҳ����ͷ��
//		free(pos);
//		//����ֱ�ӵ���ͷɾ
//		//SListPopFront(pphead);
//	}
//	//����ͷɾ Ҫ����һ�� ��һ������next�õ�
//	else
//	{
//		//��ǰһ�� ��ͷ��ʼ
//		SLTNode* prev = *pphead;
//		//ǰһ��nextָ����pos �ͽ���������
//		while (prev->next != pos)
//		{
//			prev = prev->next;
//		}
//		//pos����һ������pos����һ��
//		prev->next = pos->next;
//		//ɾ��pos
//		free(pos);
//		pos = NULL;
//	}
//}
//
////��pos֮���λ��ɾ��
//void SListEraseAfter(SLTNode* pos)
//{
//	assert(pos);
//	//posΪβ��������
//	assert(pos->next);
//	//pos��һ����ַ
//	SLTNode* next = pos->next;
//	//pos��������ַ��Ϊpos��һ���ĵ�ַ
//	pos->next = next->next;
//	//ɾ����һ��
//	free(next);
//	next = NULL;
//}
//
////����
//void SListDestroy(SLTNode** pphead)
//{
//	assert(pphead);
//	SLTNode* cur = *pphead;
//	while (cur)
//	{
//		//�ȱ�����һ��
//		SLTNode* next = cur->next;
//		//���ͷ�
//		//������ͷ� �ٱ��� �ͷŵĵ�ַ�������ֵ �Ҳ�����һ��
//		free(cur);
//		//��һ��Ϊ��ͷ
//		cur = next;
//	}
//	//������
//	*pphead = NULL;
//}
//
////test.c
//#define _CRT_SECURE_NO_WARNINGS 1
//
////˳���
////ȱ��:
////1.�ռ䲻��������Ҫ���� ������Ҫ��������
////2.����Ƶ������ ���˾���2�� ���ܾͻᵼ��һ���Ŀռ��˷�
////3.˳���Ҫ�����ݴӿ�ʼλ�������洢 ��ô������ͷ�������м�λ�ò���ɾ������
////����ҪŲ������ Ч�ʲ���
////�ŵ�:
////1.֧���������
//
////���˳���ȱ�� ����Ƴ�������
//
////����
////�ŵ�:
////1.��������ռ� �����˾��ͷſռ�(�������ʹ���˿ռ�)
////2.ͷ���м����ɾ������ ����ҪŲ������ ����ռ��˷�
////ȱ��:
////1.ÿ��һ������ ��Ҫ��һ��ָ��ȥ���Ӻ������ݽڵ㲻֧���������
////���±�ֱ�ӷ��ʵ�i��
//
//#include "SList.h"
//
////void TestSList1()
////{
////	SLTNode* plist = NULL;
////	//��ָ��ȥ��β�� �Ҳ���
////	//plistֱ�ӿ���ȥ ����Ӱ��phead ʵ�� �β� Ҫ����ַ
////	//��Ȼ��ָ�� ����ı��������plist ��Ҫ��plist�ĵ�ַ
////	//���ں�����������øı�
////	//��ı�int  Ҫ��int*  �����øı�
////	//��ı�int* Ҫ��int** �����øı�
////	//β��1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//��ӡ1 2 3 4 NULL
////	SListPrint(plist);
////
////	//ͷ��1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////	//��ӡ4 3 2 1 1 2 3 4 NULL
////	SListPrint(plist);
////}
////
////void TestSList2()
////{
////	SLTNode* plist = NULL;
////	//ͷ��1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////
////	//ͷ��ɾ�� ���ɾ��5�� �ᱨ��
////	SListPopBack(&plist);
////	SListPopBack(&plist);
////	SListPopBack(&plist);
////	SListPopBack(&plist);
////	//��ӡNULL
////	SListPrint(plist);
////}
////
////void TestSList3()
////{
////	SLTNode* plist = NULL;
////	//ͷ��1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////
////	//ͷɾһ�� ��ӡһ��
////	SListPopFront(&plist);
////	SListPrint(plist);
////	SListPopFront(&plist);
////	SListPrint(plist);
////	SListPopFront(&plist);
////	SListPrint(plist);
////	SListPopFront(&plist);
////	SListPrint(plist);
////}
////
////void TestSList4()
////{
////	SLTNode* plist = NULL;
////	//ͷ��1 2 3 2 4 2 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 4);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 4);
////
////	//����2
////	//3��2�ĵ�ַ
////	SLTNode* pos = SListFind(plist, 2);
////	int i = 1;
////	while (pos)
////	{
////		printf("��%d��pos�ڵ�:%p->%d\n", i++, pos, pos->data);
////		//��һ��λ�ü�����ʼ��
////		pos = SListFind(pos->next, 2);
////	}
////
////	//�޸�
////	pos = SListFind(plist, 3);
////	if (pos)
////	{
////		//����ҵ�3
////		//��3�޸ĳ�30
////		pos->data = 30;
////	}
////	//��ӡ
////	SListPrint(plist);
////}
////
////void TestSList5()
////{
////	SLTNode* plist = NULL;
////	//ͷ��1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////	//���ҵ�3
////	SLTNode* pos = SListFind(plist, 3);
////	if (pos)
////	{
////		//����3ǰ�����30
////		SListInsert(&plist, pos, 30);
////	}
////	//��ӡ
////	SListPrint(plist);
////
////	//���ҵ�1
////    pos = SListFind(plist, 1);
////	if (pos)
////	{
////		//����1ǰ�����10
////		SListInsert(&plist, pos, 10);
////	}
////	//��ӡ
////	SListPrint(plist);
////
////	//�����ͷ��
////	//���ҵ�4
////	pos = SListFind(plist, 4);
////	if (pos)
////	{
////		//����4ǰ�����40
////		SListInsert(&plist, pos, 40);
////	}
////	//��ӡ
////	SListPrint(plist);
////	//�ҵ�2
////	pos = SListFind(plist, 2);
////	if (pos)
////	{
////		//��2�������20
////		SListInsertAfter(pos, 20);
////	}
////	//��ӡ
////	SListPrint(plist);
////	//ɾ��2֮��
////	pos = SListFind(plist, 2);
////	SListEraseAfter(pos);
////	//��ӡ
////	SListPrint(plist);
////	//ɾ��4
////	pos = SListFind(plist, 4);
////	SListErase(&plist,pos);
////	//��ӡ
////	SListPrint(plist);
////}
////void TestSList6()
////{
////	SLTNode* plist = NULL;
////	//ͷ��1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////	//��ӡ1 2 3 4
////	SListPrint(plist);
////	//����
////	SListDestory(&plist);
////}
////
////int main()
////{
////	TestSList1();
////	TestSList2();
////	TestSList3();
////	TestSList4();
////	TestSList5();
////	TestSList6();
////	return 0;
////}
//
//
//
////#include "SList.h"
////void TestSList1()
////{
////	//����һ���ṹ��ָ��
////	SLTNode* plist = NULL;
////	//β��1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//��ӡ1 2 3 4 NULL
////	SListPrint(plist);
////}
////
////void TestSList2()
////{
////	//����һ���ṹ��ָ��
////	SLTNode* plist = NULL;
////	//ͷ��1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////	//��ӡ4 3 2 1 NULL
////	SListPrint(plist);
////}
////
////void TestSList3()
////{
////	//����һ���ṹ��ָ��
////	SLTNode* plist = NULL;
////	//β��1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//��ӡ1 2 3 4 NULL
////	SListPrint(plist);
////	//β��ɾ��2��
////	SListPopBack(&plist);
////	SListPopBack(&plist);
////	//��ӡ 1 2 NULL
////	SListPrint(plist);
////}
////
////
////void TestSList4()
////{
////	//����һ���ṹ��ָ��
////	SLTNode* plist = NULL;
////	//β��1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//��ӡ1 2 3 4 NULL
////	SListPrint(plist);
////	//ͷ��ɾ��2��
////	SListPopFront(&plist);
////	SListPopFront(&plist);
////	//��ӡ 3 4 NULL
////	SListPrint(plist);
////}
////
////void TestSList5()
////{
////	//����һ���ṹ��ָ��
////	SLTNode* plist = NULL;
////	//β��1 2 3 4 2 4 2
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 4);
////	SListPushBack(&plist, 2);
////	//����3
////	SLTNode* Find = SListFind(plist, 3);
////	if (Find != NULL)
////		printf("�ҵ���\n");
////	else
////		printf("�Ҳ���\n");
////	//����100
////	Find = SListFind(plist, 100);
////	if (Find != NULL)
////		printf("�ҵ���\n");
////	else
////		printf("�Ҳ���\n");
////	//����3�����޸ĳ�30
////	Find = SListFind(plist, 3);
////	if (Find != NULL)
////	{
////		Find->data = 30;
////		//��ӡ1 2 30 2 4 2 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("�Ҳ��� �޷��޸�\n");
////	//����100�����޸ĳ�10
////	Find = SListFind(plist, 100);
////	if (Find != NULL)
////	{
////		Find->data = 10;
////		//��ӡ1 20 3 4 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("�Ҳ��� �޷��޸�\n");
////	//����2
////	//3��2�ĵ�ַ
////	SLTNode* pos = SListFind(plist, 2);
////	int i = 1;
////	while (pos)
////	{
////		printf("��%d��pos�ڵ�:%p->%d\n", i++, pos, pos->data);
////		//��һ��λ�ü�����ʼ��
////		pos = SListFind(pos->next, 2);
////	}
////}
////
////void TestSList6()
////{
////	//����һ���ṹ��ָ��
////	SLTNode* plist = NULL;
////	//β��1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//��ӡ1 2 3 4 NULL
////	SListPrint(plist);
////	//��2��ǰ�����20
////	SLTNode* pos = SListFind(plist, 2);
////	if (pos != NULL)
////	{
////		SListInsert(&plist, pos, 20);
////		SListPrint(plist);
////	}
////	else
////		printf("δ�ҵ�������� ����ʧ��\n");
////	//��100ǰ�����10
////	pos= SListFind(plist, 100);
////	if (pos != NULL)
////	{
////		SListInsert(&plist, pos, 10);
////		SListPrint(plist);
////	}
////	else
////		printf("δ�ҵ�������� ����ʧ��\n");
////}
////void TestSList7()
////{
////	//����һ���ṹ��ָ��
////	SLTNode* plist = NULL;
////	//β��1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//��ӡ1 2 3 4 NULL
////	SListPrint(plist);
////	//�ҵ�2���ں������20
////	SLTNode* pos = SListFind(plist, 2);
////	if (pos != NULL)
////	{
////		SListInsertAfter(pos, 20);
////		//��ӡ1 2 20 3 4 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("δ�ҵ������� ����ʧ��\n");
////	//�ҵ�100���ں������10
////	pos = SListFind(plist, 100);
////	if (pos != NULL)
////	{
////		SListInsertAfter(pos, 10);
////		SListPrint(plist);
////	}
////	else
////		printf("δ�ҵ������� ����ʧ��\n");
////}
////
////void TestSList8()
////{
////	//����һ���ṹ��ָ��
////	SLTNode* plist = NULL;
////	//β��1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//��ӡ1 2 3 4 NULL
////	SListPrint(plist);
////	//ɾ��2
////	SLTNode* pos = SListFind(plist, 2);
////	if (pos != NULL)
////	{
////		SListErase(&plist, pos);
////		//��ӡ1 3 4 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("δ�ҵ������� ɾ��ʧ��\n");
////	//ɾ��100
////	pos = SListFind(plist, 100);
////	if (pos != NULL)
////	{
////		SListErase(&plist, pos);
////		SListPrint(plist);
////	}
////	else
////		printf("δ�ҵ������� ɾ��ʧ��\n");
////}
////
////void TestSList9()
////{
////	//����һ���ṹ��ָ��
////	SLTNode* plist = NULL;
////	//β��1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//��ӡ1 2 3 4 NULL
////	SListPrint(plist);
////	//ɾ��2֮��� Ҳ����3
////	SLTNode* pos = SListFind(plist, 2);
////	if (pos != NULL)
////	{
////		SListEraseAfter(pos);
////		//��ӡ1 2 4 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("�޴����� ɾ��ʧ��\n");
////	//ɾ��100֮���
////	pos = SListFind(plist, 100);
////	if (pos != NULL)
////	{
////		SListEraseAfter(pos);
////		//��ӡ1 2 4 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("�޴����� ɾ��ʧ��\n");
////}
////
////void TestSList10()
////{
////	//����һ���ṹ��ָ��
////	SLTNode* plist = NULL;
////	//β��1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//��ӡ1 2 3 4 NULL
////	SListPrint(plist);
////	//����
////	SListDestroy(&plist);
////	//��ӡ NULL
////	SListPrint(plist);
////}
////
////int main()
////{
////	//TestSList1();//����β��
////	//TestSList2();//����ͷ��
////	//TestSList3();//����βɾ
////	//TestSList4();//����ͷɾ
////	//TestSList5();//���Բ��Һ��޸�
////	//TestSList6();//������pos֮ǰ����
////	//TestSList7();//������pos֮�����
////	//TestSList8();//������posλ��ɾ��
////	//TestSList9();//������pos֮��ɾ��
////	//TestSList10();//��������
////	return 0;
////}
//
//#include"SList.h"
//
//void Menu()
//{
//	printf("************************************\n");
//	printf("***   1.ͷ��       2.ͷɾ        ***\n");
//	printf("***   3.β��       4.βɾ        ***\n");
//	printf("***   5.pos֮ǰ��  6.pos֮���   ***\n");
//	printf("***   7.posλ��ɾ  8.pos֮��ɾ   ***\n");
//	printf("***   9.����/�޸�  10.��ӡ       ***\n");
//	printf("***          0.�˳�              ***\n");
//	printf("************************************\n");
//	printf("��ѡ��:>");
//}
//enum Option
//{
//	EXIT,//0
//	SLISTPUSHFRONT,//1
//	SLISTPOPFRONT,//2
//	SLISTPUSHBACK,//3
//	SLISTPOPBACK,//4
//	SLISTINSERT,//5
//	SLISTINSERTAFTER,//6
//	SLISTERASE,//7
//	SLISTERASEAFTER,//8
//	SLISTFIND,//9
//	SLISTPRINT,//10
//};
//
//Menutest()
//{
//	//�ṹ�岻Ҫ������ѭ�������� ��Ȼһֱ�ǿ�ָ��
//	SLTNode* plist = NULL;
//	int x = 0;
//	int n = 0;
//	int num = 0;
//	int input = 0;
//	while (1)
//	{
//		Menu();
//		scanf("%d", &input);
//		switch (input)
//		{
//		case EXIT:
//			printf("�˳�����\n");
//			return 0;
//			break;
//		case SLISTPUSHFRONT:
//			printf("���ĸ�������Ϊ������־\n");
//			printf("��ѡ��:>");
//			scanf("%d", &n);
//			printf("��������Ҫͷ������� ��%d����:\n", n);
//			scanf("%d", &x);
//			while (x != n)
//			{
//				SListPushFront(&plist, x);
//				scanf("%d", &x);
//			}
//			break;
//		case SLISTPOPFRONT:
//			SListPopFront(&plist);
//			break;
//		case SLISTPUSHBACK:
//			printf("���ĸ�������Ϊ������־\n");
//			printf("��ѡ��:>");
//			scanf("%d", &n);
//			printf("��������Ҫβ������� ��%d����:\n", n);
//			scanf("%d", &x);
//			while (x != n)
//			{
//				SListPushBack(&plist, x);
//				scanf("%d", &x);
//			}
//			break;
//		case SLISTPOPBACK:
//			SListPopBack(&plist);
//			break;
//		case SLISTINSERT:
//			while (1)
//			{
//				printf("��������Ҫ���ĸ�����ǰ��������\n");
//				printf("��ѡ��>:");
//				scanf("%d", &num);
//				printf("������������������\n");
//				printf("��ѡ��>:");
//				scanf("%d", &x);
//				SLTNode* pos = SListFind(plist, num);
//				if (pos)
//				{
//					SListInsert(&plist, pos, x);
//					break;
//				}
//				else
//					printf("δ�ҵ������� ����ʧ�� ����������\n");
//			}
//			break;
//		case SLISTINSERTAFTER:
//			while (1)
//			{
//				printf("��ѡ������Ҫ���ĸ����ݺ����������\n");
//				printf("��ѡ��>:");
//				scanf("%d", &num);
//				printf("����������Ҫ���������\n");
//				printf("��ѡ��>:");
//				scanf("%d", &x);
//				SLTNode* pos = SListFind(plist, num);
//				if (pos)
//				{
//					SListInsertAfter(pos, x);
//					break;
//				}
//				else
//				{
//					printf("δ�ҵ������� ����ʧ�� ����������\n");
//				}
//			}
//			break;
//		case SLISTERASE:
//			while (1)
//			{
//				printf("����������Ҫɾ��������>:\n");
//				printf("��ѡ��>:");
//				scanf("%d", &num);
//				SLTNode* pos = SListFind(plist, num);
//				if (pos)
//				{
//					SListErase(&plist, pos);
//					break;
//				}
//				else
//					printf("δ�ҵ������� ɾ��ʧ�� ������ѡ��\n");
//			}
//			break;
//		case SLISTERASEAFTER:
//			while (1)
//			{
//				printf("����������Ҫɾ���ĸ����ݺ��������\n");
//				printf("��ѡ��>:");
//				scanf("%d", &num);
//				SLTNode* pos = SListFind(plist, num);
//				if (pos)
//				{
//					SListEraseAfter(pos);
//					break;
//				}
//				else
//					printf("δ�ҵ������� ɾ��ʧ�� ������ѡ��\n");
//			}
//			break;
//		case SLISTFIND:
//			while (1)
//			{
//				printf("����������Ҫ���ҵ�����\n");
//				printf("��ѡ��>:");
//				scanf("%d", &num);
//				SLTNode* pos = SListFind(plist, num);
//				if (pos)
//				{
//					printf("�ҵ���\n");
//					printf("�޲��޸�����(1�޸�/0���޸�)\n");
//					printf("��ѡ��>:");
//					scanf("%d", &num);
//					if (num == 1)
//					{
//						printf("������ĺ������\n");
//						printf("��ѡ��>:");
//						scanf("%d", &x);
//						pos->data = x;
//						printf("�޸ĳɹ�\n");
//					}
//					break;
//				}
//				else
//					printf("�������ݲ����� ������ѡ��\n");
//			}
//			break;
//		case SLISTPRINT:
//			SListPrint(plist);
//			break;
//		default:
//			printf("������� ����������\n");
//			break;
//		}
//	}
//	SListDestroy(&plist);
//}
//
//int main()
//{
//	Menutest();
//	return 0;
//}
