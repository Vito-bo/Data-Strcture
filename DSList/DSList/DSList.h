
#pragma once
#ifndef __DSLIST_H__
#define __DSLIST_H__

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>


typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;


//����һ���½��
ListNode* BuyListNode(LTDataType x);

// �������������ͷ���. 
ListNode* ListCreate(); 

// ˫���������� 
void ListDestory(ListNode* phead);

// ˫�������ӡ 
void ListPrint(ListNode* phead); 

// ˫������β�� 
void ListPushBack(ListNode* phead, LTDataType x);

// ˫������βɾ 
void ListPopBack(ListNode* phead);

// ˫������ͷ��
void ListPushFront(ListNode* phead, LTDataType x);

// ˫������ͷɾ 
void ListPopFront(ListNode* phead); 

// ˫��������� 
ListNode* ListFind(ListNode* phead, LTDataType x);

// ˫��������pos��ǰ����в��� 
void ListInsert(ListNode* pos, LTDataType x);

// ˫������ɾ��posλ�õĽڵ� 
void ListErase(ListNode* pos); 


#endif