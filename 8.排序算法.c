//#pragma once
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//#include <Windows.h>
//
////��ӡ����
//void PrintArray(int* a, int n);
//
////��������
//void InsertSort(int* a, int n);
//
////ϣ������ ����������Ż�
//void ShellSort(int* a, int n);
//
////����
//void Swap(int* p1, int* p2);
//
////������С��
//void AdjustDown(int* a, int n, int root);
//
////������(�������ȫ������)(ʵ��������)
////���:�������еĸ��׶����ڵ��ں��� ��������
////С��:�������е�ĸ�׶�С�ڵ��ں��� ������С��
//void HeapSort(int* a, int n);
//
////ֱ��ѡ������
//void SelectSort(int* a, int n);
//
////ð������
//void BubbleSort(int* a, int n);
//
////��������
//void QuickSort(int* a, int left, int right);
//
////����ȡ��
//int GetMidIndex(int* a, int left, int right);
//
////�ڿӷ�
//int PartSort1(int* a, int left, int right);
//
////����ָ�뷨
//int PartSort2(int* a, int left, int right);
//
////ǰ��ָ�뷨
//int PartSort3(int* a, int left, int right);
//
////�鲢����
//void MergeSort(int* a, int n);
//
////�鲢�Ӻ���
//void _MergeSort(int* a, int left, int right, int* tmp);
//
////ջ�Ĺ���
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
////ջ�ײ���
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
////�ǵݹ����
//void QuickSortNonR(int* a, int n);
//
////�ǵݹ�鲢
//void MergeSortNonR(int* a, int n);
//
////��������
//void CountSort(int* a, int n);
//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "Sort.h"
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
//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include "Sort.h"
//
////��ӡ����
//void PrintArray(int* a, int n)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//}
//
////��������
////ʱ�临�Ӷ�O(n^2) 
////� ���� ÿ�ζ�Ҫ��������ѭ��
////1+2+3+��������+n-1=n*(n-1)/2 O(n^2)
////��� ˳������ 1+1+1+1��������+1+1=n-1 O(n)
//void InsertSort(int* a, int n)
//{
//	//�±����
//	for (int i = 0; i < n - 1; i++)
//	{
//		//[0,end]���� end+1��λ�õ�ֵ�����ȥ ��[0,end+1]����
//		int end = i;
//		//�ȱ��� ��ֹ����
//		int tmp = a[end + 1];
//		while (end >= 0)
//		{
//			if (a[end] > tmp)
//			{
//				a[end + 1] = a[end];
//				--end;
//			}
//			//���Բ����ʱ���break
//			else
//			{
//				break;
//			}
//		}
//		//�����ֵ�����еĶ�����߶�С
//		//����ֱ�ӷŵ�end+1��λ��
//		//��С�Ļ� end����ѭ����-1 �ŵ�a[0]
//		a[end + 1] = tmp;
//	}
//}
//
////ϣ������ ����������Ż�
////1.�Ƚ���Ԥ���� �ӽ�����
////2.ֱ�Ӳ�������
////Ԥ����:������ ���Ϊgap��һ�� ����Ԥ���� gap�ɴ�С
////gapԽ��:���������Խ��ĵ�����
////С��������Խ��ĵ�ǰ��
////gapԽ�� Ԥ����Խ���ӽ�����
////gapԽС Խ�ӽ�����
////gap==1ʱ����ֱ�Ӳ�������
////ʱ�临�Ӷ�:
////��ѭ��:
////N/3/3/3��������/3/3=1
////log3��N
////Сѭ��:
////gap�ܴ�ʱ ����Ԥ�ŵ�ʱ�临�Ӷ�ΪO(N)
////gap��Сʱ �����Ѿ��ܽӽ������� ��ʱ���Ҳ��O(N)
////ʱ�临�Ӷ�O(N*log3 N)
//void ShellSort(int* a, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		//gap = gap / 2;//���Ա�֤���һ��Ϊ1
//		gap = gap / 3 + 1;//��֤���һ��Ϊ1
//		//gap==1����ֱ�Ӳ������� ��1����gap
//		//�Ѽ��Ϊgap�Ķ�������ͬʱ��
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
////�����ɴ��
////ʱ�临�Ӷ�O(N)
//void AdjustDown(int* a, int n, int root)
//{
//	int parent = root;
//	int child = parent * 2 + 1;//Ĭ������
//	//�����±��������n �ͳ��������鷶Χ
//	while (child < n)
//	{
//		//ѡ�����Һ��Ӵ����һ��
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			//�Һ��ӱ����Ӵ�ͱ�Ϊ�Һ���
//			child += 1;
//		}
//		//���ɴ��ں� �ͱ�ɴ�� С�ںž�С��
//		//����if��С�ں�ҲҪ��
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			//�������ӱ�Ϊ���� ��������
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		//����Ǹ����ӱȸ��׶�С ֱ��break
//		else
//		{
//			break;
//		}
//	}
//}
//
////������
////��С��
////ǰ��:������������С��(�������)
////�Ӹ��ڵ㿪ʼ
////ѡ�����Һ�����С����һ�� �����ױȽ�
////����ȸ���С �ͽ���
////Ȼ���ټ������µ� ����Ҷ�ӽڵ����ֹ
////����ʱ�临�Ӷ�O(N*logN)
//void HeapSort(int* a, int n)
//{
//	//����
//	//���µ����㷨 ������������С�Ѳ�����
//	//����ô��? ���Ŵ����һ��������ʼ��
//	//�ٷ��������� Ҷ�Ӳ���Ҫ�� �ӵ����ķ�Ҷ��������ʼ��
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
//	{
//		//���һ��ֵ���±���n-1 ������ĸ��� 
//		//����ǰ���� �ȰѺ������С�� 
//		AdjustDown(a, n, i);
//	}
//	//�ų����� �����
//	//Ϊʲô?
//	//����ǽ�С�� ��С���ڶѶ� �Ѿ���ѡ������
//	//��ô��ʣ�µ�������ȥѡ��(����) ����ʣ�����ṹ������
//	//��Ҫ���½��Ѳ���ѡ����һ���� ���ѵ�ʱ�临�Ӷ���O(N)
//	//��ô�������ǲ����� ���Ƕ������û��Ч��������
//	//�����Ļ������ ����������������
//	//ǰn-1�������µ��� ѡ���δ���� �ٸ������ڶ���λ�ý���
//	//ʱ�临�Ӷ�:N*logN
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		AdjustDown(a, end, 0);
//		--end;
//	}
//}
//
////ʱ�临�Ӷ�O(N^2)
////ѡ������
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
//	//	//���begin��maxi�ص� 
//	//	//��Ҫ����һ��maxi��λ��
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
//		//���±�i֮��ʼ����
//		for (int j = i + 1; j < n; j++)
//		{
//			//�����������±�i��С
//			//�Ͱ��±������Сֵ�±�
//			if (a[j] < a[mini])
//			{
//				mini = j;
//			}
//			Swap(&a[i], &a[mini]);
//		}
//	}
//}
//
////ð��
////O(N)�Ȳ�����
////��ֱ�Ӳ���˭����? ֱ�Ӳ���
//void BubbleSort(int* a, int n)
//{
//	//Ĭ������
//	int exchange = 0;
//	//ð������Ĵ���
//	for (int i = 0; i < n - 1; i++)
//	{
//		//һ��ð������
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				Swap(&a[j], &a[j + 1]);
//				//�н���
//				exchange = 1;
//			}
//		}
//		//˵���Ѿ�����
//		if (exchange == 0)
//		{
//			break;
//		}
//	}
//}
//
////����ȡ��
//int GetMidIndex(int* a, int left, int right)
//{
//	int mid = (left + right) >> 1;//����/2
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
////��������
////�ڿӷ�
////����
////������:
////����:O(N)
////O(N*logN)
////����ʲô������ ʱ�临�Ӷ��Ƕ���?
////������� O(N^2) �Ȳ�����
//int PartSort1(int* a, int left, int right)
//{
//	//��������ܻ� �����������ȡ��
//	//�����ҵ���������С��Ϊkey
//	int index = GetMidIndex(a, left, right);
//	//���� ������ԭ��������key ����ѡ����С��
//	Swap(&a[left], &a[index]);
//	int begin = left;
//	int end = right;
//	int pivot = begin;
//	int key = a[begin];
//	while (begin < end)
//	{
//		//�ұ���С �ŵ���� ���ж�һ�� ��Ϊ����end--���´���
//		//��ֹԽ��
//		while (begin < end && a[end] >= key)
//		{
//			//���˾���ǰ��
//			--end;
//		}
//		//С�ķŵ���ߵĿ�
//		//�Լ��γ��µĿ�λ
//		a[pivot] = a[end];
//		pivot = end;
//		//����Ҵ� �ŵ��ұ�
//		while (begin < end && a[begin] <= key)
//		{
//			//С�˾�������
//			++begin;
//		}
//		//��ķŵ��ұߵĿ�
//		//�Լ��γ��µĿ�λ
//		a[pivot] = a[begin];
//		pivot = begin;
//	}
//	//������ʱ����ǿӵ�λ��
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
//	//������ȡ��
//	//left��ʼ�Ҵ� right��ʼ��С
//	//�ҵ����� ���left==right��ʱ�� ��key�Ź���
//	while (begin < end)
//	{
//		//��С
//		while (begin < end && a[end] >= a[keyi])
//		{
//			--end;
//		}
//		//�Ҵ�
//		while (begin < end && a[begin] <= a[keyi])
//		{
//			++begin;
//		}
//		//����
//		Swap(&a[begin], &a[end]);
//	}
//	//��key�õ�������λ��
//	Swap(&a[begin], &a[keyi]);
//	//����key���±�
//	return begin;
//}
//
//int PartSort3(int* a, int left, int right)
//{
//	int index = GetMidIndex(a, left, right);
//	Swap(&a[left], &a[index]);
//	//prev curǰ��ָ��
//	//cur�ҵ�С�ľ�prev++ ����
//	//����С�ľ͵��������
//	//���prev��λ�þ���key��λ�� ����
//	//��󷵻�prev����key���±�
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
//	//������������ ������������ ������ ����
//	//�Ż�����ĵݹ� 
//	//ֻ��10����������
//	//ѡ�ò�������
//	//��һ������������ �ڶ������������ݸ���
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
////�ֳ����������Ұ�����
////���������������
////����������������ĺϲ�
////ȡС�� �ŵ��µ���ʱ���� �ٿ�����ԭ����
////��ô�鲢֮ǰ ����������û���� ��ô��?
////���εݹ� �ٷ�
//
//void _MergeSort(int* a, int left, int right, int* tmp)
//{
//	if (left >= right)
//		return;
//	int mid = (left + right) >> 1;
//	//����[left,mid] [mid+1,right]���� �Ϳ��Թ鲢
//	_MergeSort(a, left, mid, tmp);
//	_MergeSort(a, mid + 1, right, tmp);
//	//������������ĺϲ�
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
//	//��֪��˭�ȵ�end ֱ��д����ѭ�� ����һ������ŵ�����
//	//������ѭ��ֻ���1��
//	while (begin1 <= end1)
//	{
//		tmp[index++] = a[begin1++];
//	}
//	while (begin2 <= end2)
//	{
//		tmp[index++] = a[begin2++];
//	}
//	//������ȥ
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
////�ǵݹ����
////�ݹ�ȱ��:ջ֡���̫�� ջ�ռ䲻���� ���ܻ����
////�ݹ�ķǵݹ�:1.ֱ�Ӹ�ѭ�� 2.�������ݽṹջģ��ݹ����(����)
//void QuickSortNonR(int* a, int n)
//{
//	ST st;
//	StackInit(&st);
//	StackPush(&st, n - 1);
//	StackPush(&st, 0);
//	//ȡ�����±�
//	while (!StackEmpty(&st))
//	{
//		int left = StackTop(&st);
//		StackPop(&st);
//		int right = StackTop(&st);
//		StackPop(&st);
//		//��������
//		int keyIndex = PartSort3(a, left, right);
//		//[left,keyIndex-1] keyIndex [keyIndex+1,right]
//		//ֻ��һ��ֵ��������
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
////�ǵݹ�鲢
////ʱ�临�Ӷ�O(N*logN)
//void MergeSortNonR(int* a, int n)
//{
//	int gap = 1;//ÿһ�����ݵĸ���
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	while (gap < n)
//	{
//		for (int i = 0; i < n; i += 2 * gap)
//		{
//			//������й鲢 ���i+=2*gap���ƴ���
//			//[i,i+gap-1] [i+gap,i+2*gap-1]
//			//������������ĺϲ�
//			int begin1 = i;
//			int end1 = i + gap - 1;
//			int begin2 = i + gap;
//			int end2 = i + 2 * gap - 1;
//			//�鲢�������Ұ�������ܾͲ�����
//			if (begin2 >= n)
//				break;
//			//�鲢�������Ұ����������
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
//			//��֪��˭�ȵ�end ֱ��д����ѭ�� ����һ������ŵ�����
//			//������ѭ��ֻ���1��
//			while (begin1 <= end1)
//			{
//				tmp[index++] = a[begin1++];
//			}
//			while (begin2 <= end2)
//			{
//				tmp[index++] = a[begin2++];
//			}
//			//������ȥ
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
////�鲢���� Ҳ��������
////����10G�����ݷŵ�Ӳ�̵��ļ��� Ҫ���� �����?
////10G���ļ� �зֳ�10��1G���ļ�
////��������10��1G���ļ�����
////���ζ��ļ� ÿ�ζ�1G���ڴ��зŵ�һ������
////�ÿ��������������
////��д��һ���ļ� �ټ�������һ��1G������
//
////�������� Ͱ����
////123 45 12 9 88 43
////���ηֱ�ȡ���ǵĸ�λ ʮλ ��λ��������
////ʵ�����������ûɶ����
//
////��������
////4 4 6 8 9 3 3 0
////һ�����鿪10��
////1.ͳ��ÿ�������ֵĴ���
////��ʼ������Ϊ0 �±��Ӧ�ĵط�++����
////2.ʹ�ô����Ϳ���������
////0 0 3 3 4 4 6 8 9
////���100 101 102 101 109 105  ����109
////ǰ��0-99���˷�
////���ӳ��λ��:num-min
//
//
////�ǱȽ�����
////ʱ�临�Ӷ�:O(N+range) ˵���������ڼ���һ��������������
////�ռ临�Ӷ�:O(range)
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
//	//ͳ�ƴ���
//	for (int i = 0; i < n; i++)
//	{
//		//���ӳ��
//		count[a[i] - min]++;
//	}
//	int j = 0;
//	for (int i = 0; i < range; i++)
//	{
//		while (count[i]--)
//		{
//			//�ӻ�ȥ
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