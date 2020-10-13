#ifndef __QUEUE_H_
#define __QUEUE_H_

#include "Common.h"

#define QUEUE_DEFAULT_SIZE 8




#if 0
// ����ʵ�ֶ���
typedef struct  SeqQueue
{
	ElemType *base;
	int   capacity;
	int   front;
	int   rear;
}SeqQueue;

//���г�ʼ��
void SeqQueueInit(SeqQueue *psq, int sz = QUEUE_DEFAULT_SIZE);
//�����
void SeqQueueEn(SeqQueue *psq, ElemType x);
//������
void SeqQueueDe(SeqQueue *psq);
//ȡ���ж�ͷԪ��
ElemType SeqQueueFront(SeqQueue *psq);
//�����п�
bool SeqQueueEmpty(SeqQueue *psq);
//����չʾ
void SeqQueueShow(SeqQueue *psq);
//��������
void SeqQueueDestroy(SeqQueue *psq);

////////////////////////////////////////////////////////////////////
//���г�ʼ��
void SeqQueueInit(SeqQueue *psq, int sz)
{
	assert(psq != NULL);
	psq->capacity = sz > QUEUE_DEFAULT_SIZE ? sz : QUEUE_DEFAULT_SIZE;
	psq->base = (ElemType*)malloc(sizeof(ElemType)*psq->capacity);
	psq->front = psq->rear = 0;
}

//�����
void SeqQueueEn(SeqQueue *psq, ElemType x)
{
	assert(psq != NULL);
	if (psq->rear >= psq->capacity)
	{
		printf("����������%d�������\n", x);
		return;
	}
	psq->base[psq->rear++] = x;
}

//������
void SeqQueueDe(SeqQueue *psq)
{
	assert(psq != NULL);
	if (SeqQueueEmpty(psq))
	{
		printf("�����ѿգ����ܳ���\n");
		return;
	}
	psq->front++;
}

//ȡ���ж�ͷԪ��
ElemType SeqQueueFront(SeqQueue *psq)
{
	assert(psq != NULL);
	assert(!SeqQueueEmpty(psq));
	return psq->base[psq->front];
}
//�����п�
bool SeqQueueEmpty(SeqQueue *psq)
{
	assert(psq != NULL);
	return psq->front == psq->rear;
}

//����չʾ
void SeqQueueShow(SeqQueue *psq)
{
	assert(psq != NULL);
	for (int i = psq->front; i < psq->rear; i++)
		printf("%d ", psq->base[i]);
	printf("\n");
}

//��������
void SeqQueueDestroy(SeqQueue *psq)
{
	assert(psq != NULL);
	free(psq->base);
	psq->capacity = psq->front = psq->rear = 0;
}
#endif

//ѭ������
typedef struct CycleSeqQueue
{
	ElemType *base;
	int		 capacity;
	int      front;
	int      rear;
}CycleSeqQueue;

//ѭ�����г�ʼ��
void CycleSeqQueueInit(CycleSeqQueue *pcq, int sz = QUEUE_DEFAULT_SIZE);
//�����
void CycleSeqQueueEn(CycleSeqQueue *pcq, ElemType x);
//������
void CycleSeqQueueDe(CycleSeqQueue *pcq);
//ȡ���ж�ͷԪ��
ElemType CycleSeqQueueFront(CycleSeqQueue *pcq);
//�����п�
bool CycleSeqQueueEmpty(CycleSeqQueue *pcq);
//����չʾ
void CycleSeqQueueShow(CycleSeqQueue *pcq);
//��������
void CycleSeqQueueDestroy(CycleSeqQueue *pcq);

///////////////////////////////////////////////////////

//ѭ����������
bool IsFull(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	return ((pcq->rear + 1) % (pcq->capacity + 1)) == pcq->front;
}

//ѭ�������п�
bool IsEmpty(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	return pcq->rear == pcq->front;
}

//ѭ�����г�ʼ��
void CycleSeqQueueInit(CycleSeqQueue *pcq, int sz)
{
	assert(pcq != NULL);
	pcq->capacity = sz > QUEUE_DEFAULT_SIZE ? sz : QUEUE_DEFAULT_SIZE;
	pcq->base = (ElemType*)malloc(sizeof(ElemType)*(pcq->capacity + 1));
	pcq->front = pcq->rear = 0;
}

//�����
void CycleSeqQueueEn(CycleSeqQueue *pcq, ElemType x)
{
	assert(pcq != NULL);
	if (IsFull(pcq))
	{
		printf("����������%d���������\n", x);
		return;
	}
	pcq->base[pcq->rear] = x;
	pcq->rear = (pcq->rear + 1) % (pcq->capacity + 1);
}

//������
void CycleSeqQueueDe(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	if (IsEmpty(pcq))
	{
		printf("�����ѿգ����ܳ���\n");
		return;
	}
	pcq->front = (pcq->front + 1) % (pcq->capacity + 1);
}

//ȡ���ж�ͷԪ��
ElemType CycleSeqQueueFront(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	assert(!IsEmpty(pcq));
	return pcq->base[pcq->front];
}

//����չʾ
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

//��������
void CycleSeqQueueDestroy(CycleSeqQueue *pcq)
{
	assert(pcq != NULL);
	free(pcq->base);
	pcq->base = NULL;
	pcq->capacity = pcq->front = pcq->rear = 0;
}

#endif /*__QUEUE_H_*/