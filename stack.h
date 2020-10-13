#ifndef __STACK_H_
#define __STACK_H_

#include "common.h"

//ջ��ģ��ʵ��
//ջ���ܲ����������Ա�����ȳ�

#define STACK_DEFAULT_SIZE 8

#if 0
//˳��ջ
typedef struct SeqStack
{
	ElemType *base;   //ջ�ռ�
	size_t capacity;  //ջ����
	int top;          //ջ��ָ��
}SeqStack;

//˳��ջ��ʼ��
void SeqStackInit(SeqStack *pst, int sz = STACK_DEFAULT_SIZE);
//��ջ
void SeqStackPush(SeqStack *pst, ElemType x);
//��ջ
void SeqStackPop(SeqStack *pst);
//ȡջ��Ԫ��
ElemType SeqStackTop(SeqStack *pst);
//ȡջ��Ԫ��-����ջ��Ԫ��ָ��
void SeqStackTop(SeqStack *pst, ElemType *top_val);
//��ӡջ��Ԫ��
void SeqStackShow(SeqStack *pst);
//����ջ
void SeqStackDestroy(SeqStack *pst);
//��ջ��С
int SeqStackSize(SeqStack *pst);

/////////////////////////////////////////////////////
//˳��ջ����
bool SeqStackIsFull(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}

//˳����п�
bool SeqStackIsEmpty(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top == 0;
}

//˳��ջ��ʼ��
void SeqStackInit(SeqStack *pst, int sz)
{
	assert(pst != NULL);
	pst->capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (ElemType*)malloc(sizeof(ElemType) * pst->capacity);
	pst->top = 0;
}

//��ջ
void SeqStackPush(SeqStack *pst, ElemType x)
{
	assert(pst != NULL);
	if (SeqStackIsFull(pst))
	{
		printf("ջ������%d ������ջ.\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}

//��ջ
void SeqStackPop(SeqStack *pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("ջ�ѿգ����ܳ�ջ\n");
		return;
	}
	pst->top--;
}

//ȡջ��Ԫ��
ElemType SeqStackTop(SeqStack *pst)
{
	assert(pst != NULL);
	assert(!SeqStackIsEmpty(pst));
	return pst->base[pst->top-1];
}

//ȡջ��Ԫ��-����ջ��Ԫ��ָ��
void SeqStackTop(SeqStack *pst, ElemType *top_val)//��� //����
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("˳��ջ�ѿգ�����ȡջ��Ԫ��\n");
		return;
	}
	*top_val = pst->base[pst->top - 1];
}

//��ӡջ��Ԫ��
void SeqStackShow(SeqStack *pst)
{
	assert(pst != NULL);
	for (int i = pst->top - 1; i >= 0; --i)
		printf("| %d |\n", pst->base[i]);
	printf("-----\n");
}

//����ջ
void SeqStackDestroy(SeqStack *pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->capacity = pst->top = 0;
}

//��ջ��С
int SeqStackSize(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top;
}
#endif

//��ջ
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode *Link;
}LinkStackNode;

typedef LinkStackNode* LinkStack;
//��ջ��ʼ��
void LinkStackInit(LinkStack *pst);
//��ջ
void LinkStackPush(LinkStack *pst, ElemType x);
//��ջ
void LinkStackPop(LinkStack *pst);
//ȡջ��Ԫ��
ElemType LinkStackTop(LinkStack *pst);
//��ӡջ��Ԫ��
void LinkStackShow(LinkStack *pst);
//ջ��С
int LinkStackSize(LinkStack *pst);
//����ջ
void LinkStackDestroy(LinkStack *pst);

/////////////////////////////////////////////
//��ջ��ʼ��
void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	*pst = NULL;
}

//��ջ
void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode* node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	//������ͷ�巨��ջ
	node->Link = *pst;
	*pst = node;
}

//��ջ
void LinkStackPop(LinkStack *pst)
{
	assert(pst != NULL);
	if (*pst != NULL)
	{
		LinkStackNode *p = *pst;
		*pst = p->Link;
		free(p);
	}
}

//ȡջ��Ԫ��
ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL && *pst != NULL);
	return (*pst)->data;
}

//��ӡջ��Ԫ��
void LinkStackShow(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = *pst;
	while (p != NULL)
	{
		printf("| %d |\n", p->data);
		p = p->Link;
	}
	printf("-----\n");
}

//ջ��С
int LinkStackSize(LinkStack *pst)
{
	assert(pst != NULL);
	int size = 0;
	LinkStackNode *p = *pst;
	while (p != NULL)
	{
		++size;
		p = p->Link;
	}
	return size;
}

//����ջ
void LinkStackDestroy(LinkStack *pst)
{
	assert(pst != NULL);
	LinkStackNode *p = *pst;
	while (p!=NULL)
	{
		*pst = p->Link;
		free(p);
		p = *pst;
	}
}

#endif /*__STACK_H_*/



