

#include "SList.h"

void TestSList1()
{
	//β�巨����
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	//βɾ
	SListPopBack(&plist);
	SListPrint(plist);

	//ͷ��
	SListPushFront(&plist, 5);
	SListPrint(plist);

	//ͷɾ
	SListPopFront(&plist);
	SListPrint(plist);

	//����
	SListFind(plist, 2);
	printf("%p\n", plist);

}

int main()
{
	TestSList1();

	return 0;
}