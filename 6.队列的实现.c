////Queue.h
//#pragma once
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
//typedef int QDataType;
//
//typedef struct QueueNode
//{
//	struct QueueNode* next;
//	QDataType data;
//}QueueNode;
//
////��QueueNodeָ��ŵ�һ���ṹ������
////��������Ҫ������ָ�� ���ṹ���ַ�Ϳ���
////������ָ����ڽṹ������ �ýṹ������޸�ָ��
//typedef struct Queue
//{
//	QueueNode* head;
//	//ֻβ�� ��βɾ ���Զ���βָ��
//	QueueNode* tail;
//	//size_t _size;
//	//�����ڽṹ����ʵ�� ���߾���QueueSize�ڶ���һ��n
//}Queue;
//
////��ʼ��
//void QueueInit(Queue* pq);
//
////����
//void QueueDestroy(Queue* pq);
//
////��β����
//void QueuePush(Queue* pq, QDataType x);
//
////��ͷɾ��
//void QueuePop(Queue* pq);
//
////���ض�ͷ
//QDataType QueueFront(Queue* pq);
//
////���ض�β
//QDataType QueueBack(Queue* pq);
//
////���д�С
//int QueueSize(Queue* pq);
//
////�����Ƿ�Ϊ��
//bool QueueEmpty(Queue* pq);
//
//
//
////Queue.c
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "Queue.h"
//
////��ʼ��
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
////����
//void QueueDestroy(Queue* pq)
//{
//	assert(pq);
//	QueueNode* cur = pq->head;
//	while (cur != NULL)
//	{
//		QueueNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pq->head = pq->tail = NULL;
//}
//
////��β����
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
//	newnode->data = x;
//	newnode->next = NULL;
//	if (pq->head == NULL)
//	{
//		//ͷΪ�� ͷβ���ǿ�
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		//��Ϊ�� β����nextָ��newnode
//		//���newnode���β��
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
//
////��ͷɾ��
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	QueueNode* next = pq->head->next;
//	free(pq->head);
//	pq->head = next;
//	//ע�� ɾ��֮�� tail��û����
//	//���ɾ���� tail��Ϊ��Ұָ��
//	//���Ե�ͷΪ�յ�ʱ�� βҲҪ��Ϊ��
//	if (pq->head == NULL)
//		pq->tail == NULL;
//}
//
////���ض�ͷ
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->head->data;
//}
//
////���ض�β
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->tail->data;
//}
//
////���д�С
//int QueueSize(Queue* pq)
//{
//	assert(pq);
//	int n = 0;
//	QueueNode* cur = pq->head;
//	while (cur)
//	{
//		++n;
//		cur = cur->next;
//	}
//	return n;
//}
//
////�����Ƿ�Ϊ��
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	//�յ� Ϊ�� ����true
//	//���� Ϊ�� ����false
//	return pq->head == NULL;
//}
//
////test.c
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "Queue.h"
//
//void TestQueue1()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	while (!QueueEmpty(&q))
//	{
//		QDataType front = QueueFront(&q);
//		printf("%d ", front);
//		QueuePop(&q);
//	}
//	printf("\n");
//	QueueDestroy(&q);
//}
//
//void TestQueue2()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	QueuePop(&q);
//	while (!QueueEmpty(&q))
//	{
//		QDataType front = QueueFront(&q);
//		printf("%d ", front);
//		QueuePop(&q);
//	}
//	printf("\n");
//	QueueDestroy(&q);
//}
//
//TestQueue3()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	int front = QueueFront(&q);
//	int back = QueueBack(&q);
//	printf("��ͷ:%d\n��β:%d\n", front, back);
//}
//
//TestQueue4()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	int size = QueueSize(&q);
//	printf("ջ�Ĵ�С:%d\n", size);
//}
//
//int main()
//{
//	//TestQueue1();
//	//TestQueue2();
//	//TestQueue3();
//	TestQueue4();
//	return 0;
//}