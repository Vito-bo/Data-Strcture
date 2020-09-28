#ifndef __SEQLIST_H_
#define __SEQLIST_H_

#include "Common.h"

//��̬˳���ʵ��

#define SEQLIST_DEFAULT_SIZE 8

//����˳���ṹ
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;

// ˳����ʼ��
void SeqListInit(SeqList *plist);
// ˳���β��
void SeqListPushBack(SeqList *plist, ElemType x);
// ˳�������
void SeqListDestroy(SeqList *plist);
// ˳���ͷ��
void SeqListPushFront(SeqList *plist, ElemType x);
// ��ӡ˳���
void SeqListShow(SeqList *plist);
// ˳���βɾ
void SeqListPopBack(SeqList *plist);
// ˳���ͷɾ
void SeqListPopFront(SeqList *plist);
// ˳�������
void SeqListClear(SeqList *plist);
// ˳���λ�ò���
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x);
// ˳���ֵ����
bool SeqListInsertByVal(SeqList *plist, ElemType x);
// ˳���λ��ɾ��
void SeqListEraseByPos(SeqList *plist, int pos);
// ˳���ֵɾ��
void SeqListEraseByVal(SeqList *plist, ElemType key);
// ˳�������
void SeqListSort(SeqList *plist);
// ����˳�����Ч���ֳ���
size_t SeqListLength(SeqList *plist);
// ����˳���������С
size_t SeqListCapacity(SeqList *plist);
// ˳������
int SeqListFind(SeqList *plist, ElemType key);
// ˳�������
void SeqListReverse(SeqList *plist);
// ����˳����ͷԪ��
ElemType SeqListFront(SeqList *plist);
// ����˳����β
ElemType SeqListBack(SeqList *plist);
// ˳�����ֲ���
int SeqListFind_Binary(SeqList *plist, ElemType key);
// ˳���ɾ������Ԫ��
void SeqListEraseAll(SeqList *plist, ElemType key);

/////////////////////////����ʵ��//////////////////////////////

// ����
bool _Inc(SeqList *plist, size_t new_capacity)
{
#if 0
	assert(plist != NULL && new_capacity > plist->capacity);
	ElemType *new_base = (ElemType*)realloc(plist->base, sizeof(ElemType)*new_capacity);
	if (new_base == NULL)
		return false;
	plist->base = new_base;
	plist->capacity = new_capacity;
	return true;
#endif
	assert(plist != NULL && new_capacity > plist->capacity);
	ElemType *new_base = (ElemType*)realloc(plist->base, sizeof(ElemType)*new_capacity);
	if (new_base == NULL)
		return false;
	memcpy(new_base, plist->base, sizeof(ElemType)*(plist->capacity));

	free(plist->base);
	plist->base = new_base;
	plist->capacity = new_capacity;
	return true;
}

// ˳����п�
bool IsEmpty(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size == 0;
}

// ˳�������
bool IsFull(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size >= plist->capacity;
}

// ˳����ʼ��
void SeqListInit(SeqList *plist)
{
	assert(plist != NULL);
	plist->capacity = SEQLIST_DEFAULT_SIZE; //�ռ�Ĭ�Ͽ���8
	plist->base = (ElemType*)malloc(sizeof(ElemType)*plist->capacity);
	plist->size = 0;
}

// ˳���β��
void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("˳���������%d����β������.\n", x);
		return;
	}
	plist->base[plist->size++] = x;
}

// ˳���ͷ��
void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	// ����
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("˳���������%d����ͷ������.\n", x);
		return;
	}
	for (size_t i = plist->size; i > 0; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[0] = x;
	plist->size++;
}

// ��ӡ˳���
void SeqListShow(SeqList *plist)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; ++i)
	{
		printf("%d ", plist->base[i]);
	}
	printf("\n");
}

