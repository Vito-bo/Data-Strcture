#include "Sort.h"

void PrintfArray(int *a, int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


void TestSort()
{
	//int a[] = { 8, 9, 2, 5, 7, 4, 0, 6, 1, 3 };
	int a[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	// ��������
	//InsertSort(a, sizeof(a)/sizeof(a[0]));

	// ϣ������
	//ShellSort(a, sizeof(a) / sizeof(a[0]));

	// ֱ��ѡ������
	//SelectSort(a, sizeof(a) / sizeof(a[0]));

	// ������
	//HeapSort(a, sizeof(a) / sizeof(a[0]));

	// ð������
	//BubbleSort(a, sizeof(a) / sizeof(a[0]));


	// ��������                 
	QuickSort(a, 0, 7); 


	PrintfArray(a, sizeof(a) / sizeof(a[0]));
}

int main()
{
	TestSort();
	return 0;
}