#define _CRT_SECURE_NO_WARNINGS 1

//��ʧ������
//˼·1:���� ����qsort ����һ�����ǲ���ǰһ������1 ��ʱ�临�Ӷ�O(n*log2 N)
//˼·2:(0+1+2+3+����+n)-(a[0]+a[1]+a[2]+����+a[n-1]) ʱ�临�Ӷ�O(N)
//˼·3:�����е�ֵ�Ǽ����ڵڼ���λ��дһ�����ֵ O(N)
//˼·4:��һ��ֵx=0
//x�ȸ�0-n������ֵ��� 0���κ�һ�����������Ǹ���
//x�ڸ�������ÿ��ֵ��� ���x����ȱ���Ǹ�����
//����˳�� ֻ����������ͬ�������־ͻ����0 ˵�������Ǹ�x�ͳ�����һ��


//˼·2
int missingNumber(int* nums, int numsSize)
{
	int x = 0;
	//��0-n���
	for (int i = 0; i <= numsSize; i++)
	{
		x ^= i;
	}
	//�ٸ���ֵ��ֵ���
	for (int i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
	}
	return x;
}


//��ת
//˼·1:������⣬��תK��
//ʱ�临�Ӷ�:O(N*K) �ռ临�Ӷ�O(1)
//˼·2:���ٶ���ռ�
//ʱ�临�Ӷ�:O(N) �ռ临�Ӷ�:O(N)
//˼·3:
//ǰn-k������
//��k������
//��������

//˼·3

void Reverse(int* nums, int left, int right)
{
	while (left < right)
	{
		int tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;
		++left;
		--right;
	}
}

void rotate(int* nums, int numsSize, int k)
{
	if (k >= numsSize)
		k %= numsSize;
	//ǰn-k��������
	Reverse(nums, 0, numsSize - k - 1);
	//��k������
	Reverse(nums, numsSize - k, numsSize - 1);
	//��������
	Reverse(nums, 0, numsSize - 1);
}
//k==nʱ ����ת����Ҫ�Ľ��