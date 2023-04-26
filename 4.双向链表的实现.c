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

//初始化
LTNode* ListInit();

//打印
void ListPrint(LTNode* phead);

//尾插
void ListPushBack(LTNode* phead, LTDateType x);

//尾删
void ListPopBack(LTNode* phead);

//头插
void ListPushFront(LTNode* phead, LTDateType x);

//头删
void ListPopFront(LTNode* phead);

//找
LTNode* ListFind(LTNode* phead, LTDateType x);

//在pos之前插入x
void ListInsert(LTNode* pos, LTDateType x);

//在pos位置删除
void ListErase(LTNode* pos);

//销毁加制空
void ListDestroy(LTNode* phead);


#define _CRT_SECURE_NO_WARNINGS 1

#include "List.h"

//初始化
LTNode* ListInit()
{
	//哨兵位头节点
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//开辟新节点并放入数据
LTNode* BuyListNode(LTDateType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

//打印
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

//尾插
void ListPushBack(LTNode* phead, LTDateType x)
{
	////哨兵位头节点还在
	//assert(phead);
	////尾部就是头部的prev
	//LTNode* tail = phead->prev;
	//LTNode* newnode = BuyListNode(x);
	////tail和newnode链接
	//tail->next = newnode;
	//newnode->prev = tail;
	////newnode和phead链接
	//newnode->next = phead;
	//phead->prev = newnode;
	ListInsert(phead, x);
}

//尾删
void ListPopBack(LTNode* phead)
{
	////phead不为空
	//assert(phead);
	////说明链表为空 phead->next指向自己
	////只有一个哨兵位的头节点 不能再删了
	//assert(phead->next != phead);
	//LTNode* tail = phead->prev;
	//tail->prev->next = phead;
	//phead->prev = tail->prev;
	//free(tail);
	ListErase(phead->prev);
}

//头插
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

//头删
void ListPopFront(LTNode* phead)
{
	//assert(phead);
	////防止删除哨兵位
	//assert(phead->next != phead);
	//LTNode* next = phead->next;
	//LTNode* nextNext = next->next;
	//phead->next = nextNext;
	//nextNext->prev = phead;
	//free(next);
	ListErase(phead->next);
}

//找
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

//在pos之前插入x
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

//在pos位置删除
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

//销毁
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
	//里面制空要传二级指针才能改变
	//所以要在外面制空 或者写一个大函数里面制空
	phead = NULL;
}

//销毁加制空
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
//	//删除2
//	LTNode* pos = ListFind(plist, 2);
//	if (pos)
//		ListErase(pos);
//	else
//		printf("无此数据,删除失败\n");
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


//顺序表和链表的区别
//这两个结构各有优势
//很难说谁更优
//严格来说他们说 相辅相成的两个结构
//
//顺序表
//优点
//1.支持随机访问 需要随机访问结构支持算法可以很好的适用
//2.cpu高速缓存命中率更高
//
//缺点:
//1.头部中部插入删除时间效率低 O(N)
//2.连续的物理空间 空间不够了以后需要增容
//增容有一定程度消耗
//为了避免频繁增容 一般我们都按倍数去增
//用不完可能存在一定的空间浪费
//
//链表(双向带头循环链表):
//优点:
//1.任意位置插入删除效率高 O(1)
//2.按需申请释放空间
//缺点:
//1.不支持随机访问(用下标访问)
//意味着:一些排序 二分查找等在这种
//结构上不适用
//2.链表存储一个值 同时要存储链接指针
//也有一定的消耗
//3.cpu高速缓存命中率更低

#include "List.h"

void TestList1()
{
	//初始化 头部为plist
	LTNode* plist = ListInit();
	//尾插1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//打印1 2 3 4
	ListPrint(plist);
}

void TestList2()
{
	//初始化 头部为plist
	LTNode* plist = ListInit();
	//尾插1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//尾删2次
	ListPopBack(plist);
	ListPopBack(plist);
	//打印1 2
	ListPrint(plist);
}

TestList3()
{
	//初始化 头部为plist
	LTNode* plist = ListInit();
	//头插1 2 3 4
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	//打印4 3 2 1
	ListPrint(plist);
}

TestList4()
{
	//初始化 头部为plist
	LTNode* plist = ListInit();
	//尾插1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//头删2次
	ListPopFront(plist);
	ListPopFront(plist);
	//打印3 4
	ListPrint(plist);
}

TestList5()
{
	//初始化 头部为plist
	LTNode* plist = ListInit();
	//尾插1 2 3 2 4 2
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 2);
	ListPushBack(plist, 4);
	ListPushBack(plist, 2);
	//查找3
	//把第一个3改成30
	LTNode* pos = ListFind(plist, 3);
	int i = 1;
	if (pos)
	{
		printf("第%d个pos节点:%p->%d\n", i++, pos, pos->data);
		LTNode* ppos = pos;
		while (ppos)
		{
			//后一个位置继续开始找
			ppos = ListFind(ppos->next, 3);
			if (ppos == pos)
				break;
			printf("第%d个pos节点:%p->%d\n", i++, ppos, pos->data);
		}
		if (pos)
			pos->data = 30;
		else
			printf("未找到此数据 修改失败\n");
	}
	else
	{
		printf("未找到此数据\n");
	}
	//打印1 2 30 2 4 2
	ListPrint(plist);
	printf("\n");
	//查找2
	//把第二个2改成20
	//3个2的地址
	pos = ListFind(plist, 2);
	if (pos)
	{
		i = 1;
		printf("第%d个pos节点:%p->%d\n", i++, pos, pos->data);
		LTNode* ppos = pos;
		while (ppos)
		{
			//后一个位置继续开始找
			ppos = ListFind(ppos->next, 2);
			if (ppos == pos)
				break;
			if (ppos && i == 2)
				ppos->data = 20;
			printf("第%d个pos节点:%p->%d\n", i++, ppos, pos->data);
		}
	}
	//打印1 2 30 20 4 2
	ListPrint(plist);
	printf("\n");
	//查找100
	pos = ListFind(plist, 100);
	i = 1;
	if (pos)
	{
		printf("第%d个pos节点:%p->%d\n", i++, pos, pos->data);
		LTNode* ppos = pos;
		while (ppos)
		{
			//后一个位置继续开始找
			ppos = ListFind(ppos->next, 3);
			if (ppos == pos)
				break;
			printf("第%d个pos节点:%p->%d\n", i++, ppos, pos->data);
		}
	}
	else
	{
		printf("未找到此数据\n");
	}
}

