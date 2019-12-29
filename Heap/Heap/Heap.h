
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef int HPDataType;
typedef  struct Heap
{
	HPDataType* _a;
	size_t _size;
	size_t _capacity;
}Heap;

//打印堆
void HeapPrint(Heap* hp);

// 堆的构建 
void HeapCreate(Heap* hp, HPDataType* a, int n); 

// 堆的销毁 
void HeapDestory(Heap* hp); 

// 堆的插入 
void HeapPush(Heap* hp, HPDataType x); 

// 堆的删除 
void HeapPop(Heap* hp); 

// 取堆顶的数据 
HPDataType HeapTop(Heap* hp); 

// 堆的数据个数 
int HeapSize(Heap* hp); 

// 堆的判空 
int HeapEmpty(Heap* hp);

// 对数组进行堆排序 
void HeapSort(int* a, int n);

//向下调整建大堆
void AdjustDwon(HPDataType* a, int n, int root);

//数据交换
void Swap(HPDataType* x1, HPDataType* x2);
