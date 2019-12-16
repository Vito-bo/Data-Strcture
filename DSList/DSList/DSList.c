
#include"DSList.h"

//����һ���½��
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

// �������������ͷ���. 
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}

// ˫���������� 
//����һ��ָ���һ������ָ�룬����һ����㲻��ͷ��㣩��ѭ�������������ͷţ�����ָ��ָ����һ��Ҫ�ͷŵ�λ�á�
//ѭ��������ͷ�����Ҫ�����ͷţ�����ͷָ���ÿա�
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	if (phead == NULL)
	{
		return 0;
	}
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = NULL;
		cur = next;
	}
	free(phead);
	phead = NULL;
}

// ˫�������ӡ 
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d->", cur->_data);
		cur = cur->next;
	}
	printf("\n");
}

// ˫������β�� 
void ListPushBack(ListNode* phead, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = phead->prev;
	
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

// ˫������βɾ 
void ListPopBack(ListNode* phead)
{
	assert(phead);

	//ListNode* tail = phead->prev;
	//ListNode* tailprev = tail->prev;

	//tailprev->next = phead;
	//phead->prev = tailprev;
	//free(tail);
	
	ListNode* tail = phead->prev;
	phead->prev = tail->prev;
	tail->prev->next = phead;
	free(tail);
}



// ˫������ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{
	/*ListNode* newnode = BuyListNode(x);
	ListNode* first = phead->next;

	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;*/

	ListNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;

}

// ˫������ͷɾ 
void ListPopFront(ListNode* phead)
{
	assert(phead);
	//�൱��ɾ��ͷ�������Ԫ��
	ListErase(phead->next);
}

// ˫��������� 
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur->next != phead)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ˫��������pos��ǰ����в��� 
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

// ˫������ɾ��posλ�õĽڵ� 
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
}