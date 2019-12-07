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

	//β��
	SeqListPushBack(&s,6);
	SeqListPrint(&s);
	//ͷ��
	SeqListPushFront(&s, 5);
	SeqListPrint(&s);
	//βɾ
	SeqListPopBack(&s);
	SeqListPrint(&s);
	//ͷɾ
	SeqListPopFront(&s);
	SeqListPrint(&s);
	//����
	SeqListFind(&s,13);
	printf("%d\n", SeqListFind(&s, 13));
	//ָ��λ��ɾ��
	SeqListErase(&s,4 );
	SeqListPrint(&s);
	//�޸�ĳ��λ�õ�ֵ
	SeqListModify(&s, 1, 32);
	SeqListPrint(&s);
	//ð������
	SeqListBubbleSort(&s);
	SeqListPrint(&s);
	//���ֲ���
	SeqListBinaryFind(&s, 8);
	printf("%d\n", SeqListBinaryFind(&s, 8));

}

int main()
{
	TestSeqList1();
	return 0;
}