TestList6()
{
	//初始化 头部为plist
	LTNode* plist = ListInit();
	//尾插1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//在2前面插入10
	LTNode* pos = ListFind(plist, 2);
	if (pos)
		ListInsert(pos, 10);
	else
		printf("无该数据 插入失败\n");
	//打印1 10 2 3 4
	ListPrint(plist);
	printf("\n");

	//在100前面插入10
	pos = ListFind(plist, 100);
	if (pos)
		ListInsert(pos, 10);
	else
		printf("无该数据 插入失败\n");
	//打印1 10 2 3 4
	ListPrint(plist);
}

TestList7()
{
	//初始化 头部为plist
	LTNode* plist = ListInit();
	//尾插3 2 1
	ListPushBack(plist, 3);
	ListPushBack(plist, 2);
	ListPushBack(plist, 1);
	//打印3 2 1
	ListPrint(plist);
	//头插4 5 6
	ListPushFront(plist, 4);
	ListPushFront(plist, 5);
	ListPushFront(plist, 6);
	//打印6 5 4 3 2 1
	ListPrint(plist);
}

TestList8()
{
	//初始化 头部为plist
	LTNode* plist = ListInit();
	//尾插1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//删除2
	LTNode* pos = ListFind(plist, 2);
	if (pos)
	{
		ListErase(pos);
	}
	else
		printf("无此数据 删除失败\n");
	//打印1 3 4
	ListPrint(plist);
	printf("\n");
	//删除100
	pos = ListFind(plist, 100);
	if (pos)
	{
		ListErase(pos);
	}
	else
		printf("无此数据 删除失败\n");
	//打印1 3 4
	ListPrint(plist);
}
TestList9()
{
	//初始化 头部为plist
	LTNode* plist = ListInit();
	//尾插1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//打印1 2 3 4
	ListPrint(plist);
	//头删1次
	ListPopFront(plist);
	//打印2 3 4
	ListPrint(plist);
	//尾删1次
	ListPopBack(plist);
	//打印2 3
	ListPrint(plist);
}

TestList10()
{
	//初始化 头部为plist
	LTNode* plist = ListInit();
	//尾插1 2 3 4 
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//打印1 2 3 4
	ListPrint(plist);
	//销毁
	ListDestroy(plist);
	plist = NULL;
	//链表为空 打印不了 assert断言
	ListPrint(plist);
}

int main()
{
	//TestList1();//测试尾插
	//TestList2();//测试尾删
	//TestList3();//测试头插
	//TestList4();//测试头删
	//TestList5();//测试查找/修改
	//TestList6();//测试在pos之前插入
	//TestList7();//测试在pos之前插入实现后复用头插和尾插
	//TestList8();//测试在pos位置删除
	//TestList9();//测试在pos位置删除实现后复用头删和尾删
	//TestList10();//测试销毁加制空
	return 0;
}
