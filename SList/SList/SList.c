
#include "SList.h"

// 无头+单向+非循环链表增删查改实现 
// 动态申请一个节点 
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;

	return node;
}

//单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 单链表尾插 
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	//定义两个指针，同时往后遍历单链表找到表尾
	SListNode* prev = NULL;
	SListNode* tail = *pplist;
	//1.空
	//2.只有一个节点
	if (tail == NULL || tail->next == NULL)
	{
		free(tail);
		*pplist = NULL;
	}
	//3.两个及以上的节点
	else
	{
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	// 1.空
	// 2.非空
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}

//单链表的头删
void SListPopFront(SListNode** pplist)
{
	// 1.空
	// 2.一个
	// 3.两个及以上
	SListNode* first = *pplist;
	if (first == NULL)
	{
		return ;
	}
	else if (first->next == NULL)
	{
		free(first);
		*pplist = NULL;
	}
	else
	{
		SListNode* next = first->next;
		free(first);
		*pplist = next;
	}
}

// 单链表查找(找到返回该结点的地址，没找到返回NULL)
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	// 1.空
	// 2.一个
	// 3.两个及以上
	while (plist != NULL)
	{
		if (plist->data == x)
		{
			return plist;
		}
		plist = plist->next;
	}
	return NULL;
}


