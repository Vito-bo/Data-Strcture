#ifndef __SLIST_H_
#define __SLIST_H_

// 单链表的实现
#include "Common.h"


//不带头结点单链表
typedef struct SListNode
{
	ElemType data;
	struct SListNode *next;
}SListNode;

typedef SListNode* SList;

//初始化单链表
void SListInit(SList *phead);
//单链表判空
bool SListEmpty(SList *phead);
//单链表尾插
void SListPushBack(SList *phead, ElemType x);
//单链表头插
void SListPushFront(SList *phead, ElemType x);
//单链表尾删 
void SListPopBack(SList* phead);
//单链表头删
void SListPopFront(SList* phead);
//打印单链表
void SListShow(SList *phead);
//求单链表长度
size_t SListLength(SList *phead);

//按值寻找某个结点
SListNode* SListFind(SList phead, ElemType key);
//按值删除所有结点
void SListEraseByVal(SList *phead, ElemType key);
//按值插入结点
void SListInsertByVal(SList *phead, ElemType key);
//单链表排序
void SListSort(SList *phead);

//返回头结点
ElemType SListFront(SList phead);
//返回尾结点
ElemType SListBack(SList phead);
//删除所有链表结点
void SListEraseAll(SList *phead, ElemType key);
//清空链表
void SListClear(SList *phead);
//链表销毁
void SListDestroy(SList *phead);
//链表逆置
void SListReverse(SList *phead);

/////////////////////////////////////////////////////////////

//初始化单链表
void SListInit(SList *phead)
{
	assert(phead != NULL);
	*phead = NULL;
}

//单链表判空
bool SListEmpty(SList *phead)
{
	return *phead == NULL;
}

//单链表尾插
void SListPushBack(SList *phead, ElemType x)
{
	assert(phead != NULL);
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;

	//链接结点
	SListNode *p = *phead;
	if (p == NULL)//插入的节点为第一个结点
		*phead = s;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = s;
	}
}

//单链表头插
void SListPushFront(SList *phead, ElemType x)
{
	assert(phead != NULL);
	SListNode *s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;

	//链接结点
	s->next = *phead;
	*phead = s;
}

//单链表尾删 
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
		//需要考虑释放的结点是否为最后一个结点
		if (prev == NULL)
			*phead = NULL;
		else
			prev->next = NULL;
		free(p);
	}
}


//单链表头删
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
 
//打印单链表
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

//求单链表长度
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

//按值寻找某个结点
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
	while (p != NULL && p->data != key) //顺序不能颠倒
		p = p->next;
	return p;
}

//按值删除所有结点
void SListEraseByVal(SList *phead, ElemType key)
{
#if 0
	assert(phead != NULL);
	SListNode *p = SListFind(*phead, key);
	if (p == NULL)
		return;
	if (p->next == NULL)//删除的是末尾结点
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

//按值插入结点
void SListInsertByVal(SList *phead, ElemType key);

//单链表排序
//通过交换地址（修改指针）排序
void SListSort(SList *phead)
{
	 
}

//返回头结点
ElemType SListFront(SList phead)
{
	assert(phead != NULL);
	return phead->data;
}

//返回尾结点
ElemType SListBack(SList phead)
{
	assert(phead != NULL);
	SListNode *p = phead;
	while (p->next != NULL)
		p = p->next;
	return p->data;
}

//删除所有链表结点
void SListEraseAll(SList *phead, ElemType key)
{

}
//清空链表
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

//链表销毁
void SListDestroy(SList *phead)
{
	SListClear(phead);
}
//链表逆置
void SListReverse(SList *phead)
{
	//头插法使链表逆置
	assert(phead != NULL);

	SListNode *p = *phead;
	SListNode *q = p->next;
	p->next = NULL;  //分割出第一个结点

	while (q != NULL)
	{
		p = q;
		q = q->next;
		p->next = *phead;
		*phead = p;
	}

}


































 
#endif /* __SLIST_H_ */
