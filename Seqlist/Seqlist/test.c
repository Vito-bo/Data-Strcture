#include "Seqlist.h"

void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 13);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 27);
	SeqListPushBack(&s, 45);
	SeqListPrint(&s);

	//尾插
	SeqListPushBack(&s,6);
	SeqListPrint(&s);
	//头插
	SeqListPushFront(&s, 5);
	SeqListPrint(&s);
	//尾删
	SeqListPopBack(&s);
	SeqListPrint(&s);
	//头删
	SeqListPopFront(&s);
	SeqListPrint(&s);
	//查找
	SeqListFind(&s,13);
	printf("%d\n", SeqListFind(&s, 13));
	//指定位置删除
	SeqListErase(&s,4 );
	SeqListPrint(&s);
	//修改某个位置的值
	SeqListModify(&s, 1, 32);
	SeqListPrint(&s);
	//冒泡排序
	SeqListBubbleSort(&s);
	SeqListPrint(&s);
	//二分查找
	SeqListBinaryFind(&s, 8);
	printf("%d\n", SeqListBinaryFind(&s, 8));

}

int main()
{
	TestSeqList1();
	return 0;
}