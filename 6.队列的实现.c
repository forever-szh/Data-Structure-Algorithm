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
////把QueueNode指针放到一个结构体里面
////这样不需要传二级指针 传结构体地址就可以
////把两个指针包在结构体里面 用结构体访问修改指针
//typedef struct Queue
//{
//	QueueNode* head;
//	//只尾插 不尾删 可以定义尾指针
//	QueueNode* tail;
//	//size_t _size;
//	//可以在结构体内实现 或者就在QueueSize内定义一个n
//}Queue;
//
////初始化
//void QueueInit(Queue* pq);
//
////销毁
//void QueueDestroy(Queue* pq);
//
////队尾插入
//void QueuePush(Queue* pq, QDataType x);
//
////队头删除
//void QueuePop(Queue* pq);
//
////返回队头
//QDataType QueueFront(Queue* pq);
//
////返回队尾
//QDataType QueueBack(Queue* pq);
//
////队列大小
//int QueueSize(Queue* pq);
//
////队列是否为空
//bool QueueEmpty(Queue* pq);
//
//
//
////Queue.c
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "Queue.h"
//
////初始化
//void QueueInit(Queue* pq)
//{
//	assert(pq);
//	pq->head = NULL;
//	pq->tail = NULL;
//}
//
////销毁
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
////队尾插入
//void QueuePush(Queue* pq, QDataType x)
//{
//	assert(pq);
//	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
//	newnode->data = x;
//	newnode->next = NULL;
//	if (pq->head == NULL)
//	{
//		//头为空 头尾都是空
//		pq->head = pq->tail = newnode;
//	}
//	else
//	{
//		//不为空 尾部的next指向newnode
//		//最后newnode变成尾部
//		pq->tail->next = newnode;
//		pq->tail = newnode;
//	}
//}
//
////队头删除
//void QueuePop(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	QueueNode* next = pq->head->next;
//	free(pq->head);
//	pq->head = next;
//	//注意 删完之后 tail还没有走
//	//最后删完了 tail变为了野指针
//	//所以当头为空的时候 尾也要变为空
//	if (pq->head == NULL)
//		pq->tail == NULL;
//}
//
////返回队头
//QDataType QueueFront(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->head->data;
//}
//
////返回队尾
//QDataType QueueBack(Queue* pq)
//{
//	assert(pq);
//	assert(!QueueEmpty(pq));
//	return pq->tail->data;
//}
//
////队列大小
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
////队列是否为空
//bool QueueEmpty(Queue* pq)
//{
//	assert(pq);
//	//空的 为真 返回true
//	//不空 为假 返回false
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
//	printf("队头:%d\n队尾:%d\n", front, back);
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
//	printf("栈的大小:%d\n", size);
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