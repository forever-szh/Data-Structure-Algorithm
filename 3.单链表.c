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
////打印链表
//void SListPrint(SLTNode* phead);
//
////尾插
//void SListPushBack(SLTNode** pphead, SLTDateType x);
//
////头插
//void SListPushFront(SLTNode** pphead, SLTDateType x);
//
////尾删
//void SListPopBack(SLTNode** pphead);
//
////头删
//void SListPopFront(SLTNode** pphead);
//
////查找
//SLTNode* SListFind(SLTNode* phead, SLTDateType x);
//
////在pos位置之前去插入一个节点
//void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
//
////在pos之后插入一个节点 这个更适合 也更简单
//void SListInsertAfter(SLTNode* pos, SLTDateType x);
//
////在pos位置删除
//void SListErase(SLTNode** pphead, SLTNode* pos);
//
////在pos之后的位置删除
//void SListEraseAfter(SLTNode* pos);
//
////销毁
//void SListDestroy(SLTNode** pphead);
//
//
////SList.c
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "SList.h"
//
////申请一个节点
//SLTNode* BuyListNode(SLTDateType x)
//{
//	//先申请
//	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
//	if (newnode == NULL)
//	{
//		printf("malloc fail\n");
//		exit(-1);
//	}
//	//放数据
//	newnode->data = x;
//	//尾部放空指针
//	newnode->next = NULL;
//	return newnode;
//}
//
////打印
//void SListPrint(SLTNode* phead)
//{
//	//结构体指针 访问next
//	SLTNode* cur = phead;
//	while (cur != NULL)
//	{
//		printf("%d->", cur->data);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//}
//
////尾插
//void SListPushBack(SLTNode** pphead, SLTDateType x)
//{
//	//如果传的是plist 会提醒
//	//头指针的地址不可能为空
//	//就算是空链表 空指针的地址也不为空
//	//如果你传的是plist 那么&plist为空
//	//防止传一级指针 这个地方应该传二级指针
//	assert(pphead);
//	SLTNode* newnode = BuyListNode(x);
//	if (*pphead == NULL)
//	{
//		//如果传过来的是空指针 也就是说里面没有数据
//		//相当于把这个结构体作为首个指针
//		*pphead = newnode;
//	}
//	//int->int*
//	//int*->int**
//	else
//	{
//		//找到尾节点
//		SLTNode* tail = *pphead;
//		while (tail->next != NULL)
//		{
//			//尾节点说明next指针为空
//			//通过循环找到
//			tail = tail->next;
//		}
//		//再把新申请的地址给尾节点的next指针
//		tail->next = newnode;
//	}
//}
//
////头插
//void SListPushFront(SLTNode** pphead, SLTDateType x)
//{
//	assert(pphead);
//	//申请
//	SLTNode* newnode = BuyListNode(x);
//	//先把第二个位置的指针给第一个位置的指针next
//	newnode->next = *pphead;
//	//再让新申请的节点作为头地址
//	*pphead = newnode;
//}
//
////尾删
////当链表只有1个数据时 prev是前1个 会是空指针 这时对prev进行解引用
////会报错 因此要分类讨论
//void SListPopBack(SLTNode** pphead)
//{
//	assert(pphead);
//	assert(*pphead != NULL);
//	//说明这里就只有1个节点了 头部的next指针为NULL
//	if ((*pphead)->next == NULL)
//	{
//		//直接把这1个数据还给系统
//		free(*pphead);
//		*pphead = NULL;
//	}
//	//说明节点数量在1个以上
//	else
//	{
//		SLTNode* prev = NULL;
//		SLTNode* tail = *pphead;
//		while (tail->next != NULL)//while(tail->next)也可以 
//		{
//			//给到前面一个再往下走
//			//这样prev就为尾部的前一个
//			prev = tail;
//			tail = tail->next;
//		}
//		free(tail);
//		tail = NULL;
//		//没有把前一个的next指针变为空指针的话
//		//等到tail出函数销毁后 这个next指针会指向一块已经还给系统的空间
//		//那么的话 这个next指针会变为野指针 非法访问
//		prev->next = NULL;
//	}
//}
//
////头删
//void SListPopFront(SLTNode** pphead)
//{
//	assert(pphead);
//	//当plist为NULL的时候 解引用会报错 
//	assert(*pphead != NULL);
//	//把plist搬到下一个 用next存起来
//	SLTNode* next = (*pphead)->next;
//	//释放
//	free(*pphead);
//	//再把下一个变为plist
//	*pphead = next;
//}
//
////查找 也可以修改 找到后把修改值赋给data
//SLTNode* SListFind(SLTNode* phead, SLTDateType x)
//{
//	//头部拿到
//	SLTNode* cur = phead;
//	while (cur)
//	{
//		//遍历
//		if (cur->data == x)
//		{
//			return cur;
//		}
//		//没找到就一直往后拿
//		else
//		{
//			cur = cur->next;
//		}
//	}
//	//最后都没找到 返回空
//	return NULL;
//}
//
////在pos位置之前去插入一个节点
//void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
//{
//	assert(pphead);
//	assert(pos);
//	SLTNode* newnode = BuyListNode(x);
//	//如果就是头插
//	if (*pphead == pos)
//	{
//		//原来的头部给新的节点的next
//		newnode->next = *pphead;
//		//新的节点变为plist
//		*pphead = newnode;
//	}
//	//不是头插
//	else
//	{
//		//找到pos的前一个位置
//		SLTNode* posPrev = *pphead;
//		while (posPrev->next != pos)
//		{
//			//不是pos前一个位置就往下走
//			posPrev = posPrev->next;
//		}
//		//posPrev newnode pos的连接
//		posPrev->next = newnode;
//		newnode->next = pos;
//	}
//}
//
////在pos之后插入一个节点 这个更适合 也更简单
//void SListInsertAfter(SLTNode* pos, SLTDateType x)
//{
//	//pos为空 插入不了
//	assert(pos);
//	//先申请一个新节点
//	SLTNode* newnode = BuyListNode(x);
//	//不定义
//	////先把pos的下一个地址给到newnode
//	//newnode->next = pos->next;
//	////再把newnode的地址给到pos
//	//pos->next = newnode;
//	//定义
//	SLTNode* posNext = pos->next;
//	pos->next = newnode;
//	newnode->next = posNext;
//}
//
////在pos位置删除
//void SListErase(SLTNode** pphead, SLTNode* pos)
//{
//	assert(pphead);
//	assert(pos);
//	//头删特殊处理
//	if (*pphead == pos)
//	{
//		//plist指向下一个
//		*pphead = pos->next;
//		//删除pos 也就是头部
//		free(pos);
//		//或者直接调用头删
//		//SListPopFront(pphead);
//	}
//	//不是头删 要找上一个 下一个可用next得到
//	else
//	{
//		//找前一个 从头开始
//		SLTNode* prev = *pphead;
//		//前一个next指向不是pos 就接着往下走
//		while (prev->next != pos)
//		{
//			prev = prev->next;
//		}
//		//pos的下一个赋给pos的上一个
//		prev->next = pos->next;
//		//删除pos
//		free(pos);
//		pos = NULL;
//	}
//}
//
////在pos之后的位置删除
//void SListEraseAfter(SLTNode* pos)
//{
//	assert(pos);
//	//pos为尾部有问题
//	assert(pos->next);
//	//pos后一个地址
//	SLTNode* next = pos->next;
//	//pos后两个地址变为pos后一个的地址
//	pos->next = next->next;
//	//删除后一个
//	free(next);
//	next = NULL;
//}
//
////销毁
//void SListDestroy(SLTNode** pphead)
//{
//	assert(pphead);
//	SLTNode* cur = *pphead;
//	while (cur)
//	{
//		//先保存下一个
//		SLTNode* next = cur->next;
//		//再释放
//		//如果先释放 再保存 释放的地址会是随机值 找不到下一个
//		free(cur);
//		//下一个为开头
//		cur = next;
//	}
//	//销毁完
//	*pphead = NULL;
//}
//
////test.c
//#define _CRT_SECURE_NO_WARNINGS 1
//
////顺序表
////缺陷:
////1.空间不够用了需要扩容 扩容是要付出代价
////2.避免频繁扩容 满了就扩2倍 可能就会导致一定的空间浪费
////3.顺序表要求数据从开始位置连续存储 那么我们在头部或者中间位置插入删除数据
////就需要挪动数据 效率不高
////优点:
////1.支持随机访问
//
////针对顺序表缺陷 就设计出的链表
//
////链表
////优点:
////1.按需申请空间 不用了就释放空间(更合理的使用了空间)
////2.头部中间插入删除数据 不需要挪动数据 不存空间浪费
////缺点:
////1.每个一个数据 都要存一个指针去链接后面数据节点不支持随机访问
////用下标直接访问第i个
//
//#include "SList.h"
//
////void TestSList1()
////{
////	SLTNode* plist = NULL;
////	//空指针去找尾部 找不了
////	//plist直接拷过去 不会影响phead 实参 形参 要传地址
////	//虽然是指针 你想改变的是整个plist 你要传plist的地址
////	//再在函数里面解引用改变
////	//想改变int  要传int*  解引用改变
////	//想改变int* 要传int** 解引用改变
////	//尾插1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//打印1 2 3 4 NULL
////	SListPrint(plist);
////
////	//头插1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////	//打印4 3 2 1 1 2 3 4 NULL
////	SListPrint(plist);
////}
////
////void TestSList2()
////{
////	SLTNode* plist = NULL;
////	//头插1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////
////	//头部删除 如果删第5次 会报错
////	SListPopBack(&plist);
////	SListPopBack(&plist);
////	SListPopBack(&plist);
////	SListPopBack(&plist);
////	//打印NULL
////	SListPrint(plist);
////}
////
////void TestSList3()
////{
////	SLTNode* plist = NULL;
////	//头插1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////
////	//头删一次 打印一次
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
////	//头插1 2 3 2 4 2 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 4);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 4);
////
////	//查找2
////	//3个2的地址
////	SLTNode* pos = SListFind(plist, 2);
////	int i = 1;
////	while (pos)
////	{
////		printf("第%d个pos节点:%p->%d\n", i++, pos, pos->data);
////		//后一个位置继续开始找
////		pos = SListFind(pos->next, 2);
////	}
////
////	//修改
////	pos = SListFind(plist, 3);
////	if (pos)
////	{
////		//如果找到3
////		//把3修改成30
////		pos->data = 30;
////	}
////	//打印
////	SListPrint(plist);
////}
////
////void TestSList5()
////{
////	SLTNode* plist = NULL;
////	//头插1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////	//先找到3
////	SLTNode* pos = SListFind(plist, 3);
////	if (pos)
////	{
////		//再在3前面插入30
////		SListInsert(&plist, pos, 30);
////	}
////	//打印
////	SListPrint(plist);
////
////	//先找到1
////    pos = SListFind(plist, 1);
////	if (pos)
////	{
////		//再在1前面插入10
////		SListInsert(&plist, pos, 10);
////	}
////	//打印
////	SListPrint(plist);
////
////	//如果是头插
////	//先找到4
////	pos = SListFind(plist, 4);
////	if (pos)
////	{
////		//再在4前面插入40
////		SListInsert(&plist, pos, 40);
////	}
////	//打印
////	SListPrint(plist);
////	//找到2
////	pos = SListFind(plist, 2);
////	if (pos)
////	{
////		//在2后面插入20
////		SListInsertAfter(pos, 20);
////	}
////	//打印
////	SListPrint(plist);
////	//删除2之后
////	pos = SListFind(plist, 2);
////	SListEraseAfter(pos);
////	//打印
////	SListPrint(plist);
////	//删除4
////	pos = SListFind(plist, 4);
////	SListErase(&plist,pos);
////	//打印
////	SListPrint(plist);
////}
////void TestSList6()
////{
////	SLTNode* plist = NULL;
////	//头插1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////	//打印1 2 3 4
////	SListPrint(plist);
////	//销毁
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
////	//定义一个结构体指针
////	SLTNode* plist = NULL;
////	//尾插1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//打印1 2 3 4 NULL
////	SListPrint(plist);
////}
////
////void TestSList2()
////{
////	//定义一个结构体指针
////	SLTNode* plist = NULL;
////	//头插1 2 3 4
////	SListPushFront(&plist, 1);
////	SListPushFront(&plist, 2);
////	SListPushFront(&plist, 3);
////	SListPushFront(&plist, 4);
////	//打印4 3 2 1 NULL
////	SListPrint(plist);
////}
////
////void TestSList3()
////{
////	//定义一个结构体指针
////	SLTNode* plist = NULL;
////	//尾插1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//打印1 2 3 4 NULL
////	SListPrint(plist);
////	//尾部删除2次
////	SListPopBack(&plist);
////	SListPopBack(&plist);
////	//打印 1 2 NULL
////	SListPrint(plist);
////}
////
////
////void TestSList4()
////{
////	//定义一个结构体指针
////	SLTNode* plist = NULL;
////	//尾插1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//打印1 2 3 4 NULL
////	SListPrint(plist);
////	//头部删除2次
////	SListPopFront(&plist);
////	SListPopFront(&plist);
////	//打印 3 4 NULL
////	SListPrint(plist);
////}
////
////void TestSList5()
////{
////	//定义一个结构体指针
////	SLTNode* plist = NULL;
////	//尾插1 2 3 4 2 4 2
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 4);
////	SListPushBack(&plist, 2);
////	//查找3
////	SLTNode* Find = SListFind(plist, 3);
////	if (Find != NULL)
////		printf("找到了\n");
////	else
////		printf("找不到\n");
////	//查找100
////	Find = SListFind(plist, 100);
////	if (Find != NULL)
////		printf("找到了\n");
////	else
////		printf("找不到\n");
////	//查找3并且修改成30
////	Find = SListFind(plist, 3);
////	if (Find != NULL)
////	{
////		Find->data = 30;
////		//打印1 2 30 2 4 2 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("找不到 无法修改\n");
////	//查找100并且修改成10
////	Find = SListFind(plist, 100);
////	if (Find != NULL)
////	{
////		Find->data = 10;
////		//打印1 20 3 4 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("找不到 无法修改\n");
////	//查找2
////	//3个2的地址
////	SLTNode* pos = SListFind(plist, 2);
////	int i = 1;
////	while (pos)
////	{
////		printf("第%d个pos节点:%p->%d\n", i++, pos, pos->data);
////		//后一个位置继续开始找
////		pos = SListFind(pos->next, 2);
////	}
////}
////
////void TestSList6()
////{
////	//定义一个结构体指针
////	SLTNode* plist = NULL;
////	//尾插1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//打印1 2 3 4 NULL
////	SListPrint(plist);
////	//在2的前面插入20
////	SLTNode* pos = SListFind(plist, 2);
////	if (pos != NULL)
////	{
////		SListInsert(&plist, pos, 20);
////		SListPrint(plist);
////	}
////	else
////		printf("未找到相关数据 插入失败\n");
////	//在100前面插入10
////	pos= SListFind(plist, 100);
////	if (pos != NULL)
////	{
////		SListInsert(&plist, pos, 10);
////		SListPrint(plist);
////	}
////	else
////		printf("未找到相关数据 插入失败\n");
////}
////void TestSList7()
////{
////	//定义一个结构体指针
////	SLTNode* plist = NULL;
////	//尾插1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//打印1 2 3 4 NULL
////	SListPrint(plist);
////	//找到2并在后面插入20
////	SLTNode* pos = SListFind(plist, 2);
////	if (pos != NULL)
////	{
////		SListInsertAfter(pos, 20);
////		//打印1 2 20 3 4 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("未找到该数据 插入失败\n");
////	//找到100并在后面插入10
////	pos = SListFind(plist, 100);
////	if (pos != NULL)
////	{
////		SListInsertAfter(pos, 10);
////		SListPrint(plist);
////	}
////	else
////		printf("未找到该数据 插入失败\n");
////}
////
////void TestSList8()
////{
////	//定义一个结构体指针
////	SLTNode* plist = NULL;
////	//尾插1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//打印1 2 3 4 NULL
////	SListPrint(plist);
////	//删除2
////	SLTNode* pos = SListFind(plist, 2);
////	if (pos != NULL)
////	{
////		SListErase(&plist, pos);
////		//打印1 3 4 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("未找到该数据 删除失败\n");
////	//删除100
////	pos = SListFind(plist, 100);
////	if (pos != NULL)
////	{
////		SListErase(&plist, pos);
////		SListPrint(plist);
////	}
////	else
////		printf("未找到该数据 删除失败\n");
////}
////
////void TestSList9()
////{
////	//定义一个结构体指针
////	SLTNode* plist = NULL;
////	//尾插1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//打印1 2 3 4 NULL
////	SListPrint(plist);
////	//删除2之后的 也就是3
////	SLTNode* pos = SListFind(plist, 2);
////	if (pos != NULL)
////	{
////		SListEraseAfter(pos);
////		//打印1 2 4 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("无此数据 删除失败\n");
////	//删除100之后的
////	pos = SListFind(plist, 100);
////	if (pos != NULL)
////	{
////		SListEraseAfter(pos);
////		//打印1 2 4 NULL
////		SListPrint(plist);
////	}
////	else
////		printf("无此数据 删除失败\n");
////}
////
////void TestSList10()
////{
////	//定义一个结构体指针
////	SLTNode* plist = NULL;
////	//尾插1 2 3 4
////	SListPushBack(&plist, 1);
////	SListPushBack(&plist, 2);
////	SListPushBack(&plist, 3);
////	SListPushBack(&plist, 4);
////	//打印1 2 3 4 NULL
////	SListPrint(plist);
////	//销毁
////	SListDestroy(&plist);
////	//打印 NULL
////	SListPrint(plist);
////}
////
////int main()
////{
////	//TestSList1();//测试尾插
////	//TestSList2();//测试头插
////	//TestSList3();//测试尾删
////	//TestSList4();//测试头删
////	//TestSList5();//测试查找和修改
////	//TestSList6();//测试在pos之前插入
////	//TestSList7();//测试在pos之后插入
////	//TestSList8();//测试在pos位置删除
////	//TestSList9();//测试在pos之后删除
////	//TestSList10();//测试销毁
////	return 0;
////}
//
//#include"SList.h"
//
//void Menu()
//{
//	printf("************************************\n");
//	printf("***   1.头插       2.头删        ***\n");
//	printf("***   3.尾插       4.尾删        ***\n");
//	printf("***   5.pos之前插  6.pos之后插   ***\n");
//	printf("***   7.pos位置删  8.pos之后删   ***\n");
//	printf("***   9.查找/修改  10.打印       ***\n");
//	printf("***          0.退出              ***\n");
//	printf("************************************\n");
//	printf("请选择:>");
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
//	//结构体不要定义在循环体里面 不然一直是空指针
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
//			printf("退出程序\n");
//			return 0;
//			break;
//		case SLISTPUSHFRONT:
//			printf("以哪个数字作为结束标志\n");
//			printf("请选择:>");
//			scanf("%d", &n);
//			printf("请输入你要头插的数据 以%d结束:\n", n);
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
//			printf("以哪个数字作为结束标志\n");
//			printf("请选择:>");
//			scanf("%d", &n);
//			printf("请输入你要尾插的数据 以%d结束:\n", n);
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
//				printf("请输入你要在哪个数据前插入数据\n");
//				printf("请选择>:");
//				scanf("%d", &num);
//				printf("请输入你想插入的数据\n");
//				printf("请选择>:");
//				scanf("%d", &x);
//				SLTNode* pos = SListFind(plist, num);
//				if (pos)
//				{
//					SListInsert(&plist, pos, x);
//					break;
//				}
//				else
//					printf("未找到该数据 插入失败 请重新输入\n");
//			}
//			break;
//		case SLISTINSERTAFTER:
//			while (1)
//			{
//				printf("请选择你想要在哪个数据后面插入数据\n");
//				printf("请选择>:");
//				scanf("%d", &num);
//				printf("请输入你想要插入的数据\n");
//				printf("请选择>:");
//				scanf("%d", &x);
//				SLTNode* pos = SListFind(plist, num);
//				if (pos)
//				{
//					SListInsertAfter(pos, x);
//					break;
//				}
//				else
//				{
//					printf("未找到该数据 插入失败 请重新输入\n");
//				}
//			}
//			break;
//		case SLISTERASE:
//			while (1)
//			{
//				printf("请输入你想要删除的数据>:\n");
//				printf("请选择>:");
//				scanf("%d", &num);
//				SLTNode* pos = SListFind(plist, num);
//				if (pos)
//				{
//					SListErase(&plist, pos);
//					break;
//				}
//				else
//					printf("未找到该数据 删除失败 请重新选择\n");
//			}
//			break;
//		case SLISTERASEAFTER:
//			while (1)
//			{
//				printf("请输入你想要删除哪个数据后面的数据\n");
//				printf("请选择>:");
//				scanf("%d", &num);
//				SLTNode* pos = SListFind(plist, num);
//				if (pos)
//				{
//					SListEraseAfter(pos);
//					break;
//				}
//				else
//					printf("未找到该数据 删除失败 请重新选择\n");
//			}
//			break;
//		case SLISTFIND:
//			while (1)
//			{
//				printf("请输入你想要查找的数据\n");
//				printf("请选择>:");
//				scanf("%d", &num);
//				SLTNode* pos = SListFind(plist, num);
//				if (pos)
//				{
//					printf("找到了\n");
//					printf("修不修改数据(1修改/0不修改)\n");
//					printf("请选择>:");
//					scanf("%d", &num);
//					if (num == 1)
//					{
//						printf("请输入改后的数据\n");
//						printf("请选择>:");
//						scanf("%d", &x);
//						pos->data = x;
//						printf("修改成功\n");
//					}
//					break;
//				}
//				else
//					printf("查找数据不存在 请重新选择\n");
//			}
//			break;
//		case SLISTPRINT:
//			SListPrint(plist);
//			break;
//		default:
//			printf("输入错误 请重新输入\n");
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
