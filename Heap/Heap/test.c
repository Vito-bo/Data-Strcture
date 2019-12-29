
#include"Heap.h"


void TestHeap()
{
	HPDataType a[10] = { 4, 3, 7, 1, 8, 0, 5, 6, 9, 2 };
	Heap hp;
	HeapCreate(&hp, a, 10);
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);

	HeapPush(&hp, -1);
	HeapPrint(&hp);

	HeapPush(&hp, 5);
	HeapPrint(&hp);

}


//TopK问题
//找最大的前K个，建立K个数的小堆
//找最小的前K个，建立K个数的大堆



void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int)*n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		a[i] = rand() % 1000000;
	}
	/*a[5] = 1000000 + 1;
	a[1231] = 1000000 + 2;
	a[531] = 1000000 + 3;
	a[5121] = 1000000 + 4;
	a[115] = 1000000 + 5;
	a[2335] = 1000000 + 6;
	a[9999] = 1000000 + 7;
	a[76] = 1000000 + 8;
	a[423] = 1000000 + 9;
	a[3144] = 1000000 + 10;*/
	
	a[5] = -1;
	a[1231] = -2;
	a[531] = -3;
	a[5121] = -4;
	a[115] = -5;
	a[2335] = -6;
	a[9999] = -7;
	a[76] = -8;
	a[423] = -9;
	a[3144] = -10;

	Heap hp;

	HeapCreate(&hp, a, 10);
	for (size_t i = 10; i < n; ++i)  // N
	{
		if (a[i] < HeapTop(&hp)) // LogK
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}

	HeapPrint(&hp);
}

//升序进行堆排序
void HeapSort(int* a, int n)
{
	// 建大堆
	int i = (n - 1 - 1) / 2;
	for (i; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a,end,0);
		--end;
	}
}


int main()
{
	//TestHeap();
	//TestTopk();

	int a[10] = { 4, 3, 7, 1, 8, 0, 5, 6, 9, 2 };
	HeapSort(a, 10);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}