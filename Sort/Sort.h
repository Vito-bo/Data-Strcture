

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

// 排序实现的接口
// 排序的整体分析
//1.单趟排序 2.整体排序

// 插入排序 
void InsertSort(int* a, int n)
{
	int i;
	for (i = 0; i < n-1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// 希尔排序 
// 插入排序的优化改进
// 预排序（接近升序）+ 插入排序（有序）
void ShellSort(int* a, int n)
{
	//单趟排序，间距为gap的插入排序
	//[0,end] tmp,间距都是gap
	//1.gap >1 时，进行预排序
	//2.gap==1时，进行插入排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//同时对gap组进行排序
		int i;
		for ( i = 0; i<n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 直接选择排序 
// 时间复杂度 O(N^2)
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin; i <= end; ++i)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i]<a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		++begin;
		--end;
	}
}

// 堆排序  时间复杂度O(N*logN)                                                
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	// 建大堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, n - 1, 0);
		--end;
	}
}

// 冒泡排序  O(N^2)
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 1; i < end; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange = 0)
			break;
		--end;
	}
}

// 快速排序递归实现    
// 快速排序hoare版本 
int PartSort1(int* a, int left, int right)
{
	int key = left;
	while (left < right)
	{
		// right先走，找小
		while (left < right && a[right] >= a[key])
		{
			--right;
		}

		// left再走，找大
		while (left < right && a[left] <= a[key])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
}

// 快速排序挖坑法 
int PartSort2(int* a, int left, int right)
{
	 1
}

// 快速排序前后指针法 
int PartSort3(int* a, int left, int right); 

// 快速排序 递归实现
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int keyIndex = PartSort1(a, left, right);
	//将区间[left,right]分成[left, keyIndex-1],keyIndex,[keyIndex + 1, right]

	QuickSort(a, left, keyIndex-1);
	QuickSort(a, keyIndex + 1, right);
}

// 快速排序 非递归实现 
void QuickSortNonR(int* a, int left, int right);

// 归并排序递归实现 
void MergeSort(int* a, int n);

// 归并排序非递归实现 
void MergeSortNonR(int* a, int n);

// 计数排序 
void CountSort(int* a, int n);
