#ifndef __STACK_H_
#define __STACK_H_

#include "common.h"

//栈的模拟实现
//栈：受操作限制线性表：后进先出

#define STACK_DEFAULT_SIZE 8

#if 0
//顺序栈
typedef struct SeqStack
{
	ElemType *base;   //栈空间
	size_t capacity;  //栈容量
	int top;          //栈顶指针
}SeqStack;

//顺序栈初始化
void SeqStackInit(SeqStack *pst, int sz = STACK_DEFAULT_SIZE);
//入栈
void SeqStackPush(SeqStack *pst, ElemType x);
//出栈
void SeqStackPop(SeqStack *pst);
//取栈顶元素
ElemType SeqStackTop(SeqStack *pst);
//取栈顶元素-返回栈顶元素指针
void SeqStackTop(SeqStack *pst, ElemType *top_val);
//打印栈内元素
void SeqStackShow(SeqStack *pst);
//销毁栈
void SeqStackDestroy(SeqStack *pst);
//求栈大小
int SeqStackSize(SeqStack *pst);

/////////////////////////////////////////////////////
//顺序栈判满
bool SeqStackIsFull(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top >= pst->capacity;
}

//顺序表判空
bool SeqStackIsEmpty(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top == 0;
}

//顺序栈初始化
void SeqStackInit(SeqStack *pst, int sz)
{
	assert(pst != NULL);
	pst->capacity = sz > STACK_DEFAULT_SIZE ? sz : STACK_DEFAULT_SIZE;
	pst->base = (ElemType*)malloc(sizeof(ElemType) * pst->capacity);
	pst->top = 0;
}

//入栈
void SeqStackPush(SeqStack *pst, ElemType x)
{
	assert(pst != NULL);
	if (SeqStackIsFull(pst))
	{
		printf("栈已满，%d 不能入栈.\n", x);
		return;
	}
	pst->base[pst->top++] = x;
}

//出栈
void SeqStackPop(SeqStack *pst)
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("栈已空，不能出栈\n");
		return;
	}
	pst->top--;
}

//取栈顶元素
ElemType SeqStackTop(SeqStack *pst)
{
	assert(pst != NULL);
	assert(!SeqStackIsEmpty(pst));
	return pst->base[pst->top-1];
}

//取栈顶元素-返回栈顶元素指针
void SeqStackTop(SeqStack *pst, ElemType *top_val)//入参 //出参
{
	assert(pst != NULL);
	if (SeqStackIsEmpty(pst))
	{
		printf("顺序栈已空，不能取栈顶元素\n");
		return;
	}
	*top_val = pst->base[pst->top - 1];
}

//打印栈内元素
void SeqStackShow(SeqStack *pst)
{
	assert(pst != NULL);
	for (int i = pst->top - 1; i >= 0; --i)
		printf("| %d |\n", pst->base[i]);
	printf("-----\n");
}

//销毁栈
void SeqStackDestroy(SeqStack *pst)
{
	assert(pst != NULL);
	free(pst->base);
	pst->capacity = pst->top = 0;
}

//求栈大小
int SeqStackSize(SeqStack *pst)
{
	assert(pst != NULL);
	return pst->top;
}
#endif

//链栈
typedef struct LinkStackNode
{
	ElemType data;
	struct LinkStackNode *Link;
}LinkStackNode;

typedef LinkStackNode* LinkStack;
//链栈初始化
void LinkStackInit(LinkStack *pst);
//入栈
void LinkStackPush(LinkStack *pst, ElemType x);
//出栈
void LinkStackPop(LinkStack *pst);
//取栈顶元素
ElemType LinkStackTop(LinkStack *pst);
//打印栈内元素
void LinkStackShow(LinkStack *pst);
//栈大小
int LinkStackSize(LinkStack *pst);
//销毁栈
void LinkStackDestroy(LinkStack *pst);

/////////////////////////////////////////////
//链栈初始化
void LinkStackInit(LinkStack *pst)
{
	assert(pst != NULL);
	*pst = NULL;
}

//入栈
void LinkStackPush(LinkStack *pst, ElemType x)
{
	assert(pst != NULL);
	LinkStackNode* node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	assert(node != NULL);
	node->data = x;

	//单链表头插法入栈
	node->Link = *pst;
	*pst = node;
}

//出栈
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

//取栈顶元素
ElemType LinkStackTop(LinkStack *pst)
{
	assert(pst != NULL && *pst != NULL);
	return (*pst)->data;
}

//打印栈内元素
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

//栈大小
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

//销毁栈
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



