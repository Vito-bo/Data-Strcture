#ifndef __SEQLIST_H_
#define __SEQLIST_H_

#include "Common.h"

//静态顺序表实现

#define SEQLIST_DEFAULT_SIZE 8

//定义顺序表结构
typedef struct SeqList
{
	ElemType *base;
	size_t capacity;
	size_t size;
}SeqList;

// 顺序表初始化
void SeqListInit(SeqList *plist);
// 顺序表尾插
void SeqListPushBack(SeqList *plist, ElemType x);
// 顺序表销毁
void SeqListDestroy(SeqList *plist);
// 顺序表头插
void SeqListPushFront(SeqList *plist, ElemType x);
// 打印顺序表
void SeqListShow(SeqList *plist);
// 顺序表尾删
void SeqListPopBack(SeqList *plist);
// 顺序表头删
void SeqListPopFront(SeqList *plist);
// 顺序表清零
void SeqListClear(SeqList *plist);
// 顺序表按位置插入
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x);
// 顺序表按值插入
bool SeqListInsertByVal(SeqList *plist, ElemType x);
// 顺序表按位置删除
void SeqListEraseByPos(SeqList *plist, int pos);
// 顺序表按值删除
void SeqListEraseByVal(SeqList *plist, ElemType key);
// 顺序表排序
void SeqListSort(SeqList *plist);
// 返回顺序表有效数字长度
size_t SeqListLength(SeqList *plist);
// 返回顺序表容量大小
size_t SeqListCapacity(SeqList *plist);
// 顺序表查找
int SeqListFind(SeqList *plist, ElemType key);
// 顺序表逆置
void SeqListReverse(SeqList *plist);
// 返回顺序表表头元素
ElemType SeqListFront(SeqList *plist);
// 返回顺序表表尾
ElemType SeqListBack(SeqList *plist);
// 顺序表二分查找
int SeqListFind_Binary(SeqList *plist, ElemType key);
// 顺序表删除所有元素
void SeqListEraseAll(SeqList *plist, ElemType key);

/////////////////////////函数实现//////////////////////////////

// 扩容
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

// 顺序表判空
bool IsEmpty(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size == 0;
}

// 顺序表判满
bool IsFull(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size >= plist->capacity;
}

// 顺序表初始化
void SeqListInit(SeqList *plist)
{
	assert(plist != NULL);
	plist->capacity = SEQLIST_DEFAULT_SIZE; //空间默认开辟8
	plist->base = (ElemType*)malloc(sizeof(ElemType)*plist->capacity);
	plist->size = 0;
}

// 顺序表尾插
void SeqListPushBack(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("顺序表已满，%d不能尾部插入.\n", x);
		return;
	}
	plist->base[plist->size++] = x;
}

// 顺序表头插
void SeqListPushFront(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	// 判满
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("顺序表已满，%d不能头部插入.\n", x);
		return;
	}
	for (size_t i = plist->size; i > 0; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[0] = x;
	plist->size++;
}

// 打印顺序表
void SeqListShow(SeqList *plist)
{
	assert(plist != NULL);
	for (size_t i = 0; i < plist->size; ++i)
	{
		printf("%d ", plist->base[i]);
	}
	printf("\n");
}

// 顺序表尾删
void SeqListPopBack(SeqList *plist)
{
	assert(plist != NULL);
	//判空
	if (IsEmpty(plist))
	{
		printf("顺序表以空，不能尾部删除.\n");
		return;
	}
	plist->size--;
}

// 顺序表头删
void SeqListPopFront(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("顺序表以空，不能头部删除.\n");
		return;
	}
	for (size_t i = 0; i < plist->size; ++i)
	{
		plist->base[i] = plist->base[i + 1];
	}
	plist->size--;
}

// 顺序表按位置插入
bool SeqListInsertByPos(SeqList *plist, int pos, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("顺序表已满，不能进行按位置插入\n");
		return false;
	}
	if (pos<0 || pos>plist->size)
	{
		printf("要插入的位置是非法位置\n");
		return false;
	}
	for (size_t i = plist->size; i > pos; --i)
		plist->base[i] = plist->base[i - 1];
	plist->base[pos] = x;
	plist->size++;
	return true;
}

// 顺序表按值插入
bool SeqListInsertByVal(SeqList *plist, ElemType x)
{
	assert(plist != NULL);
	if (IsFull(plist) && !_Inc(plist, plist->capacity * 2))
	{
		printf("顺序表已满，不能插入\n");
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

// 顺序表按位置删除
void SeqListEraseByPos(SeqList *plist, int pos)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("顺序表已空，不能再删除数据\n");
		return;
	}
	if (pos<0 || pos>=plist->size)
	{
		printf("删除位置非法，不能删除数据.\n");
		return;
	}
	for (size_t i = pos; i < plist->size; ++i)
		plist->base[i] = plist->base[i + 1];
	plist->size--;
}

// 顺序表按值删除
void SeqListEraseByVal(SeqList *plist, ElemType key)
{
	assert(plist != NULL);
	int pos = SeqListFind(plist, key);
	if (pos == -1)
		return;
	SeqListEraseByPos(plist,pos);
}

// 顺序表排序
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
		if (flag == 0)//数组已有序
			break;
	}
}

// 返回顺序表有效数字长度
size_t SeqListLength(SeqList *plist)
{
	assert(plist != NULL);
	return plist->size;
}
// 返回顺序表容量大小
size_t SeqListCapacity(SeqList *plist)
{
	assert(plist != NULL);
	return plist->capacity;
}

// 顺序表查找
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

// 顺序表逆置
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

// 返回顺序表表头元素
ElemType SeqListFront(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("顺序表以空，不能取表元素\n");
		//return ;
	}
	return plist->base[0];
}

// 返回顺序表表尾
ElemType SeqListBack(SeqList *plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist))
	{
		printf("顺序表以空，不能取表尾元素\n");
		//return;
	}
	return plist->base[plist->size - 1];
}

// 顺序表二分查找
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

// 顺序表删除所有元素
void SeqListEraseAll(SeqList *plist, ElemType key)
{
	assert(plist != NULL);

}


#endif /*__SEQLIST_H_*/
