

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

// ����ʵ�ֵĽӿ�
// ������������
//1.�������� 2.��������

// �������� 
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

// ϣ������ 
// ����������Ż��Ľ�
// Ԥ���򣨽ӽ�����+ ������������
void ShellSort(int* a, int n)
{
	//�������򣬼��Ϊgap�Ĳ�������
	//[0,end] tmp,��඼��gap
	//1.gap >1 ʱ������Ԥ����
	//2.gap==1ʱ�����в�������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//ͬʱ��gap���������
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

// ֱ��ѡ������ 
// ʱ�临�Ӷ� O(N^2)
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

// ������  ʱ�临�Ӷ�O(N*logN)                                                
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
	// �����
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

// ð������  O(N^2)
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

// ��������ݹ�ʵ��    
// ��������hoare�汾 
int PartSort1(int* a, int left, int right)
{
	int key = left;
	while (left < right)
	{
		// right���ߣ���С
		while (left < right && a[right] >= a[key])
		{
			--right;
		}

		// left���ߣ��Ҵ�
		while (left < right && a[left] <= a[key])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[key], &a[left]);
}

// ���������ڿӷ� 
int PartSort2(int* a, int left, int right)
{
	 1
}

// ��������ǰ��ָ�뷨 
int PartSort3(int* a, int left, int right); 

// �������� �ݹ�ʵ��
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int keyIndex = PartSort1(a, left, right);
	//������[left,right]�ֳ�[left, keyIndex-1],keyIndex,[keyIndex + 1, right]

	QuickSort(a, left, keyIndex-1);
	QuickSort(a, keyIndex + 1, right);
}

// �������� �ǵݹ�ʵ�� 
void QuickSortNonR(int* a, int left, int right);

// �鲢����ݹ�ʵ�� 
void MergeSort(int* a, int n);

// �鲢����ǵݹ�ʵ�� 
void MergeSortNonR(int* a, int n);

// �������� 
void CountSort(int* a, int n);
