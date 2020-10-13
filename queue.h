#ifndef __QUEUE_H_
#define __QUEUE_H_

#include "Common.h"

#define QUEUE_DEFAULT_SIZE 8




#if 0
// 数组实现队列
typedef struct  SeqQueue
{
	ElemType *base;
	int   capacity;
	int   front;
	int   rear;
}SeqQueue;

//队列初始化
void SeqQueueInit(SeqQueue *psq, int sz = QUEUE_DEFAULT_SIZE);
//入队列
void SeqQueueEn(SeqQueue *psq, ElemType x);
//出队列
void SeqQueueDe(SeqQueue *psq);
//取队列队头元素
ElemType SeqQueueFront(SeqQueue *psq);
//队列判空
bool SeqQueueEmpty(SeqQueue *psq);
//队列展示
void SeqQueueShow(SeqQueue *psq);
//队列销毁
void SeqQueueDestroy(SeqQueue *psq);

////////////////////////////////////////////////////////////////////
//队列初始化
void SeqQueueInit(SeqQueue *psq, int sz)
{
	assert(psq != NULL);
	psq->capacity = sz > QUEUE_DEFAULT_SIZE ? sz : QUEUE_DEFAULT_SIZE;
	psq->base = (ElemType*)malloc(sizeof(ElemType)*psq->capacity);
	psq->front = psq->rear = 0;
}

//入队列
void SeqQueueEn(SeqQueue *psq, ElemType x)
{
	assert(psq != NULL);
	if (psq->rear >= psq->capacity)
	{
		printf("队列已满，%d不能入队\n", x);
		return;
	}
	psq->base[psq->rear++] = x;
}

//出队列
void SeqQueueDe(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueEmpty(psq))
	{
		printf("队列已空，不能出队\n");
		return;
	}
	psq->front++;
}

//取队列队头元素
ElemType SeqQueueFront(SeqQueue *psq)
{
	assert(psq != NULL);
	assert(!SeqQueueEmpty(psq));
	return psq->base[psq->front];
}
//队列判空
bool SeqQueueEmpty(SeqQueue *psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}

//队列展示
void SeqQueueShow(SeqQueue *psq)
{
	assert(psq != NULL);
	for (int i = psq->front; i < psq->rear; i++)
		printf("%d ", psq->base[i]);
	printf("\n");
}

//队列销毁
void SeqQueueDestroy(SeqQueue *psq)
{
	assert(psq != NULL);
	free(psq->base);
	psq->capacity = psq->front = psq->rear = 0;
}
#endif

//循环队列
typedef struct CycleSeqQueue
{
	ElemType *base;
	int		 capacity;
	int      front;
	int      rear;
}CycleSeqQueue;

//循环队列初始化
void CycleSeqQueueInit(CycleSeqQueue *pcq, int sz = QUEUE_DEFAULT_SIZE);
//入队列
void CycleSeqQueueEn(CycleSeqQueue *pcq, ElemType x);
//出队列
void CycleSeqQueueDe(CycleSeqQueue *pcq);
//取队列队头元素
ElemType CycleSeqQueueFront(CycleSeqQueue *pcq);
//队列判空
bool CycleSeqQueueEmpty(CycleSeqQueue *pcq);
//队列展示
void CycleSeqQueueShow(CycleSeqQueue *pcq);
//队列销毁
void CycleSeqQueueDestroy(CycleSeqQueue *pcq);

///////////////////////////////////////////////////////

//循环队列判满
bool IsFull(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	return ((pcq->rear + 1) % (pcq->capacity + 1)) == pcq->front;
}

//循环队列判空
bool IsEmpty(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	return pcq->rear == pcq->front;
}

//循环队列初始化
void CycleSeqQueueInit(CycleSeqQueue *pcq, int sz)
{
	assert(pcq != NULL);
	pcq->capacity = sz > QUEUE_DEFAULT_SIZE ? sz : QUEUE_DEFAULT_SIZE;
	pcq->base = (ElemType*)malloc(sizeof(ElemType)*(pcq->capacity + 1));
	pcq->front = pcq->rear = 0;
}

//入队列
void CycleSeqQueueEn(CycleSeqQueue *pcq, ElemType x)
{
	assert(pcq != NULL);
	if (IsFull(pcq))
	{
		printf("队列已满，%d不能入队列\n", x);
		return;
	}
	pcq->base[pcq->rear] = x;
	pcq->rear = (pcq->rear + 1) % (pcq->capacity + 1);
}

//出队列
void CycleSeqQueueDe(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	if (IsEmpty(pcq))
	{
		printf("队列已空，不能出队\n");
		return;
	}
	pcq->front = (pcq->front + 1) % (pcq->capacity + 1);
}

//取队列队头元素
ElemType CycleSeqQueueFront(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	assert(!IsEmpty(pcq));
	return pcq->base[pcq->front];
}

//队列展示
void CycleSeqQueueShow(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	for (int i = pcq->front; i != pcq->rear;)
	{
		printf("%d ", pcq->base[i]);
		i = (i + 1) % (pcq->capacity + 1);
	}
	printf("\n");
}

//队列销毁
void CycleSeqQueueDestroy(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	free(pcq->base);
	pcq->base = NULL;
	pcq->capacity = pcq->front = pcq->rear = 0;
}

#endif /*__QUEUE_H_*/