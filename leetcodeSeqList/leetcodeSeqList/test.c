
//26.删除数组中的重复项
int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize <= 1)
		return numsSize;
	int count = 0;//记录前移的步数
	int i = 0;
	for (; i < numsSize - 1; ++i)
	{
		if (nums[i] == nums[i + 1])
			++count;
		else
			nums[i - count] = nums[i];
	}
	nums[i - count] = nums[i];  //处理尾部节点
	return (numsSize - count);
}

//88.合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = m - 1;
		for (; j >= 0; j--)
		{
			if (nums2[i] < nums1[j])
				nums1[j + 1] = nums1[j];
			else
				break;
		}
		nums1[j + 1] = nums2[i];
		m++;
	}
}
//189旋转数组
void rotate(int* nums, int numsSize, int k)
{
	k = k%numsSize;
	reverse(nums, 0, numsSize - 1);

}
void reverse(int* nums, int left, int right)
{
	int mid = (left + right) / 2;
	for (int i = right; i > mid; i--)
	{
		int tmp = nums[i];
		nums[i] = nums[left + right - i];
		nums[left + right - i] = tmp;
	}
}
