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
//	int top;//栈顶的位置
//	int capacity;
//}ST;
//
////初始化
//void StackInit(ST* ps);
//
////销毁
//void StackDestroy(ST* ps);
//
////栈顶插入
//void StackPush(ST* ps, STDataType x);
//
////栈底删除
//void StackPop(ST* ps);
//
////栈顶数据
//STDataType StackTop(ST* ps);
//
////栈的大小
//int StackSize(ST* ps);
//
////栈是否为空
//bool StackEmpty(ST* ps);
//
//
////stack.c
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "Stack.h"
//
////初始化
//void StackInit(ST* ps)
//{
//	assert(ps);
//	ps->a = NULL;
//	ps->top = 0;
//	//初始化 top给的是0 意味着top指向栈顶数据的下一个
//	//先放数据 再加1
//	//初始化 top给的是-1 意味着top指向栈顶数据
//	//先加1 再放数据
//	ps->capacity = 0;
//}
//
////销毁
//void StackDestroy(ST* ps)
//{
//	assert(ps);
//	free(ps->a);
//	ps->a = NULL;
//	ps->capacity = ps->top = 0;
//}
//
////栈顶插入
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
////栈顶删除
//void StackPop(ST* ps)
//{
//	assert(ps);
//	//警告删完了还删
//	assert(!StackEmpty(ps));
//	ps->top--;
//}
//
////栈顶数据
//STDataType StackTop(ST* ps)
//{
//	assert(ps);
//	//不为空再返回栈顶
//	assert(!StackEmpty(ps));
//	//存完之后top会自加 因此top-1处是栈顶
//	return ps->a[ps->top - 1];
//}
//
////栈的大小
//int StackSize(ST* ps)
//{
//	assert(ps);
//	//top的大小就是size
//	return ps->top;
//}
//
////栈是否为空
//bool StackEmpty(ST* ps)
//{
//	assert(ps);
//	//top==0为真 返回1 栈是空的
//	//top!=0为假 返回0 栈不是空的
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
//	//循环打印栈顶并删除栈顶
//	//实现遍历
//	//后进先出
//	while (!StackEmpty(&st))
//	{
//		//打印栈顶
//		printf("%d ", StackTop(&st));
//		//删除栈顶
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
//	//循环打印栈顶并删除栈顶
//	//实现遍历
//	//后进先出
//	while (!StackEmpty(&st))
//	{
//		//打印栈顶
//		printf("%d ", StackTop(&st));
//		//删除栈顶
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
