#define _CRT_SECURE_NO_WARNINGS 1

//消失的数字
//思路1:排序 快排qsort 看后一个数是不是前一个数加1 但时间复杂度O(n*log2 N)
//思路2:(0+1+2+3+……+n)-(a[0]+a[1]+a[2]+……+a[n-1]) 时间复杂度O(N)
//思路3:数组中的值是几就在第几个位置写一下这个值 O(N)
//思路4:给一个值x=0
//x先跟0-n的所有值异或 0跟任何一个数异或就是那个数
//x在跟数组中每个值异或 最后x就是缺的那个数字
//不管顺序 只有有两个相同的数出现就会等于0 说明最后的那个x就出现了一次


//思路2
int missingNumber(int* nums, int numsSize)
{
	int x = 0;
	//跟0-n异或
	for (int i = 0; i <= numsSize; i++)
	{
		x ^= i;
	}
	//再跟数值中值异或
	for (int i = 0; i < numsSize; i++)
	{
		x ^= nums[i];
	}
	return x;
}


//旋转
//思路1:暴力求解，旋转K次
//时间复杂度:O(N*K) 空间复杂度O(1)
//思路2:开辟额外空间
//时间复杂度:O(N) 空间复杂度:O(N)
//思路3:
//前n-k个逆置
//后k个逆置
//整体逆置

//思路3

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
	//前n-k个数逆置
	Reverse(nums, 0, numsSize - k - 1);
	//后k个逆置
	Reverse(nums, numsSize - k, numsSize - 1);
	//整体逆置
	Reverse(nums, 0, numsSize - 1);
}
//k==n时 不旋转就是要的结果