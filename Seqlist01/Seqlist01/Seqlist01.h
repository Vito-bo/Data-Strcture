
#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

// 顺序表的静态存储 
#define MAX 100 
typedef int SLDataType;

typedef struct SeqList 
{
	SLDataType arr[MAX]; // 定长数组 
	size_t size;       // 有效数据的个数     
}SeqList;

// 基本增删查改接口 
// 静态顺序表初始化 
void SeqListInit(SeqList* ps); 

// 静态顺序表销毁 
void SeqListDestory(SeqList* ps); 

// 静态顺序表打印 
void SeqListPrint(SeqList* ps); 

// 静态顺序表尾插 
void SeqListPushBack(SeqList* ps, SLDataType x); 

// 静态顺序表尾删 
void SeqListPopBack(SeqList* ps); 

// 静态顺序表头插 
void SeqListPushFront(SeqList* ps, SLDataType x); 

// 静态顺序表头删 
void SeqListPopFront(SeqList* ps); 

// 静态顺序表查找
int SeqListFind(SeqList* ps, SLDataType x);

// 静态顺序表在pos位置插入x 
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x); // 顺序表删除pos位置的值 void SeqListErase(SeqList* psl, size_t pos); 

// 静态顺序表的数据更新
void SeqListUpdata(SeqList* ps, size_t pos, SLDataType x);

// 静态顺序表的冒泡排序
void SeqListBubbleSort(SeqList *ps);



#endif