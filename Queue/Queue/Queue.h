
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// ��ʽ�ṹ����ʾ���� 
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

// ���еĽṹ 
typedef struct Queue
{
	QueueNode* front;    //��ͷ 
	QueueNode* back;     //��β
}Queue;


// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->back = NULL;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	QueueNode* cur = q->front;
	while (cur != NULL)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->back = NULL;
}

// ��β����� 
void QueuePush(Queue* q, QDataType x)
{
	assert(q);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->data = x;
	newnode->next = NULL;
	if (q->back == NULL)
	{
		q->front = q->back = newnode;
	}
	else
	{
		q->back->next = newnode;
		q->back = newnode;
	}
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	QueueNode* next = q->front->next;
	free(q->front);
	q->front = next;

	//�������һ����㱻���������
	if (q->front == NULL)
	{
		q->back = NULL;
	}
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->back->data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	int n = 0;
	QueueNode* cur = q->front;
	while (cur != NULL)
	{
		++n;
		cur = cur->next;
	}
	return n;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ���1������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL ? 1 : 0;
}

