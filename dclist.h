
#ifndef __SCLIST_H_
#define __SCLIST_H_

#include "Common.h"

//带头结点的双向循环链表

//定义结点
typedef struct DCListNode
{
	ElemType data;
	struct DCListNode *next;
	struct DCListNode *prev;
}DCListNode;

typedef DCListNode* DCList;

//链表初始化
void DCListInit(DCList *phead);
//链表尾插
void DCListPushBack(DCList *phead, ElemType x);
//链表头插
void DCListPushFront(DCList *phead, ElemType x);
//打印链表
void DCListShow(DCList phead);
//链表尾删
void DCListPopBack(DCList *phead);
//链表头删
void DCListPopFront(DCList *phead);
//求链表长度
size_t DCListLength(DCList *phead);
//返回表头元素
ElemType DCListFront(DCList *phead);
//返回表尾元素
ElemType DCListBack(DCList *phead);
//链表清空
void DCListClear(DCList *phead);
//链表销毁
void DCListDestroy(DCList *phead);
//链表按值查找
DCListNode* DCListFind(DCList phead, ElemType key);
//删除某值
void DCListEraseByVal(DCList phead, ElemType key);
//链表排序
void DCListSort(DCList phead);
//链表按值插入
void DCListInsertByVal(DCList phead, ElemType x);
//链表逆置
void DCListReverse(DCList phead);
//按值删除所有
void DCListEraseAll(DCList phead, ElemType key);

//////////////////////////////////////////////////////
DCListNode * _Buynode(ElemType v = ElemType())
{
	DCListNode *_s = (DCListNode*)malloc(sizeof(DCListNode));
	_s->data = v;
	_s->prev = _s->next = _s;
	return _s;
}

//链表初始化
void DCListInit(DCList *phead)
{
	*phead = _Buynode();
}

//链表尾插
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

//链表头插
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

//打印链表
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

//链表尾删
void DCListPopBack(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *head = *phead;

	if (head->next == NULL) //判空
		return;

	DCListNode *p = head->prev;
	p->prev->next = head; //p指向最后一个结点
	head->prev = p->prev;
	free(p);
}

//链表头删
void DCListPopFront(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *head = *phead;

	if (head->next == NULL) //判空
		return;

	DCListNode *p = head->next;
	p->next->prev = head;   //p->next->prev = p->prev
	head->next = p->next;   //p->prev->next = head->next;
	free(p);
}

//求链表长度
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

//返回表头元素
ElemType DCListFront(DCList phead)
{
	assert(phead != NULL);
	assert(phead->next != phead);;

	return phead->next->data;
}

//返回表尾元素
ElemType DCListBack(DCList phead)
{
	assert(phead != NULL);
	assert(phead->next != phead);

	return phead->prev->data;
}

//链表清空
void DCListClear(DCList *phead)
{
	assert(phead != NULL);
	DCListNode *p = (*phead)->next;

	while (p != (*phead))
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
		p = (*phead)->next; //更新p
	}
}

//链表销毁
void DCListDestroy(DCList *phead)
{
	assert(phead != NULL);
	DCListClear(phead);
	free(*phead);   //释放头结点
	*phead = NULL;  //预防野指针
}

//链表按值查找
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

//删除某值
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

//链表排序
void DCListSort(DCList phead)
{
	assert(phead != NULL);
	if (DCListLength(phead) == 1)
		return;

	DCListNode *p = phead->next;
	DCListNode *q = p->next;
	//取下 头和第一个结点
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

//链表按值插入
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

//链表逆置
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