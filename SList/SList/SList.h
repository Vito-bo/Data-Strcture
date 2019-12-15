
#ifndef __SLIST_H__
#define __SLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

// ��ͷ+����+��ѭ��������ɾ���ʵ�� 
typedef int SLTDateType; 
typedef struct SListNode 
{    
	SLTDateType data;    
	struct SListNode* next; 
}SListNode;

// ��̬����һ���ڵ� 
SListNode* BuySListNode(SLTDateType x); 

// �������ӡ 
void SListPrint(SListNode* plist); 

// ������β�� 
void SListPushBack(SListNode** pplist, SLTDateType x); 

// �������βɾ 
void SListPopBack(SListNode** pplist);

// �������ͷ�� 
void SListPushFront(SListNode** pplist, SLTDateType x);

// ������ͷɾ 
void SListPopFront(SListNode** pplist);

// ��������� 
SListNode* SListFind(SListNode* plist, SLTDateType x);

// ��������posλ��֮�����x 
void SListInsertAfter(SListNode* pos, SLTDateType x);

//������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos);

#endif 