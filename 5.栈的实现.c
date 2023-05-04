////stack.h
//#pragma once
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//typedef int STDataType;
//
//typedef struct Stack
//{
//	STDataType* a;
//	int top;//ջ����λ��
//	int capacity;
//}ST;
//
////��ʼ��
//void StackInit(ST* ps);
//
////����
//void StackDestroy(ST* ps);
//
////ջ������
//void StackPush(ST* ps, STDataType x);
//
////ջ��ɾ��
//void StackPop(ST* ps);
//
////ջ������
//STDataType StackTop(ST* ps);
//
////ջ�Ĵ�С
//int StackSize(ST* ps);
//
////ջ�Ƿ�Ϊ��
//bool StackEmpty(ST* ps);
//
//
////stack.c
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "Stack.h"
//
////��ʼ��
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;
//	//��ʼ�� top������0 ��ζ��topָ��ջ�����ݵ���һ��
//	//�ȷ����� �ټ�1
//	//��ʼ�� top������-1 ��ζ��topָ��ջ������
//	//�ȼ�1 �ٷ�����
//	ps->capacity = 0;
//}
//
////����
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
////ջ������
//void StackPush(ST* ps, STDataType x)
//{
//	assert(ps);
//	if (ps->top == ps->capacity)
//	{
//		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
//		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newCapacity);
//		if (tmp == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		ps->a = tmp;
//		ps->capacity = newCapacity;
//	}
//	ps->a[ps->top] = x;
//	ps->top++;
//}
//
////ջ��ɾ��
//void StackPop(ST* ps)
//{
//	assert(ps);
//	//����ɾ���˻�ɾ
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//
////ջ������
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	//��Ϊ���ٷ���ջ��
//	assert(!StackEmpty(ps));
//	//����֮��top���Լ� ���top-1����ջ��
//	return ps->a[ps->top - 1];
//}
//
////ջ�Ĵ�С
//int StackSize(ST* ps)
//{
//	assert(ps);
//	//top�Ĵ�С����size
//	return ps->top;
//}
//
////ջ�Ƿ�Ϊ��
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	//top==0Ϊ�� ����1 ջ�ǿյ�
//	//top!=0Ϊ�� ����0 ջ���ǿյ�
//	return ps->top == 0;
//}
//
////test.c
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "Stack.h"
//
//void TestStack1()
//{
//	ST st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//	//ѭ����ӡջ����ɾ��ջ��
//	//ʵ�ֱ���
//	//����ȳ�
//	while (!StackEmpty(&st))
//	{
//		//��ӡջ��
//		printf("%d ", StackTop(&st));
//		//ɾ��ջ��
//		StackPop(&st);
//	}
//	StackDestroy(&st);
//}
//
//void TestStack2()
//{
//	ST st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//	StackPop(&st);
//	StackPop(&st);
//	//ѭ����ӡջ����ɾ��ջ��
//	//ʵ�ֱ���
//	//����ȳ�
//	while (!StackEmpty(&st))
//	{
//		//��ӡջ��
//		printf("%d ", StackTop(&st));
//		//ɾ��ջ��
//		StackPop(&st);
//	}
//	StackDestroy(&st);
//}
//
//void TestStack3()
//{
//	ST st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	StackPush(&st, 4);
//	int size = StackSize(&st);
//	printf("%d", size);
//	StackDestroy(&st);
//}
//
//
//int main()
//{
//	//TestStack1();
//	//TestStack2();
//	TestStack3();
//	return 0;
//}
//
