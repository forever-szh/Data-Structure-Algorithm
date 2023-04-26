#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//��ʼ��
LTNode* ListInit();

//��ӡ
void ListPrint(LTNode* phead);

//β��
void ListPushBack(LTNode* phead, LTDateType x);

//βɾ
void ListPopBack(LTNode* phead);

//ͷ��
void ListPushFront(LTNode* phead, LTDateType x);

//ͷɾ
void ListPopFront(LTNode* phead);

//��
LTNode* ListFind(LTNode* phead, LTDateType x);

//��pos֮ǰ����x
void ListInsert(LTNode* pos, LTDateType x);

//��posλ��ɾ��
void ListErase(LTNode* pos);

//���ټ��ƿ�
void ListDestroy(LTNode* phead);


#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//��ʼ��
LTNode* ListInit()
{
	//�ڱ�λͷ�ڵ�
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//�����½ڵ㲢��������
LTNode* BuyListNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//��ӡ
void ListPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//β��
void ListPushBack(LTNode* phead, LTDateType x)
{
	////�ڱ�λͷ�ڵ㻹��
	//assert(phead);
	////β������ͷ����prev
	//LTNode* tail = phead->prev;
	//LTNode* newnode = BuyListNode(x);
	////tail��newnode����
	//tail->next = newnode;
	//newnode->prev = tail;
	////newnode��phead����
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead, x);
}

//βɾ
void ListPopBack(LTNode* phead)
{
	////phead��Ϊ��
	//assert(phead);
	////˵������Ϊ�� phead->nextָ���Լ�
	////ֻ��һ���ڱ�λ��ͷ�ڵ� ������ɾ��
	//assert(phead->next != phead);
	//LTNode* tail = phead->prev;
	//tail->prev->next = phead;
	//phead->prev = tail->prev;
	//free(tail);
	ListErase(phead->prev);
}

//ͷ��
void ListPushFront(LTNode* phead, LTDateType x)
{
	//assert(phead);
	//LTNode* next = phead->next;
	//LTNode* newnode = BuyListNode(x);
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = next;
	//next->prev = newnode;
	ListInsert(phead->next, x);
}

//ͷɾ
void ListPopFront(LTNode* phead)
{
	//assert(phead);
	////��ֹɾ���ڱ�λ
	//assert(phead->next != phead);
	//LTNode* next = phead->next;
	//LTNode* nextNext = next->next;
	//phead->next = nextNext;
	//nextNext->prev = phead;
	//free(next);
	ListErase(phead->next);
}

//��
LTNode* ListFind(LTNode* phead, LTDateType x)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//��pos֮ǰ����x
void ListInsert(LTNode* pos, LTDateType x)
{
	assert(pos);
	LTNode* posPrev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	//posPrev newnode pos
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}

//��posλ��ɾ��
void ListErase(LTNode* pos)
{
	assert(pos);
	assert(pos->next != pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}

//����
void Destroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	//�����ƿ�Ҫ������ָ����ܸı�
	//����Ҫ�������ƿ� ����дһ�����������ƿ�
	phead = NULL;
}

//���ټ��ƿ�
void ListDestroy(LTNode* phead)
{
	Destroy(phead);
	phead = NULL;
}

#define _CRT_SECURE_NO_WARNINGS 1

//#include "List.h"

//void TestList1()
//{
//	LTNode* plist = ListInit();
//	ListPushBack(plist, 1);
//	ListPushBack(plist, 2);
//	ListPushBack(plist, 3);
//	ListPushBack(plist, 4);
//	ListPopBack(plist);
//	ListPrint(plist);
//}
//
//TestList2()
//{
//	LTNode* plist = ListInit();
//	ListPushFront(plist, 1);
//	ListPushFront(plist, 2);
//	ListPushFront(plist, 3);
//	ListPushFront(plist, 4);
//	ListPopFront(plist);
//	ListPrint(plist);
//}
//
//TestList3()
//{
//	LTNode* plist = ListInit();
//	ListPushFront(plist, 1);
//	ListPushFront(plist, 2);
//	ListPushFront(plist, 3);
//	ListPushFront(plist, 4);
//	//ɾ��2
//	LTNode* pos = ListFind(plist, 2);
//	if (pos)
//		ListErase(pos);
//	else
//		printf("�޴�����,ɾ��ʧ��\n");
//	ListPrint(plist);
//}
//
//#include "List.h"
//TestList4()
//{
//	LTNode* plist = ListInit();
//	ListPushFront(plist, 1);
//	ListPushFront(plist, 2);
//	ListPushFront(plist, 3);
//	ListPushFront(plist, 4);
//	ListDestroy(plist);
//}
////
//int main()
//{
//	//TestList1();
//	//TestList2();
//	//TestList3();
//	TestList4();
//	return 0;
//}


