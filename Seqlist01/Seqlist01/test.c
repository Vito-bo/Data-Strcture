#include"Seqlist01.h"

void TestSeqlist01()
{
	SeqList L;
	SeqListInit(&L);
	//β��
	SeqListPushBack(&L, 6);
	SeqListPushBack(&L, 13);
	SeqListPushBack(&L, 8);
	SeqListPushBack(&L, 27);
	SeqListPushBack(&L, 45);
	SeqListPrint(&L);
	//βɾ 
	SeqListPopBack(&L);
	SeqListPrint(&L);
	// ͷ�� 
	SeqListPushFront(&L, 5);
	SeqListPrint(&L);
	// ͷɾ 
	SeqListPopFront(&L);
	SeqListPrint(&L);
	// ����
	SeqListFind(&L, 8);
	printf("%d\n", SeqListFind(&L, 8));
	// ��posλ�ò���x 
	SeqListInsert(&L, 2, 66);
	SeqListPrint(&L);
	// ɾ��posλ�õ�ֵ 
	SeqListErase(&L, 2);
	SeqListPrint(&L);
	// ���ݸ���
	SeqListUpdata(&L, 2, 66);
	SeqListPrint(&L);
	// ð������
	SeqListBubbleSort(&L);
	SeqListPrint(&L);

}


int main()
{
	TestSeqlist01();
	return 0;
}