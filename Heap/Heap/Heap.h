
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

//��ӡ��
void HeapPrint(Heap* hp);

// �ѵĹ��� 
void HeapCreate(Heap* hp, HPDataType* a, int n); 

// �ѵ����� 
void HeapDestory(Heap* hp); 

// �ѵĲ��� 
void HeapPush(Heap* hp, HPDataType x); 

// �ѵ�ɾ�� 
void HeapPop(Heap* hp); 

// ȡ�Ѷ������� 
HPDataType HeapTop(Heap* hp); 

// �ѵ����ݸ��� 
int HeapSize(Heap* hp); 

// �ѵ��п� 
int HeapEmpty(Heap* hp);

// ��������ж����� 
void HeapSort(int* a, int n);

//���µ��������
void AdjustDwon(HPDataType* a, int n, int root);

//���ݽ���
void Swap(HPDataType* x1, HPDataType* x2);
