
#include "SList.h"

// ��ͷ+����+��ѭ��������ɾ���ʵ�� 
// ��̬����һ���ڵ� 
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;

	return node;
}

//�������ӡ
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

// ������β�� 
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

// �������βɾ
void SListPopBack(SListNode** pplist)
{
	//��������ָ�룬ͬʱ��������������ҵ���β
	SListNode* prev = NULL;
	SListNode* tail = *pplist;
	//1.��
	//2.ֻ��һ���ڵ�
	if (tail == NULL || tail->next == NULL)
	{
		free(tail);
		*pplist = NULL;
	}
	//3.���������ϵĽڵ�
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

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	// 1.��
	// 2.�ǿ�
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

//�������ͷɾ
void SListPopFront(SListNode** pplist)
{
	// 1.��
	// 2.һ��
	// 3.����������
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

// ���������(�ҵ����ظý��ĵ�ַ��û�ҵ�����NULL)
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	assert(plist);
	// 1.��
	// 2.һ��
	// 3.����������
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