//˳�������������
//�������ṹ��������
//����˵˭����
//�ϸ���˵����˵ �ศ��ɵ������ṹ
//
//˳���
//�ŵ�
//1.֧��������� ��Ҫ������ʽṹ֧���㷨���Ժܺõ�����
//2.cpu���ٻ��������ʸ���
//
//ȱ��:
//1.ͷ���в�����ɾ��ʱ��Ч�ʵ� O(N)
//2.����������ռ� �ռ䲻�����Ժ���Ҫ����
//������һ���̶�����
//Ϊ�˱���Ƶ������ һ�����Ƕ�������ȥ��
//�ò�����ܴ���һ���Ŀռ��˷�
//
//����(˫���ͷѭ������):
//�ŵ�:
//1.����λ�ò���ɾ��Ч�ʸ� O(1)
//2.���������ͷſռ�
//ȱ��:
//1.��֧���������(���±����)
//��ζ��:һЩ���� ���ֲ��ҵ�������
//�ṹ�ϲ�����
//2.����洢һ��ֵ ͬʱҪ�洢����ָ��
//Ҳ��һ��������
//3.cpu���ٻ��������ʸ���

#include "List.h"

void TestList1()
{
	//��ʼ�� ͷ��Ϊplist
	LTNode* plist = ListInit();
	//β��1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//��ӡ1 2 3 4
	ListPrint(plist);
}

void TestList2()
{
	//��ʼ�� ͷ��Ϊplist
	LTNode* plist = ListInit();
	//β��1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//βɾ2��
	ListPopBack(plist);
	ListPopBack(plist);
	//��ӡ1 2
	ListPrint(plist);
}

TestList3()
{
	//��ʼ�� ͷ��Ϊplist
	LTNode* plist = ListInit();
	//ͷ��1 2 3 4
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	//��ӡ4 3 2 1
	ListPrint(plist);
}

TestList4()
{
	//��ʼ�� ͷ��Ϊplist
	LTNode* plist = ListInit();
	//β��1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//ͷɾ2��
	ListPopFront(plist);
	ListPopFront(plist);
	//��ӡ3 4
	ListPrint(plist);
}

TestList5()
{
	//��ʼ�� ͷ��Ϊplist
	LTNode* plist = ListInit();
	//β��1 2 3 2 4 2
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 2);
	ListPushBack(plist, 4);
	ListPushBack(plist, 2);
	//����3
	//�ѵ�һ��3�ĳ�30
	LTNode* pos = ListFind(plist, 3);
	int i = 1;
	if (pos)
	{
		printf("��%d��pos�ڵ�:%p->%d\n", i++, pos, pos->data);
		LTNode* ppos = pos;
		while (ppos)
		{
			//��һ��λ�ü�����ʼ��
			ppos = ListFind(ppos->next, 3);
			if (ppos == pos)
				break;
			printf("��%d��pos�ڵ�:%p->%d\n", i++, ppos, pos->data);
		}
		if (pos)
			pos->data = 30;
		else
			printf("δ�ҵ������� �޸�ʧ��\n");
	}
	else
	{
		printf("δ�ҵ�������\n");
	}
	//��ӡ1 2 30 2 4 2
	ListPrint(plist);
	printf("\n");
	//����2
	//�ѵڶ���2�ĳ�20
	//3��2�ĵ�ַ
	pos = ListFind(plist, 2);
	if (pos)
	{
		i = 1;
		printf("��%d��pos�ڵ�:%p->%d\n", i++, pos, pos->data);
		LTNode* ppos = pos;
		while (ppos)
		{
			//��һ��λ�ü�����ʼ��
			ppos = ListFind(ppos->next, 2);
			if (ppos == pos)
				break;
			if (ppos && i == 2)
				ppos->data = 20;
			printf("��%d��pos�ڵ�:%p->%d\n", i++, ppos, pos->data);
		}
	}
	//��ӡ1 2 30 20 4 2
	ListPrint(plist);
	printf("\n");
	//����100
	pos = ListFind(plist, 100);
	i = 1;
	if (pos)
	{
		printf("��%d��pos�ڵ�:%p->%d\n", i++, pos, pos->data);
		LTNode* ppos = pos;
		while (ppos)
		{
			//��һ��λ�ü�����ʼ��
			ppos = ListFind(ppos->next, 3);
			if (ppos == pos)
				break;
			printf("��%d��pos�ڵ�:%p->%d\n", i++, ppos, pos->data);
		}
	}
	else
	{
		printf("δ�ҵ�������\n");
	}
}

