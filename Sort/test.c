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
	// ²åÈëÅÅÐò
	//InsertSort(a, sizeof(a)/sizeof(a[0]));

	// Ï£¶ûÅÅÐò
	//ShellSort(a, sizeof(a) / sizeof(a[0]));

	// Ö±½ÓÑ¡ÔñÅÅÐò
	//SelectSort(a, sizeof(a) / sizeof(a[0]));

	// ¶ÑÅÅÐò
	//HeapSort(a, sizeof(a) / sizeof(a[0]));

	// Ã°ÅÝÅÅÐò
	//BubbleSort(a, sizeof(a) / sizeof(a[0]));


	// ¿ìËÙÅÅÐò                 
	QuickSort(a, 0, 7); 


	PrintfArray(a, sizeof(a) / sizeof(a[0]));
}

int main()
{
	TestSort();
	return 0;
}