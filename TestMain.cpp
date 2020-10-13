
//#include "seqlist.h"
//#include "slist.h"
//#include "dclist.h"

//#include "stack.h"
#include "queue.h"



//ѭ�����в���
int main()
{
	CycleSeqQueue q;
	CycleSeqQueueInit(&q);

	CycleSeqQueueEn(&q, 1);
	CycleSeqQueueEn(&q, 2);
	CycleSeqQueueEn(&q, 3);
	CycleSeqQueueEn(&q, 4);
	CycleSeqQueueEn(&q, 5);
	CycleSeqQueueShow(&q);

	CycleSeqQueueDe(&q);
	CycleSeqQueueShow(&q);

	CycleSeqQueueEn(&q, 6);
	CycleSeqQueueShow(&q);

	Cycle
	return 0;
}


#if 0
//˳����в���
int main()
{
	SeqQueue q;
	SeqQueueInit(&q);

	SeqQueueEn(&q, 1);
	SeqQueueEn(&q, 2);
	SeqQueueEn(&q, 3);
	SeqQueueEn(&q, 4);
	SeqQueueEn(&q, 5);
	SeqQueueShow(&q);

	SeqQueueDe(&q);
	SeqQueueShow(&q);

	SeqQueueEn(&q, 6);
	SeqQueueShow(&q);

	printf("��ͷԪ��Ϊ��%d\n",SeqQueueFront(&q));
	return 0;
}
#endif

#if 0
//��ջ����
int main()
{
	LinkStack ls;
	LinkStackInit(&ls);

	LinkStackPush(&ls, 1);
	LinkStackPush(&ls, 2);
	LinkStackPush(&ls, 3);
	LinkStackPush(&ls, 4);
	LinkStackPush(&ls, 5);
	printf("ջ��Ԫ��Ϊ%d\n", LinkStackTop(&ls));
	LinkStackShow(&ls);

	LinkStackPop(&ls);
	printf("ջ��Ԫ��Ϊ%d\n", LinkStackTop(&ls));
	printf("ջ��СΪ%d\n", LinkStackSize(&ls));
	LinkStackShow(&ls);

	return 0;
}

//˳��ջ����
int main()
{
	SeqStack st;
	SeqStackInit(&st);

	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);
	SeqStackPush(&st, 3);
	SeqStackPush(&st, 4);
	SeqStackPush(&st, 5);
	SeqStackShow(&st);
	printf("ջ��Ԫ��Ϊ��%d\n", SeqStackTop(&st));
	printf("ջ��С��%d\n", SeqStackSize(&st));

	SeqStackPop(&st);
	printf("ջ��Ԫ��Ϊ��%d\n", SeqStackTop(&st));
	SeqStackShow(&st);
	printf("ջ��С��%d\n", SeqStackSize(&st));

	SeqStackPop(&st);
	int top_val;
	while (!SeqStackIsEmpty(&st))
	{
		//top_val = SeqStackTop(&st);
		SeqStackTop(&st, &top_val);
		SeqStackPop(&st);
		printf("%d ��ջ.\n", top_val);
	}
	SeqStackShow(&st);

	SeqStackDestroy(&st);
	SeqStackShow(&st);

	return 0;
}
#endif


