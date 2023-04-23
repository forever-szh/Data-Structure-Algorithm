//
////SeqList.h
//#pragma once
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//typedef int SLDateType;
//
////静态顺序表
//typedef struct SeqList
//{
//	SLDateType* a;
//	int size;//表示数组中存储了多少个有效数据
//	int capacity; //数组实际能存数据的空间容量
//}SL;
//
////接口函数--命名风格是跟着STL走的
//
////初始化
//void SeqListInit(SL* ps);
//
////打印
//void SeqListPrint(SL* ps);
////静态特点:如果满了就不让插入 缺点:给多少的合适呢？这个很难确定
////N给小了不够 N给大了浪费
//
////销毁
//void SeqListDestroy(SL* ps);
//
////尾部插入
//void SeqListPushBack(SL* ps, SLDateType x);
//
////尾部删除
//void SeqListPopBack(SL* ps);
//
////头部插入
//void SeqListPushFront(SL* ps, SLDateType x);
//
////头部删除
//void SeqListPopFront(SL* ps);
//
////检查扩容
//void SeqListCheckCapacity(SL* ps);
//
////找到了返回x位置下标 没有找到返回-1
//int SeqListFind(SL* ps, SLDateType x);
//
////指定pos下标位置插入
//void SeqListInsert(SL* ps, int pos, SLDateType x);
//
////删除pos位置的数据
//void SeqListErase(SL* ps, int pos);
//
//
////SeqList.c
//#define _CRT_SECURE_NO_WARNINGS 1
////
//#include "SeqList.h"
////
////打印
//void SeqListPrint(SL* ps)
//{
//	for (int i = 0; i < ps->size; ++i)
//	{
//		printf("%d ", ps->a[i]);
//	}
//	printf("\n");
//}
////
////初始化
//void SeqListInit(SL* ps)
//{
//	ps->a = NULL;
//	ps->size = ps->capacity = 0;
//}
////
////销毁
//void SeqListDestroy(SL* ps)
//{
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->size = 0;
//	printf("销毁成功\n");
//}
////
////检查是否需要扩容
//void SeqListCheckCapacity(SL* ps)
//{
//	//如果没有空间或者空间不足就扩容
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
////尾部插入
//void SeqListPushBack(SL* ps, SLDateType x)
//{
//	//SeqListCheckCapacity(ps);
//	//ps->a[ps->size] = x;
//	//ps->size++;
//	//尾插可以简化成
//	SeqListInsert(ps, ps->size, x);
//}
////
////尾部删除
//void SeqListPopBack(SL* ps)
//{
//	assert(ps->size > 0);
//	ps->size--;
//}
////
////头部插入
//void SeqListPushFront(SL* ps, SLDateType x)
//{
//	////检查需不需要扩容
//	//SeqListCheckCapacity(ps);
//	////挪动数据
//	//int end = ps->size - 1;
//	//while (end >= 0)
//	//{
//	//	ps->a[end + 1] = ps->a[end];
//	//	--end;
//	//}
//	//ps->a[0] = x;
//	//ps->size++;
//	//头插可以简化成
//	SeqListInsert(ps, 0, x);
//}
////
////头部删除
//void SeqListPopFront(SL* ps)
//{
//	////往前挪再size--
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
////查找 返回下标
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
////指定pos下标位置插入
//void SeqListInsert(SL* ps, int pos, SLDateType x)
//{
//	assert(pos >= 0 && pos <= ps->size);
//	//考虑扩容
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
////删除pos位置的数据
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
//	printf("***   1.头插    2.头删      ***\n");
//	printf("***   3.尾插    4.尾删      ***\n");
//	printf("***   5.pos处插 6.pos处删   ***\n");
//	printf("***   7.查找    8.打印      ***\n");
//	printf("***        0.退出           ***\n");
//	printf("*******************************\n");
//	printf("请选择:>");
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
//			printf("以哪个数字作为结束标志\n");
//			printf("请选择:>");
//			scanf("%d", &n);
//			printf("请输入你要头插的数据 以%d结束:\n", n);
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
//			printf("以哪个数字作为结束标志\n");
//			printf("请选择:>");
//			scanf("%d", &n);
//			printf("请输入你要尾插的数据 以%d结束:\n", n);
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
//			printf("两种模式:1.输入数据 在这个数据前插入 2.输入下标 在这个下标处插入\n");
//			printf("请选择(1或者2)>:");
//			scanf("%d", &n);
//			while (1)
//			{
//				if (n == 1)
//				{
//					printf("请输入数据\n");
//					printf("请选择:>");
//					scanf("%d", &num);
//					int pos = SeqListFind(&s1, num);
//					if (pos != -1)
//					{
//						printf("请输入要插入的数据\n");
//						printf("请选择:>");
//						scanf("%d", &x);
//						SeqListInsert(&s1, pos, x);
//						break;
//					}
//					else
//					{
//						printf("未找到该数据\n");
//						printf("请重新选择\n");
//					}
//				}
//				else
//				{
//					SL* ps = &s1;
//					printf("要插入数据的下标\n");
//					printf("请选择>:");
//					scanf("%d", &pos);
//					if (pos >= 0 && pos <= ps->size)
//					{
//						printf("请输入要插入的数据\n");
//						printf("请选择>:");
//						scanf("%d", &x);
//						SeqListInsert(&s1, pos, x);
//						break;
//					}
//					else
//						printf("该下标不存在 请重新输入\n");
//				}
//			}
//			break;
//		case ERASE:
//			printf("两种模式:1.输入数据 删除这个数据 2.输入下标 删除这个下标对应的数据\n");
//			printf("请选择(1或者2)>:");
//			scanf("%d", &n);
//			while (1)
//			{
//				if (n == 1)
//				{
//					printf("请输入想要删除的数据\n");
//					printf("请选择>:");
//					scanf("%d", &num);
//					int pos = SeqListFind(&s1, num);
//					if (pos != -1)
//					{
//						SeqListErase(&s1, pos);
//						break;
//					}
//					else
//					{
//						printf("未找到该数据\n");
//						printf("请重新选择>:");
//					}
//				}
//				else
//				{
//					SL* ps = &s1;
//					printf("请输入想要删除数据的下标\n");
//					printf("请选择>:");
//					scanf("%d", &pos);
//					if (pos >= 0 && pos <= ps->size)
//					{
//						SeqListErase(&s1, pos);
//						break;
//					}
//					else
//						printf("该下标不存在 请重新输入\n");
//				}
//			}
//			break;
//		case FIND:
//			printf("请输入你需要找的数据\n");
//			printf("请选择>:");
//			scanf("%d", &x);
//			int pos = SeqListFind(&s1, x);
//			if (pos != -1)
//			{
//				printf("需不需要修改数据(1.修改 0.不修改)\n");
//				printf("请选择(1/0)>:");
//				scanf("%d", &num);
//				if (num == 0)
//					printf("该数据的下标为%d\n", pos);
//				else
//				{
//					printf("该数据的下标为%d\n", pos);
//					printf("请输入你想要改后的数据\n");
//					printf("请选择>:");
//					scanf("%d", &x);
//					SL* Find = &s1;
//					Find->a[pos] = x;
//				}
//			}
//			else
//				printf("未找到该数据\n");
//			break;
//		case EXIT:
//			printf("退出程序\n");
//			return 0;
//			break;
//		default:
//			printf("无此选项 请重新输入\n");
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
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//1 2 3 4 5尾插 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//打印 1 2 3 4 5 
////	SeqListPrint(&s1);
////}
////
////void TestSeqList2()
////{
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//1 2 3 4 5头插
////	SeqListPushFront(&s1, 1);
////	SeqListPushFront(&s1, 2);
////	SeqListPushFront(&s1, 3);
////	SeqListPushFront(&s1, 4);
////	SeqListPushFront(&s1, 5);
////	//打印 5 4 3 2 1
////	SeqListPrint(&s1);
////}
////
////void TestSeqList3()
////{
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//1 2 3 4 5尾插 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//尾部删除2次
////	SeqListPopBack(&s1);
////	SeqListPopBack(&s1);
////	//打印 1 2 3
////	SeqListPrint(&s1);
////	//尾部再删除4次 会assert报错
////	SeqListPopBack(&s1);
////	SeqListPopBack(&s1);
////	SeqListPopBack(&s1);
////	SeqListPopBack(&s1);
////}
////
////void TestSeqList4()
////{
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//1 2 3 4 5尾插 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//头部删除2次
////	SeqListPopFront(&s1);
////	SeqListPopFront(&s1);
////	//打印3 4 5
////	SeqListPrint(&s1);
////	//头部再删除4次 assert报错
////	SeqListPopFront(&s1);
////	SeqListPopFront(&s1);
////	SeqListPopFront(&s1);
////	SeqListPopFront(&s1);
////}
////
////void TestSeqList5()
////{
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//1 2 3 4 5尾插 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//查找3
////	int pos = SeqListFind(&s1, 3);
////	if (pos != -1)
////		printf("该数据的下标为%d\n", pos);
////	else
////		printf("没有该数据\n");
////	//查找6
////	pos = SeqListFind(&s1, 6);
////	if (pos != -1)
////		printf("该数据的下标为%d\n", pos);
////	else
////		printf("没有该数据\n");
////	//找到3并改成30
////	pos = SeqListFind(&s1, 3);
////	if (pos != -1)
////	{
////		//定义一个结构体指针
////		SL* Find = &s1;
////		//访问
////		Find->a[pos] = 30;
////	}
////	else
////		printf("没有该数据");
////	//打印1 2 30 4 5
////	SeqListPrint(&s1);
////}
////
////TestSeqList6()
////{
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//尾插1 2 3
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	//打印1 2 3
////	SeqListPrint(&s1);
////	//头插1 2 3
////	SeqListPushFront(&s1, 1);
////	SeqListPushFront(&s1, 2);
////	SeqListPushFront(&s1, 3);
////	//打印3 2 1 1 2 3
////	SeqListPrint(&s1);
////}
////
////TestSeqList7()
////{
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//1 2 3 4 5尾插 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//在下标为2的位置插入20
////	//也就是3的前面插入20
////	SeqListInsert(&s1, 2, 20);
////	//打印1 2 20 3 4 5
////	SeqListPrint(&s1);
////	//如果越界
////	SeqListInsert(&s1, 7, 20);
////	//打印
////	SeqListPrint(&s1);
////}
////
////TestSeqList8()
////{
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//1 2 3 4 5尾插 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//在4的前面插入40
////	//先用pos接收4的下标
////	int pos = SeqListFind(&s1, 4);
////	if (pos != -1)
////		SeqListInsert(&s1, pos, 40);
////	else
////		printf("无此数据");
////	//打印1 2 3 40 4 5
////	SeqListPrint(&s1);
////	//在7的前面插入70
////	//顺序表中没有7
////	pos = SeqListFind(&s1, 7);
////	if (pos != -1)
////		SeqListInsert(&s1, pos, 70);
////	else
////		printf("无此数据 插入失败\n");
////	//打印1 2 3 40 4 5
////	SeqListPrint(&s1);
////}
////
////TestSeqList9()
////{
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//1 2 3 4 5尾插 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//头删2次
////	SeqListPopFront(&s1);
////	SeqListPopFront(&s1);
////	//打印3 4 5
////	SeqListPrint(&s1);
//// 	//再头删4次
////    SeqListPopFront(&s1);
////    SeqListPopFront(&s1);
////    SeqListPopFront(&s1);
////    SeqListPopFront(&s1);
////}
////
////TestSeqList10()
////{
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//1 2 3 4 5尾插 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//删除下标为2的数据
////	//也就是删除3
////	SeqListErase(&s1, 2);
////	//打印1 2 4 5
////	SeqListPrint(&s1);
////	//删除下标为7的数据
////	//越界
////	SeqListErase(&s1, 7);
////}
////
////TestSeqList11()
////{
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//1 2 3 4 5尾插 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//删除4
////	int pos = SeqListFind(&s1, 4);
////	if (pos != -1)
////		SeqListErase(&s1, pos);
////	else
////		printf("无此数据 删除失败\n");
////	//打印1 2 3 5
////	SeqListPrint(&s1);
////	//删除7
////	pos = SeqListFind(&s1, 7);
////	if (pos != -1)
////		SeqListErase(&s1, pos);
////	else
////		printf("无此数据 删除失败\n");
////	//打印1 2 3 5
////	SeqListPrint(&s1);
////}
////
////TestSeqList12()
////{
////	//定义一个结构体 
////	SL s1;
////	//传址初始化结构体
////	SeqListInit(&s1);
////	//1 2 3 4 5尾插 
////	SeqListPushBack(&s1, 1);
////	SeqListPushBack(&s1, 2);
////	SeqListPushBack(&s1, 3);
////	SeqListPushBack(&s1, 4);
////	SeqListPushBack(&s1, 5);
////	//打印1 2 3 4 5
////	SeqListPrint(&s1);
////	//销毁
////	SeqListDestroy(&s1);
////	//只打印\n
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