TestList6()
{
	//��ʼ�� ͷ��Ϊplist
	LTNode* plist = ListInit();
	//β��1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//��2ǰ�����10
	LTNode* pos = ListFind(plist, 2);
	if (pos)
		ListInsert(pos, 10);
	else
		printf("�޸����� ����ʧ��\n");
	//��ӡ1 10 2 3 4
	ListPrint(plist);
	printf("\n");

	//��100ǰ�����10
	pos = ListFind(plist, 100);
	if (pos)
		ListInsert(pos, 10);
	else
		printf("�޸����� ����ʧ��\n");
	//��ӡ1 10 2 3 4
	ListPrint(plist);
}

TestList7()
{
	//��ʼ�� ͷ��Ϊplist
	LTNode* plist = ListInit();
	//β��3 2 1
	ListPushBack(plist, 3);
	ListPushBack(plist, 2);
	ListPushBack(plist, 1);
	//��ӡ3 2 1
	ListPrint(plist);
	//ͷ��4 5 6
	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	ListPushFront(plist, 6);
	//��ӡ6 5 4 3 2 1
	ListPrint(plist);
}

TestList8()
{
	//��ʼ�� ͷ��Ϊplist
	LTNode* plist = ListInit();
	//β��1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//ɾ��2
	LTNode* pos = ListFind(plist, 2);
	if (pos)
	{
		ListErase(pos);
	}
	else
		printf("�޴����� ɾ��ʧ��\n");
	//��ӡ1 3 4
	ListPrint(plist);
	printf("\n");
	//ɾ��100
	pos = ListFind(plist, 100);
	if (pos)
	{
		ListErase(pos);
	}
	else
		printf("�޴����� ɾ��ʧ��\n");
	//��ӡ1 3 4
	ListPrint(plist);
}
TestList9()
{
	//��ʼ�� ͷ��Ϊplist
	LTNode* plist = ListInit();
	//β��1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//��ӡ1 2 3 4
	ListPrint(plist);
	//ͷɾ1��
	ListPopFront(plist);
	//��ӡ2 3 4
	ListPrint(plist);
	//βɾ1��
	ListPopBack(plist);
	//��ӡ2 3
	ListPrint(plist);
}

TestList10()
{
	//��ʼ�� ͷ��Ϊplist
	LTNode* plist = ListInit();
	//β��1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//��ӡ1 2 3 4
	ListPrint(plist);
	//����
	ListDestroy(plist);
	plist = NULL;
	//����Ϊ�� ��ӡ���� assert����
	ListPrint(plist);
}

int main()
{
	//TestList1();//����β��
	//TestList2();//����βɾ
	//TestList3();//����ͷ��
	//TestList4();//����ͷɾ
	//TestList5();//���Բ���/�޸�
	//TestList6();//������pos֮ǰ����
	//TestList7();//������pos֮ǰ����ʵ�ֺ���ͷ���β��
	//TestList8();//������posλ��ɾ��
	//TestList9();//������posλ��ɾ��ʵ�ֺ���ͷɾ��βɾ
	//TestList10();//�������ټ��ƿ�
	return 0;
}
