
#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

// ˳���ľ�̬�洢 
#define MAX 100 
typedef int SLDataType;

typedef struct SeqList 
{
	SLDataType arr[MAX]; // �������� 
	size_t size;       // ��Ч���ݵĸ���     
}SeqList;

// ������ɾ��Ľӿ� 
// ��̬˳����ʼ�� 
void SeqListInit(SeqList* ps); 

// ��̬˳������� 
void SeqListDestory(SeqList* ps); 

// ��̬˳����ӡ 
void SeqListPrint(SeqList* ps); 

// ��̬˳���β�� 
void SeqListPushBack(SeqList* ps, SLDataType x); 

// ��̬˳���βɾ 
void SeqListPopBack(SeqList* ps); 

// ��̬˳���ͷ�� 
void SeqListPushFront(SeqList* ps, SLDataType x); 

// ��̬˳���ͷɾ 
void SeqListPopFront(SeqList* ps); 

// ��̬˳������
int SeqListFind(SeqList* ps, SLDataType x);

// ��̬˳�����posλ�ò���x 
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x); // ˳���ɾ��posλ�õ�ֵ void SeqListErase(SeqList* psl, size_t pos); 

// ��̬˳�������ݸ���
void SeqListUpdata(SeqList* ps, size_t pos, SLDataType x);

// ��̬˳����ð������
void SeqListBubbleSort(SeqList *ps);



#endif