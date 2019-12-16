

#include"DSList.h"

void Test()
{

	ListNode* phead = ListCreate();

	//Œ≤≤Â
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);

	//Œ≤…æ
	ListPopBack(phead);
	ListPrint(phead);

	//Õ∑≤Â
	ListPushFront(phead, 5);
	ListPrint(phead);

	//Õ∑…æ
	ListPopFront(phead);
	ListPrint(phead);

	//≤È’“
	ListFind(phead, 2);
	printf("%p", ListFind(phead, 5));

}
int main()
{
	Test();
	return 0;
}