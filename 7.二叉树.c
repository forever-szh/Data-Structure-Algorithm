//#pragma once
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
////ǰ������
//struct BinaryTreeNode;
//
//typedef struct BinaryTreeNode* QDataType;
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
//#define _CRT_SECURE_NO_WARNINGS 1
//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include "Queue.h"
//
//typedef char BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	struct BinaryTreeNode* left;
//	struct BinaryTreeNode* right;
//	BTDataType data;
//}BTNode;
//
////������ȱ���
//void PrevOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	printf("%c ", root->data);
//	PrevOrder(root->left);
//	PrevOrder(root->right);
//}
//
//void InOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	InOrder(root->left);
//	printf("%c ", root->data);
//	InOrder(root->right);
//}
//
//void PostOrder(BTNode* root)
//{
//	if (root == NULL)
//	{
//		printf("NULL ");
//		return;
//	}
//	PostOrder(root->left);
//	PostOrder(root->right);
//	printf("%c ", root->data);
//}
//
////�ܽ����
//int TreeSize(BTNode* root)
//{
//	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
////Ҷ�ӵĽ�����
//int TreeLeafSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	//��Ҷ�ӷ���1
//	if (root->left == NULL && root->right == NULL)
//		return 1;
//	//����Ҷ�����±���
//	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
//}
//
////������� ������ȱ���
////���� �Ƚ��ȳ�
////����˼·����:��һ�����һ��
////�Ѷ��д����ù���
//void LevelOrder(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	if (root)
//		QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		//��ͷ��� Ȼ��ɾ
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		printf("%c ", front->data);
//		//��Ϊ�� �ͷ������ ����һ��Ž���
//		if (front->left)
//		{
//			QueuePush(&q, front->left);
//		}
//		if (front->right)
//		{
//			QueuePush(&q, front->right);
//		}
//	}
//	printf("\n");
//	QueueDestroy(&q);
//}
//
////��ɾ������ ��ɾ������ ��ɾ�� �������
//void DestroyTree(BTNode** root)
//{
//	//Ҫ�ı�root ��root�ƿ� ������ָ��
//	if (*root == NULL)
//		return;
//	DestroyTree((*root)->left);
//	DestroyTree((*root)->right);
//	free(*root);
//	*root = NULL;
//}
//
//int main()
//{
//	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
//	A->data = 'A';
//	A->left = NULL;
//	A->right = NULL;
//
//	BTNode* B = (BTNode*)malloc(sizeof(BTNode));
//	B->data = 'B';
//	B->left = NULL;
//	B->right = NULL;
//
//	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
//	C->data = 'C';
//	C->left = NULL;
//	C->right = NULL;
//
//	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
//	D->data = 'D';
//	D->left = NULL;
//	D->right = NULL;
//
//	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
//	E->data = 'E';
//	E->left = NULL;
//	E->right = NULL;
//
//	A->left = B;
//	A->right = C;
//	B->left = D;
//	B->right = E;
//
//	PrevOrder(A);
//	printf("\n");
//
//	InOrder(A);
//	printf("\n");
//
//	PostOrder(A);
//	printf("\n");
//
//	LevelOrder(A);
//	printf("\n");
//
//	printf("ATreeSize=%d\n", TreeSize(A));
//	printf("BTreeSize=%d\n", TreeSize(B));
//	printf("ATreeLeafSize=%d\n", TreeLeafSize(A));
//	printf("BTreeLeafSize=%d\n", TreeLeafSize(A));
//	return 0;
//}