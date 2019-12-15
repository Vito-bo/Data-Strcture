
#ifndef __SLIST_H__
#define __SLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

// 无头+单向+非循环链表增删查改实现 
typedef int SLTDateType; 
typedef struct SListNode 
{    
	SLTDateType data;    
	struct SListNode* next; 
}SListNode;

// 动态申请一个节点 
SListNode* BuySListNode(SLTDateType x); 

// 单链表打印 
void SListPrint(SListNode* plist); 

// 单链表尾插 
void SListPushBack(SListNode** pplist, SLTDateType x); 

// 单链表的尾删 
void SListPopBack(SListNode** pplist);

// 单链表的头插 
void SListPushFront(SListNode** pplist, SLTDateType x);

// 单链表头删 
void SListPopFront(SListNode** pplist);

// 单链表查找 
SListNode* SListFind(SListNode* plist, SLTDateType x);

// 单链表在pos位置之后插入x 
void SListInsertAfter(SListNode* pos, SLTDateType x);

//单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos);

#endif 