// ˳���βɾ
void SeqListPopBack(SeqList *plist)
{
	assert(plist != NULL);
	//�п�
	if (IsEmpty(plist))
	{
		printf("˳����Կգ�����β��ɾ��.\n");
		return;
	}
	plist->size--;
}

// ˳���ͷɾ
void SeqListPopFront(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("˳����Կգ�����ͷ��ɾ��.\n");
		return;
	}
	for (size_t i = 0; i < plist->size; ++i)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}

// ˳���λ�ò���
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("˳������������ܽ��а�λ�ò���\n");
		return false;
	}
	if (pos<0 || pos>plist->size)
	{
		printf("Ҫ�����λ���ǷǷ�λ��\n");
		return false;
	}
	for (size_t i = plist->size; i > pos; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[pos] = x;
	plist->size++;
	return true;
}

// ˳���ֵ����
bool SeqListInsertByVal(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("˳������������ܲ���\n");
		return false;
	}
	size_t end = plist->size - 1; 
	while (end >=0 && x < plist->base[end])
	{
		plist->base[end + 1] = plist->base[end];
		end--;
	}
	plist->base[end+1] = x;
	plist->size++;
	/*
	size_t pos = 0;
	while (pos<plist->size && x>plist->base[pos])
		pos++;
	for (size_t i = plist->size; i>pos; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[pos] = x;
	plist->size++;
	*/
}

// ˳���λ��ɾ��
void SeqListEraseByPos(SeqList *plist, int pos)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("˳����ѿգ�������ɾ������\n");
		return;
	}
	if (pos<0 || pos>=plist->size)
	{
		printf("ɾ��λ�÷Ƿ�������ɾ������.\n");
		return;
	}
	for (size_t i = pos; i < plist->size; ++i)
		plist->base[i] = plist->base[i + 1];
	plist->size--;
}

// ˳���ֵɾ��
void SeqListEraseByVal(SeqList *plist, ElemType key)
{
	assert(plist != NULL);
	int pos = SeqListFind(plist, key);
	if (pos == -1)
		return;
	SeqListEraseByPos(plist,pos);
}

// ˳�������
void SeqListSort(SeqList *plist)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size - 1; ++i)
	{
		int flag = 0;
		for (size_t j = 0; j < plist->size - i - 1; ++j)
		{
			if (plist->base[j] > plist->base[j + 1])
			{
				Swap(&plist->base[j], &plist->base[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)//����������
			break;
	}
}

// ����˳�����Ч���ֳ���
size_t SeqListLength(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size;
}
// ����˳���������С
size_t SeqListCapacity(SeqList *plist)
{
	assert(plist != NULL);
	return plist->capacity;
}

// ˳������
int SeqListFind(SeqList *plist, ElemType key)
{
	assert(plist != NULL);
	int pos = 0;
	while (pos < plist->size && key != plist->base[pos])
		pos++;
	if (pos == plist->size)
		pos = -1; 
	return pos;
}

// ˳�������
void SeqListReverse(SeqList *plist)
{
	assert(plist != NULL);
	int start = 0;
	int end = plist->size - 1;
	while (start < end)
	{
		Swap(&plist->base[start], &plist->base[end]);
		start++;
		end--;
	}
}

// ����˳����ͷԪ��
ElemType SeqListFront(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("˳����Կգ�����ȡ��Ԫ��\n");
		//return ;
	}
	return plist->base[0];
}

// ����˳����β
ElemType SeqListBack(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("˳����Կգ�����ȡ��βԪ��\n");
		//return;
	}
	return plist->base[plist->size - 1];
}

// ˳�����ֲ���
int SeqListFind_Binary(SeqList *plist, ElemType key)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
		return -1;
	int start = 0;
	int end = plist->size - 1;
	int mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (key == plist->base[mid])
			return mid;
		else if (key < plist->base[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

// ˳���ɾ������Ԫ��
void SeqListEraseAll(SeqList *plist, ElemType key)
{
	assert(plist != NULL);

}


#endif /*__SEQLIST_H_*/
