//#pragma once
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//
////前置声明
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
////深度优先遍历
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
////总结点数
//int TreeSize(BTNode* root)
//{
//	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
////叶子的结点个数
//int TreeLeafSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	//是叶子返回1
//	if (root->left == NULL && root->right == NULL)
//		return 1;
//	//不是叶子往下遍历
//	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
//}
//
////层序遍历 广度优先遍历
////队列 先进先出
////核心思路就是:上一层带下一层
////把队列代码拿过来
//void LevelOrder(BTNode* root)
//{
//	Queue q;
//	QueueInit(&q);
//	if (root)
//		QueuePush(&q, root);
//	while (!QueueEmpty(&q))
//	{
//		//队头标记 然后删
//		BTNode* front = QueueFront(&q);
//		QueuePop(&q);
//		printf("%c ", front->data);
//		//不为空 就放入队列 把下一层放进来
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
////先删除左数 再删除右树 再删根 后序遍历
//void DestroyTree(BTNode** root)
//{
//	//要改变root 把root制空 传二级指针
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