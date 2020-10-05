#ifndef __SLIST_H_
#define __SLIST_H_

// �������ʵ��
#include "Common.h"


//����ͷ��㵥����
typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;

typedef SListNode* SList;

//��ʼ��������
void SListInit(SList *phead);
//�������п�
bool SListEmpty(SList *phead);
//������β��
void SListPushBack(SList *phead, ElemType x);
//������ͷ��
void SListPushFront(SList *phead, ElemType x);
//������βɾ 
void SListPopBack(SList* phead);
//������ͷɾ
void SListPopFront(SList* phead);
//��ӡ������
void SListShow(SList *phead);
//��������
size_t SListLength(SList *phead);

//��ֵѰ��ĳ�����
SListNode* SListFind(SList phead, ElemType key);
//��ֵɾ�����н��
void SListEraseByVal(SList *phead, ElemType key);
//��ֵ������
void SListInsertByVal(SList *phead, ElemType key);
//����������
void SListSort(SList *phead);

//����ͷ���
ElemType SListFront(SList phead);
//����β���
ElemType SListBack(SList phead);
//ɾ������������
void SListEraseAll(SList *phead, ElemType key);
//�������
void SListClear(SList *phead);
//��������
void SListDestroy(SList *phead);
//��������
void SListReverse(SList *phead);

/////////////////////////////////////////////////////////////

//��ʼ��������
void SListInit(SList *phead)
{
	assert(phead != NULL);
	*phead = NULL;
}

//�������п�
bool SListEmpty(SList *phead)
{
	return *phead == NULL;
}

//������β��
void SListPushBack(SList *phead, ElemType x)
{
	assert(phead != NULL);
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	//���ӽ��
	SListNode *p = *phead;
	if (p == NULL)//����Ľڵ�Ϊ��һ�����
		*phead = s;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = s;
	}
}

//������ͷ��
void SListPushFront(SList *phead, ElemType x)
{
	assert(phead != NULL);
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;

	//���ӽ��
	s->next = *phead;
	*phead = s;
}

//������βɾ 
void SListPopBack(SList* phead)
{
	assert(phead != NULL);
	SListNode *p = *phead;
	SListNode *prev = NULL;

	if (p != NULL)
	{
		while (p->next != NULL)
		{
			prev = p;
			p = p->next;
		}
		//��Ҫ�����ͷŵĽ���Ƿ�Ϊ���һ�����
		if (prev == NULL)
			*phead = NULL;
		else
			prev->next = NULL;
		free(p);
	}
}


//������ͷɾ
void SListPopFront(SList* phead)
{
	assert(phead != NULL);
	SListNode* p = *phead;
	if (p != NULL)
	{
		*phead = p->next;
		free(p);
	} 
} 
 
//��ӡ������
void SListShow(SList phead)
{
	//assert(phead != NULL);
	SListNode *p = phead;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

//��������
size_t SListLength(SList phead)
{
	//assert(phead != NULL);
	size_t len = 0;
	SListNode *p = phead;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

//��ֵѰ��ĳ�����
SListNode* SListFind(SList phead, ElemType key)
{
#if 0
	SListNode *p = phead;
	while (p != NULL)
	{
		if (p->data == key)
			return p;
		p = p->next;
	}
	return NULL;
#endif
	SListNode *p = phead;
	while (p != NULL && p->data != key) //˳���ܵߵ�
		p = p->next;
	return p;
}

//��ֵɾ�����н��
void SListEraseByVal(SList *phead, ElemType key)
{
#if 0
	assert(phead != NULL);
	SListNode *p = SListFind(*phead, key);
	if (p == NULL)
		return;
	if (p->next == NULL)//ɾ������ĩβ���
		SListPopBack(phead);
	else
	{
		SListNode *q = p->next;
		p->data = q->data;
		p->next = q->next;
		free(q);
	}
#endif
	assert(phead != NULL);
	SListNode *p = SListFind(*phead, key);
	if (p == NULL)
		return;
	
	SListNode *prev = *phead;
	while (prev != p && prev->next != p)
		prev = prev->next;
	if (prev == p)
		*phead = p->next;
	else
		prev->next = p->next;
	free(p);
}

//��ֵ������
void SListInsertByVal(SList *phead, ElemType key);

//����������
//ͨ��������ַ���޸�ָ�룩����
void SListSort(SList *phead)
{
	 
}

//����ͷ���
ElemType SListFront(SList phead)
{
	assert(phead != NULL);
	return phead->data;
}

//����β���
ElemType SListBack(SList phead)
{
	assert(phead != NULL);
	SListNode *p = phead;
	while (p->next != NULL)
		p = p->next;
	return p->data;
}

//ɾ������������
void SListEraseAll(SList *phead, ElemType key)
{

}
//�������
void SListClear(SList *phead)
{
	assert(phead != NULL);
	SListNode *p = NULL;
	while (*phead != NULL)
	{
		p = *phead;
		*phead = p->next;
		free(p);
	}
}

//��������
void SListDestroy(SList *phead)
{
	SListClear(phead);
}
//��������
void SListReverse(SList *phead)
{
	//ͷ�巨ʹ��������
	assert(phead != NULL);

	SListNode *p = *phead;
	SListNode *q = p->next;
	p->next = NULL;  //�ָ����һ�����

	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = *phead;
		*phead = p;
	}

}


































 
#endif /* __SLIST_H_ */
