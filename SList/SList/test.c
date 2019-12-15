

#include "SList.h"

void TestSList1()
{
	//尾插法建表
	SListNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	//尾删
	SListPopBack(&plist);
	SListPrint(plist);

	//头插
	SListPushFront(&plist, 5);
	SListPrint(plist);

	//头删
	SListPopFront(&plist);
	SListPrint(plist);

	//查找
	SListFind(plist, 2);
	printf("%p\n", plist);

}

int main()
{
	TestSList1();

	return 0;
}