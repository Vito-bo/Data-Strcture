#include"Seqlist01.h"

void TestSeqlist01()
{
	SeqList L;
	SeqListInit(&L);
	//尾插
	SeqListPushBack(&L, 6);
	SeqListPushBack(&L, 13);
	SeqListPushBack(&L, 8);
	SeqListPushBack(&L, 27);
	SeqListPushBack(&L, 45);
	SeqListPrint(&L);
	//尾删 
	SeqListPopBack(&L);
	SeqListPrint(&L);
	// 头插 
	SeqListPushFront(&L, 5);
	SeqListPrint(&L);
	// 头删 
	SeqListPopFront(&L);
	SeqListPrint(&L);
	// 查找
	SeqListFind(&L, 8);
	printf("%d\n", SeqListFind(&L, 8));
	// 在pos位置插入x 
	SeqListInsert(&L, 2, 66);
	SeqListPrint(&L);
	// 删除pos位置的值 
	SeqListErase(&L, 2);
	SeqListPrint(&L);
	// 数据更新
	SeqListUpdata(&L, 2, 66);
	SeqListPrint(&L);
	// 冒泡排序
	SeqListBubbleSort(&L);
	SeqListPrint(&L);

}


int main()
{
	TestSeqlist01();
	return 0;
}