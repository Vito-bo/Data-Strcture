
#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// 链式结构：表示队列 
typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

// 队列的结构 
typedef struct Queue
{
	QueueNode* front;    //队头 
	QueueNode* back;     //队尾
}Queue;


// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->back = NULL;
}

// 销毁队列 
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

// 队尾入队列 
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

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	QueueNode* next = q->front->next;
	free(q->front);
	q->front = next;

	//处理最后一个结点被弹出的情况
	if (q->front == NULL)
	{
		q->back = NULL;
	}
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->back->data;
}

// 获取队列中有效元素个数 
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

// 检测队列是否为空，如果为空返回1，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL ? 1 : 0;
}

