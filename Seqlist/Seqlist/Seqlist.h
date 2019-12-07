
#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//顺序表的动态存储
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* _a;      // 指向动态开辟的数组     
	size_t _size ;       // 有效数据个数     
	size_t _capacity ;   // 容量空间的大小 
}SeqList;

//基本增删查改接口
//初始化顺序表
void SeqListInit(SeqList* ps);
//销毁顺序表
void SeqListDestory(SeqList* ps);
//打印数据
void SeqListPrint(SeqList* ps);
//检查空间是否够用
void SeqListCheckCapacity(SeqList* ps);

//尾插
void SeqListPushBack(SeqList* ps, SLDataType x); 
//尾删
void SeqListPopBack(SeqList* ps); 


//头插
void SeqListPushFront(SeqList* ps, SLDataType x); 
//头删
void SeqListPopFront(SeqList* ps);

//查找
int SeqListFind(SeqList* ps, SLDataType x); 

//中间某处插入
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x); 

//指定位置删除
void SeqListErase(SeqList* ps, size_t pos); 

//指定元素删除
void SeqListRemove(SeqList* ps, SLDataType x); 

//修改某个位置的值
void SeqListModify(SeqList* ps, size_t pos, SLDataType x); 

//冒泡排序
void SeqListBubbleSort(SeqList* ps);

//冒泡排序
void SeqListBubbleSort(SeqList* ps);

//二分查找
int SeqListBinaryFind(SeqList* ps, SLDataType x);

#endif