#if 0
int main()
{
	//˳���
	//SeqList list;
	//SeqListInit(&list);

	//��ͷ������
	//SList slist;
	//SListInit(&slist);
	//SListNode *p = NULL;

	//��ͷ˫ѭ������
	DCList list;
	DCListInit(&list);



	ElemType item;
	int pos;
	bool flag;
	int select = 1;
	while (select)
	{
		printf("******************************************\n");
		printf("*** [0] quit_system     [1] push_back  ***\n");
		printf("*** [2] push_front      [3] show_list  ***\n");
		printf("*** [4] pop_back        [5] pop_front  ***\n");
		printf("*** [6] insert_pos      [7] insert_val ***\n");
		printf("*** [8] erase_pos       [9] erase_val  ***\n");
		printf("*** [10] find           [11] length    ***\n");
		printf("*** [12] capacity       [13] sort      ***\n");
		printf("*** [14] reverse        [15] clear     ***\n");
		printf("*** [16] front          [17] back      ***\n");
		printf("*** [18] binary_find    [19] erase_all ***\n");
		printf("******************************************\n");
		printf("��ѡ��>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("������Ҫ���������<��-1����>:");
			while (scanf("%d", &item), item != -1)
			{
				//SeqListPushBack(&list, item);
				//SListPushBack(&slist, item);
				DCListPushBack(&list, item);
			}
			printf("β���������ݳɹ�......\n");
			break;
		case 2:
			printf("������Ҫ���������<��-1����>:");
			while (scanf("%d", &item), item != -1)
			{
				//SeqListPushFront(&list, item);
				//SListPushFront(&slist, item);
				DCListPushFront(&list, item);
			}
			printf("ͷ���������ݳɹ�......\n");
			break;
		case 3:
			//SeqListShow(&list);
			//SListShow(slist);
			DCListShow(list);
			break;
		case 4:
			//SeqListPopBack(&list);
			//SListPopBack(&slist);
			DCListPopBack(&list);
			printf("β��ɾ�����ݳɹ�......\n");
			break;
		case 5:
			//SeqListPopFront(&list);
			//SListPopFront(&slist);
			DCListPopFront(&list);
			printf("ͷ��ɾ�����ݳɹ�......\n");
			break;
		
		case 6:
			printf("������Ҫ�����λ��:>");
			scanf("%d", &pos);
			printf("������Ҫ�����Ԫ��:>");
			scanf("%d", &item);
			//flag = SeqListInsertByPos(&list, pos, item);
			
			if (flag)
				printf("�������ݳɹ�......\n");
			else
				printf("��������ʧ��......\n");
			break;
		case 7:
			printf("������Ҫ�����Ԫ��:>");
			scanf("%d", &item);
			//SeqListSort(&list);
			//SeqListInsertByVal(&list, item);
			DCListInsertByVal(list, item);

			printf("�������ݳɹ�......\n");
			break;
		case 8:
			printf("������Ҫɾ����λ��:>");
			scanf("%d", &pos);
			//SeqListEraseByPos(&list, pos);
			printf("ɾ�����ݳɹ�......\n");
			break;
		case 9:
			printf("������Ҫɾ����Ԫ��:>");
			scanf("%d", &item);
			//SeqListEraseByVal(&list, item);
			printf("ɾ�����ݳɹ�......\n");
			break;
		case 10:
			printf("������Ҫ���ҵĹؼ�֮��>");
			scanf("%d", &item);
			//pos = SeqListFind(&list, item);
			//p = SListFind(slist, item);
			//if (pos == -1)
			
			//if (p == NULL)
			//	printf("���ݲ���ʧ��\n");
			//else
				//printf("���ݲ��ҳɹ������ҹؼ�ֵ��λ��Ϊ��%d\n", pos);
			//	printf("���ݲ�ѯ�ɹ�\n");
			break;
		case 11:
			//printf("SeqList Length=%d\n", SeqListLength(&list));
			//printf("SList Length=%d\n", SListLength(slist));
			printf("SList Length=%d\n", DCListLength(list));


			break;
		case 12:
			//printf("SeqList Capacity=%d\n", SeqListCapacity(&list));
			break;
		case 13:
			//SeqListSort(&list);
			DCListSort(list);
			printf("˳�������ɹ�......\n");
			break;
		case 14:
			//SeqListReverse(&list);
			DCListReverse(list);
			printf("ת�����\n");
			break;

		case 15:
			//SListClear(&slist);
			DCListClear(&list);
			printf("����������\n");
			break;
		case 16:
			//printf("��ͷԪ��Ϊ: %d\n", SeqListFront(&list));
			//printf("��ͷԪ��Ϊ: %d\n", SListFront(slist));
			printf("��ͷԪ��Ϊ: %d\n", DCListFront(list));

			break;
		case 17:
			//printf("��βԪ��Ϊ: %d\n", SeqListBack(&list));
			//printf("��βԪ��Ϊ: %d\n", SListBack(slist));
			printf("��βԪ��Ϊ: %d\n", DCListBack(list));

			break;
		case 19:
			printf("������Ҫɾ����Ԫ��:>");
			scanf("%d", &item);
			//SeqListEraseAll(&list, item);
			//SeqListShow(&list);
			break;
		default:
			printf("�������,����������......\n");
			break;
		}
	}
	return 0;
}

#endif
