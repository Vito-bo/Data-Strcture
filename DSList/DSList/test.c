

#include"DSList.h"

void Test()
{

	ListNode* phead = ListCreate();

	//β��
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);

	//βɾ
	ListPopBack(phead);
	ListPrint(phead);

	//ͷ��
	ListPushFront(phead, 5);
	ListPrint(phead);

	//ͷɾ
	ListPopFront(phead);
	ListPrint(phead);

	//����
	ListFind(phead, 2);
	printf("%p", ListFind(phead, 5));

}
int main()
{
	Test();
	return 0;
}