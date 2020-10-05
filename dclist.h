
#ifndef __SCLIST_H_
#define __SCLIST_H_

#include "Common.h"

//��ͷ����˫��ѭ������

//������
typedef struct DCListNode
{
	ElemType data;
	struct DCListNode *next;
	struct DCListNode *prev;
}DCListNode;

typedef DCListNode* DCList;

//�����ʼ��
void DCListInit(DCList *phead);
//����β��
void DCListPushBack(DCList *phead, ElemType x);
//����ͷ��
void DCListPushFront(DCList *phead, ElemType x);
//��ӡ����
void DCListShow(DCList phead);
//����βɾ
void DCListPopBack(DCList *phead);
//����ͷɾ
void DCListPopFront(DCList *phead);
//��������
size_t DCListLength(DCList *phead);
//���ر�ͷԪ��
ElemType DCListFront(DCList *phead);
//���ر�βԪ��
ElemType DCListBack(DCList *phead);
//�������
void DCListClear(DCList *phead);
//��������
void DCListDestroy(DCList *phead);
//����ֵ����
DCListNode* DCListFind(DCList phead, ElemType key);
//ɾ��ĳֵ
void DCListEraseByVal(DCList phead, ElemType key);
//��������
void DCListSort(DCList phead);
//����ֵ����
void DCListInsertByVal(DCList phead, ElemType x);
//��������
void DCListReverse(DCList phead);
//��ֵɾ������
void DCListEraseAll(DCList phead, ElemType key);

//////////////////////////////////////////////////////
DCListNode * _Buynode(ElemType v = ElemType())
{
	DCListNode *_s = (DCListNode*)malloc(sizeof(DCListNode));
	_s->data = v;
	_s->prev = _s->next = _s;
	return _s;
}

//�����ʼ��
void DCListInit(DCList *phead)
{
	*phead = _Buynode();
}

//����β��
void DCListPushBack(DCList *phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode *s = _Buynode(x);
	DCListNode *head = *phead;
	
	s->prev = head->prev;
	s->next = head;
	head->prev->next = s; //s->prev->next = s
	head->prev = s;
}

//����ͷ��
void DCListPushFront(DCList *phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode *s = _Buynode(x);

	DCListNode *head = *phead;

	s->prev = head;
	s->next = head->next;
	s->prev->next = s;
	s->next->prev = s;
}

//��ӡ����
void DCListShow(DCList phead)
{
	DCListNode *p = phead->next;

	while (p != phead)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

//����βɾ
void DCListPopBack(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *head = *phead;

	if (head->next == NULL) //�п�
		return;

	DCListNode *p = head->prev;
	p->prev->next = head; //pָ�����һ�����
	head->prev = p->prev;
	free(p);
}

//����ͷɾ
void DCListPopFront(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *head = *phead;

	if (head->next == NULL) //�п�
		return;

	DCListNode *p = head->next;
	p->next->prev = head;   //p->next->prev = p->prev
	head->next = p->next;   //p->prev->next = head->next;
	free(p);
}

//��������
size_t DCListLength(DCList phead)
{
	assert(phead != NULL);

	size_t size = 0;
	DCListNode *p = phead->next;
	while (p != phead)
	{
		++size;
		p = p->next;
	}
	return size;
}

//���ر�ͷԪ��
ElemType DCListFront(DCList phead)
{
	assert(phead != NULL);
	assert(phead->next != phead);;

	return phead->next->data;
}

//���ر�βԪ��
ElemType DCListBack(DCList phead)
{
	assert(phead != NULL);
	assert(phead->next != phead);

	return phead->prev->data;
}

//�������
void DCListClear(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->next;

	while (p != (*phead))
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = (*phead)->next; //����p
	}
}

//��������
void DCListDestroy(DCList *phead)
{
	assert(phead != NULL);
	DCListClear(phead);
	free(*phead);   //�ͷ�ͷ���
	*phead = NULL;  //Ԥ��Ұָ��
}

//����ֵ����
DCListNode* DCListFind(DCList phead, ElemType key)
{
	assert(phead != NULL);
	DCListNode *p = phead->next;
	while (p != phead && p->data != key)
		p = p->next;
	if (p == phead)
		return NULL;
	return p;
}

//ɾ��ĳֵ
void DCListEraseByVal(DCList phead, ElemType key)
{
	assert(phead != NULL);
	DCListNode *p = DCListFind(phead, key);
	if (p == NULL)
		return;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

//��������
void DCListSort(DCList phead)
{
	assert(phead != NULL);
	if (DCListLength(phead) == 1)
		return;

	DCListNode *p = phead->next;
	DCListNode *q = p->next;
	//ȡ�� ͷ�͵�һ�����
	p->next = phead;
	phead->prev = p;

	while (q != phead)
	{
		p = q;
		q = q->next;

		DCListNode *tmp = phead->next;
		while (tmp != phead && p->data > tmp->data)
			tmp = tmp->next;
		p->next = tmp;
		p->prev = tmp->prev;
		p->next->prev = p;
		p->prev->next = p;
	}
}

//����ֵ����
void DCListInsertByVal(DCList phead, ElemType x)
{
	assert(phead != NULL);
	DCListNode *p = phead->next;
	while (p != phead && x > p->data)
		p = p->next;
	
	DCListNode *s = _Buynode(x);
	s->next = p;
	s->prev = p->prev;
	s->prev->next = s;
	s->next->prev = s;
}

//��������
void DCListReverse(DCList phead)
{
	assert(phead != NULL);
	if (DCListLength(phead) == 1)
		return;
	DCListNode *p = phead->next;
	DCListNode *q = p->next;
	p->next = phead;
	phead->prev = p;

	while (q != phead)
	{
		p = q;
		q = q->next;

		p->next = phead->next;
		p->prev = phead;
		p->next->prev = p;
		p->prev->next = p;
	}
}





#endif /*__SCLIST_H_*/