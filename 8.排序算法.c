//#pragma once
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//#include <Windows.h>
//
////打印数组
//void PrintArray(int* a, int n);
//
////插入排序
//void InsertSort(int* a, int n);
//
////希尔排序 插入排序的优化
//void ShellSort(int* a, int n);
//
////交换
//void Swap(int* p1, int* p2);
//
////调整成小堆
//void AdjustDown(int* a, int n, int root);
//
////堆排序(想象成完全二叉树)(实际是数组)
////大堆:树中所有的父亲都大于等于孩子 根是最大的
////小堆:树中所有的母亲都小于等于孩子 根是最小的
//void HeapSort(int* a, int n);
//
////直接选择排序
//void SelectSort(int* a, int n);
//
////冒泡排序
//void BubbleSort(int* a, int n);
//
////快速排序
//void QuickSort(int* a, int left, int right);
//
////三数取中
//int GetMidIndex(int* a, int left, int right);
//
////挖坑法
//int PartSort1(int* a, int left, int right);
//
////左右指针法
//int PartSort2(int* a, int left, int right);
//
////前后指针法
//int PartSort3(int* a, int left, int right);
//
////归并排序
//void MergeSort(int* a, int n);
//
////归并子函数
//void _MergeSort(int* a, int left, int right, int* tmp);
//
////栈的构建
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
////栈底插入
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
////非递归快排
//void QuickSortNonR(int* a, int n);
//
////非递归归并
//void MergeSortNonR(int* a, int n);
//
////计数排序
//void CountSort(int* a, int n);
//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "Sort.h"
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
////栈定插入
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
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "Sort.h"
//
////打印数组
//void PrintArray(int* a, int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
////插入排序
////时间复杂度O(n^2) 
////最坏 逆序 每次都要走完整个循环
////1+2+3+…………+n-1=n*(n-1)/2 O(n^2)
////最好 顺序有序 1+1+1+1…………+1+1=n-1 O(n)
//void InsertSort(int* a, int n)
//{
//	//下标遍历
//	for (int i = 0; i < n - 1; i++)
//	{
//		//[0,end]有序 end+1的位置的值插入进去 让[0,end+1]有序
//		int end = i;
//		//先保存 防止覆盖
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (a[end] > tmp)
//			{
//				a[end + 1] = a[end];
//				--end;
//			}
//			//可以插入的时候就break
//			else
//			{
//				break;
//			}
//		}
//		//插入的值比所有的都大或者都小
//		//都大直接放到end+1的位置
//		//都小的话 end最后出循环是-1 放到a[0]
//		a[end + 1] = tmp;
//	}
//}
//
////希尔排序 插入排序的优化
////1.先进行预排序 接近有序
////2.直接插入排序
////预排序:分组排 间隔为gap是一组 多组预排序 gap由大到小
////gap越大:大的数可以越快的到后面
////小的数可以越快的到前面
////gap越大 预排完越不接近有序
////gap越小 越接近有序
////gap==1时就是直接插入排序
////时间复杂度:
////大循环:
////N/3/3/3…………/3/3=1
////log3的N
////小循环:
////gap很大时 下面预排的时间复杂度为O(N)
////gap很小时 数组已经很接近有序了 这时差不多也是O(N)
////时间复杂度O(N*log3 N)
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		//gap = gap / 2;//可以保证最后一次为1
//		gap = gap / 3 + 1;//保证最后一次为1
//		//gap==1就是直接插入排序 把1换成gap
//		//把间隔为gap的多组数据同时排
//		for (int i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int tmp = a[end + gap];
//			while (end >= 0)
//			{
//				if (a[end] > tmp)
//				{
//					a[end + gap] = a[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			a[end + gap] = tmp;
//		}
//	}
//}
//
//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
////调整成大堆
////时间复杂度O(N)
//void AdjustDown(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;//默认左孩子
//	//孩子下标如果大于n 就超出了数组范围
//	while (child < n)
//	{
//		//选出左右孩子大的那一个
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			//右孩子比左孩子大就变为右孩子
//			child += 1;
//		}
//		//换成大于号 就变成大堆 小于号就小堆
//		//上面if的小于号也要换
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			//交换后孩子变为父亲 孩子重置
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		//大的那个孩子比父亲都小 直接break
//		else
//		{
//			break;
//		}
//	}
//}
//
////堆排序
////建小堆
////前提:左右子树都是小堆(特殊情况)
////从根节点开始
////选出左右孩子中小的那一个 跟父亲比较
////如果比父亲小 就交换
////然后再继续往下调 调到叶子节点就终止
////整体时间复杂度O(N*logN)
//void HeapSort(int* a, int n)
//{
//	//建堆
//	//向下调整算法 左右子树不是小堆不能用
//	//那怎么办? 倒着从最后一颗子树开始调
//	//再分析倒着走 叶子不需要调 从倒数的非叶子子树开始调
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		//最后一个值的下标是n-1 算出他的父亲 
//		//再往前遍历 先把后面调成小堆 
//		AdjustDown(a, n, i);
//	}
//	//排成升序 建大堆
//	//为什么?
//	//如果是建小堆 最小数在堆顶 已经被选出来了
//	//那么在剩下的数中再去选数(建堆) 但是剩下树结构都乱了
//	//需要重新建堆才能选出下一个数 建堆的时间复杂度是O(N)
//	//那么这样不是不可以 但是堆排序就没有效率优势了
//	//把最大的换到最后 把他不看做堆里面
//	//前n-1个数向下调整 选出次大的数 再跟倒数第二个位置交换
//	//时间复杂度:N*logN
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
//
////时间复杂度O(N^2)
////选择排序
//void SelectSort(int* a, int n)
//{
//	//int begin = 0;
//	//int end = n - 1;
//	//while (begin < end)
//	//{
//	//	int mini = begin;
//	//	int maxi = begin;
//	//	for (int i = begin; i <= end; i++)
//	//	{
//	//		if (a[i] < a[mini])
//	//		{
//	//			mini = i;
//	//		}
//	//		if (a[i] > a[maxi])
//	//		{
//	//			maxi = i;
//	//		}
//	//	}
//	//	Swap(&a[begin], &a[mini]);
//	//	//如果begin和maxi重叠 
//	//	//需要修正一下maxi的位置
//	//	if (begin == maxi)
//	//	{
//	//		maxi = mini;
//	//	}
//	//	Swap(&a[end], &a[maxi]);
//	//	++begin;
//	//	--end;
//	//}
//	int mini = 0;
//	for (int i = 0; i < n; i++)
//	{
//		mini = i;
//		//从下标i之后开始遍历
//		for (int j = i + 1; j < n; j++)
//		{
//			//后面有数比下标i处小
//			//就把下标给到最小值下标
//			if (a[j] < a[mini])
//			{
//				mini = j;
//			}
//			Swap(&a[i], &a[mini]);
//		}
//	}
//}
//
////冒泡
////O(N)等差数列
////跟直接插入谁更好? 直接插入
//void BubbleSort(int* a, int n)
//{
//	//默认有序
//	int exchange = 0;
//	//冒泡排序的次数
//	for (int i = 0; i < n - 1; i++)
//	{
//		//一趟冒泡排序
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				Swap(&a[j], &a[j + 1]);
//				//有交换
//				exchange = 1;
//			}
//		}
//		//说明已经有序
//		if (exchange == 0)
//		{
//			break;
//		}
//	}
//}
//
////三数取中
//int GetMidIndex(int* a, int left, int right)
//{
//	int mid = (left + right) >> 1;//就是/2
//	if (a[left] < a[mid])
//	{
//		if (a[mid] < a[right])
//		{
//			return mid;
//		}
//		else if (a[left] > a[right])
//		{
//			return a[left];
//		}
//		else
//		{
//			return a[right];
//		}
//	}
//	else//a[left]>a[mid]
//	{
//		if (a[mid] > a[right])
//		{
//			return mid;
//		}
//		else if (a[left] < a[right])
//		{
//			return a[left];
//		}
//		else
//		{
//			return a[right];
//		}
//	}
//}
//
//
////快速排序
////挖坑法
////分治
////不有序:
////单趟:O(N)
////O(N*logN)
////快排什么情况下最坏 时间复杂度是多少?
////有序情况 O(N^2) 等差数列
//int PartSort1(int* a, int left, int right)
//{
//	//有序情况很坏 这里进行三数取中
//	//不让找到最大或者最小作为key
//	int index = GetMidIndex(a, left, right);
//	//交换 但还是原来的数做key 不会选到最小的
//	Swap(&a[left], &a[index]);
//	int begin = left;
//	int end = right;
//	int pivot = begin;
//	int key = a[begin];
//	while (begin < end)
//	{
//		//右边找小 放到左边 再判断一次 因为可能end--后导致错乱
//		//防止越界
//		while (begin < end && a[end] >= key)
//		{
//			//大了就往前走
//			--end;
//		}
//		//小的放到左边的坑
//		//自己形成新的坑位
//		a[pivot] = a[end];
//		pivot = end;
//		//左边找大 放到右边
//		while (begin < end && a[begin] <= key)
//		{
//			//小了就往后走
//			++begin;
//		}
//		//大的放到右边的坑
//		//自己形成新的坑位
//		a[pivot] = a[begin];
//		pivot = begin;
//	}
//	//相遇的时候就是坑的位置
//	pivot = begin;
//	a[pivot] = key;
//	return pivot;
//}
//
//int PartSort2(int* a, int left, int right)
//{
//	int index = GetMidIndex(a, left, right);
//	Swap(&a[left], &a[index]);
//	int begin = left;
//	int end = right;
//	int keyi = begin;
//	//先三数取中
//	//left开始找大 right开始找小
//	//找到交换 最后left==right的时候 把key放过来
//	while (begin < end)
//	{
//		//找小
//		while (begin < end && a[end] >= a[keyi])
//		{
//			--end;
//		}
//		//找大
//		while (begin < end && a[begin] <= a[keyi])
//		{
//			++begin;
//		}
//		//交换
//		Swap(&a[begin], &a[end]);
//	}
//	//把key拿到相遇的位置
//	Swap(&a[begin], &a[keyi]);
//	//返回key的下标
//	return begin;
//}
//
//int PartSort3(int* a, int left, int right)
//{
//	int index = GetMidIndex(a, left, right);
//	Swap(&a[left], &a[index]);
//	//prev cur前后指针
//	//cur找到小的就prev++ 交换
//	//这样小的就到左边来了
//	//最后prev的位置就是key的位置 交换
//	//最后返回prev就是key的下标
//	int keyi = left;
//	int prev = left;
//	int cur = left + 1;
//	while (cur <= right)
//	{
//		if (a[cur] < a[keyi])
//		{
//			++prev;
//			Swap(&a[prev], &a[cur]);
//		}
//		++cur;
//	}
//	Swap(&a[keyi], &a[prev]);
//	return prev;
//}
//
//
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	//int keyIndex = PartSort1(a, left, right);
//	//int keyIndex = PartSort2(a, left, right);
//	int keyIndex = PartSort3(a, left, right);
//	//[left,right]
//	//[left,pivot-1] pivot [pivot+1,right]
//	//左子区间有序 右子区间有序 就有序 分治
//	//优化后面的递归 
//	//只有10个数以下了
//	//选用插入排序
//	//第一个参数是数组 第二个参数是数据个数
//	if (keyIndex - 1 - left > 10)
//	{
//		QuickSort(a, left, keyIndex - 1);
//	}
//	else
//	{
//		InsertSort(a + left, keyIndex - 1 - left + 1);
//	}
//	if (right - (keyIndex + 1) > 10)
//	{
//		QuickSort(a, keyIndex + 1, right);
//	}
//	else
//	{
//		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
//	}
//}
//
////分成左半区间和右半区间
////两区间如果都有序
////看成两个有序数组的合并
////取小的 放到新的临时数组 再拷贝回原数组
////那么归并之前 左右子区间没有序 怎么办?
////分治递归 再分
//
//void _MergeSort(int* a, int left, int right, int* tmp)
//{
//	if (left >= right)
//		return;
//	int mid = (left + right) >> 1;
//	//假设[left,mid] [mid+1,right]有序 就可以归并
//	_MergeSort(a, left, mid, tmp);
//	_MergeSort(a, mid + 1, right, tmp);
//	//两个有序数组的合并
//	int begin1 = left;
//	int end1 = mid;
//	int begin2 = mid + 1;
//	int end2 = right;
//	int index = left;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] < a[begin2])
//		{
//			tmp[index++] = a[begin1++];
//		}
//		else
//		{
//			tmp[index++] = a[begin2++];
//		}
//	}
//	//不知道谁先到end 直接写两个循环 把另一个数组放到后面
//	//这两个循环只会进1个
//	while (begin1 <= end1)
//	{
//		tmp[index++] = a[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[index++] = a[begin2++];
//	}
//	//拷贝回去
//	for (int i = left; i <= right; i++)
//	{
//		a[i] = tmp[i];
//	}
//}
//
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	_MergeSort(a, 0, n - 1, tmp);
//	free(tmp);
//}
//
//
////非递归快排
////递归缺陷:栈帧深度太深 栈空间不够用 可能会溢出
////递归改非递归:1.直接改循环 2.借助数据结构栈模拟递归过程(复杂)
//void QuickSortNonR(int* a, int n)
//{
//	ST st;
//	StackInit(&st);
//	StackPush(&st, n - 1);
//	StackPush(&st, 0);
//	//取左右下标
//	while (!StackEmpty(&st))
//	{
//		int left = StackTop(&st);
//		StackPop(&st);
//		int right = StackTop(&st);
//		StackPop(&st);
//		//单趟排序
//		int keyIndex = PartSort3(a, left, right);
//		//[left,keyIndex-1] keyIndex [keyIndex+1,right]
//		//只有一个值就有序了
//		if (keyIndex + 1 < right)
//		{
//			StackPush(&st, right);
//			StackPush(&st, keyIndex + 1);
//		}
//
//		if (left < keyIndex - 1)
//		{
//			StackPush(&st, keyIndex - 1);
//			StackPush(&st, left);
//		}
//	}
//}
//
////非递归归并
////时间复杂度O(N*logN)
//void MergeSortNonR(int* a, int n)
//{
//	int gap = 1;//每一组数据的个数
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			//两组进行归并 最后i+=2*gap控制次数
//			//[i,i+gap-1] [i+gap,i+2*gap-1]
//			//两个有序数组的合并
//			int begin1 = i;
//			int end1 = i + gap - 1;
//			int begin2 = i + gap;
//			int end2 = i + 2 * gap - 1;
//			//归并过程中右半区间可能就不存在
//			if (begin2 >= n)
//				break;
//			//归并过程中右半区间算多了
//			if (end2 >= n)
//			{
//				end2 = n - 1;
//			}
//			int index = i;
//			while (begin1 <= end1 && begin2 <= end2)
//			{
//				if (a[begin1] < a[begin2])
//				{
//					tmp[index++] = a[begin1++];
//				}
//				else
//				{
//					tmp[index++] = a[begin2++];
//				}
//			}
//			//不知道谁先到end 直接写两个循环 把另一个数组放到后面
//			//这两个循环只会进1个
//			while (begin1 <= end1)
//			{
//				tmp[index++] = a[begin1++];
//			}
//			while (begin2 <= end2)
//			{
//				tmp[index++] = a[begin2++];
//			}
//			//拷贝回去
//			for (int j = 0; j <= end2; j++)
//			{
//				a[j] = tmp[j];
//			}
//		}
//		gap *= 2;
//	}
//	free(tmp);
//}
//
////归并排序 也叫外排序
////假设10G的数据放到硬盘的文件中 要排序 如何排?
////10G的文件 切分成10个1G的文件
////并且让这10个1G的文件有序
////依次读文件 每次读1G到内存中放到一个数组
////用快速排序对其排序
////再写到一个文件 再继续读下一个1G的数据
//
////基数排序 桶排序
////123 45 12 9 88 43
////依次分别取他们的个位 十位 百位……排序
////实际中这个排序没啥意义
//
////计数排序
////4 4 6 8 9 3 3 0
////一个数组开10个
////1.统计每个数出现的次数
////初始化数组为0 下标对应的地方++计数
////2.使用次数就可以排序了
////0 0 3 3 4 4 6 8 9
////如果100 101 102 101 109 105  开到109
////前面0-99会浪费
////相对映射位置:num-min
//
//
////非比较排序
////时间复杂度:O(N+range) 说明他适用于集中一组整形数据排序
////空间复杂度:O(range)
//void CountSort(int* a, int n)
//{
//	int max = a[0], min = a[0];
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] > max)
//		{
//			max = a[i];
//		}
//		if (a[i] < min)
//		{
//			min = a[i];
//		}
//	}
//	int range = max - min + 1;
//	int* count = (int*)malloc(sizeof(int) * range);
//	memset(count, 0, sizeof(int) * range);
//	//统计次数
//	for (int i = 0; i < n; i++)
//	{
//		//相对映射
//		count[a[i] - min]++;
//	}
//	int j = 0;
//	for (int i = 0; i < range; i++)
//	{
//		while (count[i]--)
//		{
//			//加回去
//			a[j++] = i + min;
//		}
//	}
//}
//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "Sort.h"
//
//void TestInsertSort()
//{
//	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
//	InsertSort(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void TestShellSort()
//{
//	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
//	ShellSort(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void TestHeapSort()
//{
//	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
//	HeapSort(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void TestSelectSort()
//{
//	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
//	SelectSort(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void TestBubbleSort()
//{
//	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
//	BubbleSort(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void TestQuickSort()
//{
//	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
//	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void TestMergeSort()
//{
//	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
//	MergeSort(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void TestQuickSortNonR()
//{
//	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
//	QuickSortNonR(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void TestMergeSortNonR()
//{
//	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
//	MergeSortNonR(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void TestCountSort()
//{
//	int a[] = { 3,5,2,7,8,6,1,9,4,0 };
//	CountSort(a, sizeof(a) / sizeof(int));
//	PrintArray(a, sizeof(a) / sizeof(int));
//}
//
//void TestOP()
//{
//	srand(time(0));
//	const int N = 100000;
//	int* a1 = (int*)malloc(sizeof(int) * N);
//	int* a2 = (int*)malloc(sizeof(int) * N);
//	int* a3 = (int*)malloc(sizeof(int) * N);
//	int* a4 = (int*)malloc(sizeof(int) * N);
//	int* a5 = (int*)malloc(sizeof(int) * N);
//	int* a6 = (int*)malloc(sizeof(int) * N);
//	int* a7 = (int*)malloc(sizeof(int) * N);
//	for (int i = 0; i < N; ++i)
//	{
//		a1[i] = rand();
//		a2[i] = a1[i];
//		a3[i] = a1[i];
//		a4[i] = a1[i];
//		a5[i] = a1[i];
//		a6[i] = a1[i];
//		a7[i] = a1[i];
//	}
//	int begin1 = clock();
//	InsertSort(a1, N);
//	int end1 = clock();
//	int begin2 = clock();
//	ShellSort(a2, N);
//	int end2 = clock();
//	int begin3 = clock();
//	SelectSort(a3, N);
//	int end3 = clock();
//	int begin4 = clock();
//	HeapSort(a4, N);
//	int end4 = clock();
//	int begin5 = clock();
//	QuickSort(a5, 0, N - 1);
//	int end5 = clock();
//	int begin6 = clock();
//	MergeSort(a6, N);
//	int end6 = clock();
//	int begin7 = clock();
//	BubbleSort(a7, N);
//	int end7 = clock();
//	printf("InsertSort:%d\n", end1 - begin1);
//	printf("ShellSort:%d\n", end2 - begin2);
//	printf("SelectSort:%d\n", end3 - begin3);
//	printf("HeapSort:%d\n", end4 - begin4);
//	printf("QuickSort:%d\n", end5 - begin5);
//	printf("MergeSort:%d\n", end6 - begin6);
//	printf("BubbleSort:%d\n", end7 - begin7);
//	free(a1);
//	free(a2);
//	free(a3);
//	free(a4);
//	free(a5);
//	free(a6);
//	free(a7);
//}
//
//int main()
//{
//	TestInsertSort();
//	TestShellSort();
//	TestHeapSort();
//	TestSelectSort();
//	TestBubbleSort();
//	TestQuickSort();
//	TestMergeSort();
//	TestQuickSortNonR();
//	TestMergeSortNonR();
//	TestCountSort();
//	TestOP();
//	return 0;
//}