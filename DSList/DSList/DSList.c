
#include"DSList.h"

//创建一个新结点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

// 创建返回链表的头结点. 
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = head;
	head->prev = head;
	return head;
}

// 双向链表销毁 
//定义一个指向第一个结点的指针，（第一个结点不是头结点），循环遍历，依次释放，并将指针指向下一个要释放的位置。
//循环结束后，头结点需要单独释放，并将头指针置空。
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

// 双向链表打印 
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

// 双向链表尾插 
void ListPushBack(ListNode* phead, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* tail = phead->prev;
	
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

// 双向链表尾删 
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



// 双向链表头插
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

// 双向链表头删 
void ListPopFront(ListNode* phead)
{
	assert(phead);
	//相当于删除头结点后面的元素
	ListErase(phead->next);
}

// 双向链表查找 
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

// 双向链表在pos的前面进行插入 
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

// 双向链表删除pos位置的节点 
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
}