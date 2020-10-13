
//#include "seqlist.h"
//#include "slist.h"
//#include "dclist.h"

//#include "stack.h"
#include "queue.h"



//循环队列测试
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
//顺序队列测试
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

	printf("对头元素为：%d\n",SeqQueueFront(&q));
	return 0;
}
#endif

#if 0
//链栈测试
int main()
{
	LinkStack ls;
	LinkStackInit(&ls);

	LinkStackPush(&ls, 1);
	LinkStackPush(&ls, 2);
	LinkStackPush(&ls, 3);
	LinkStackPush(&ls, 4);
	LinkStackPush(&ls, 5);
	printf("栈顶元素为%d\n", LinkStackTop(&ls));
	LinkStackShow(&ls);

	LinkStackPop(&ls);
	printf("栈顶元素为%d\n", LinkStackTop(&ls));
	printf("栈大小为%d\n", LinkStackSize(&ls));
	LinkStackShow(&ls);

	return 0;
}

//顺序栈测试
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
	printf("栈顶元素为：%d\n", SeqStackTop(&st));
	printf("栈大小：%d\n", SeqStackSize(&st));

	SeqStackPop(&st);
	printf("栈顶元素为：%d\n", SeqStackTop(&st));
	SeqStackShow(&st);
	printf("栈大小：%d\n", SeqStackSize(&st));

	SeqStackPop(&st);
	int top_val;
	while (!SeqStackIsEmpty(&st))
	{
		//top_val = SeqStackTop(&st);
		SeqStackTop(&st, &top_val);
		SeqStackPop(&st);
		printf("%d 出栈.\n", top_val);
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
	//顺序表
	//SeqList list;
	//SeqListInit(&list);

	//无头单链表
	//SList slist;
	//SListInit(&slist);
	//SListNode *p = NULL;

	//带头双循环链表
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
		printf("请选择：>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1)
			{
				//SeqListPushBack(&list, item);
				//SListPushBack(&slist, item);
				DCListPushBack(&list, item);
			}
			printf("尾部插入数据成功......\n");
			break;
		case 2:
			printf("请输入要插入的数据<以-1结束>:");
			while (scanf("%d", &item), item != -1)
			{
				//SeqListPushFront(&list, item);
				//SListPushFront(&slist, item);
				DCListPushFront(&list, item);
			}
			printf("头部插入数据成功......\n");
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
			printf("尾部删除数据成功......\n");
			break;
		case 5:
			//SeqListPopFront(&list);
			//SListPopFront(&slist);
			DCListPopFront(&list);
			printf("头部删除数据成功......\n");
			break;
		
		case 6:
			printf("请输入要插入的位置:>");
			scanf("%d", &pos);
			printf("请输入要插入的元素:>");
			scanf("%d", &item);
			//flag = SeqListInsertByPos(&list, pos, item);
			
			if (flag)
				printf("插入数据成功......\n");
			else
				printf("插入数据失败......\n");
			break;
		case 7:
			printf("请输入要插入的元素:>");
			scanf("%d", &item);
			//SeqListSort(&list);
			//SeqListInsertByVal(&list, item);
			DCListInsertByVal(list, item);

			printf("插入数据成功......\n");
			break;
		case 8:
			printf("请输入要删除的位置:>");
			scanf("%d", &pos);
			//SeqListEraseByPos(&list, pos);
			printf("删除数据成功......\n");
			break;
		case 9:
			printf("请输入要删除的元素:>");
			scanf("%d", &item);
			//SeqListEraseByVal(&list, item);
			printf("删除数据成功......\n");
			break;
		case 10:
			printf("请输入要查找的关键之：>");
			scanf("%d", &item);
			//pos = SeqListFind(&list, item);
			//p = SListFind(slist, item);
			//if (pos == -1)
			
			//if (p == NULL)
			//	printf("数据查找失败\n");
			//else
				//printf("数据查找成功，查找关键值的位置为：%d\n", pos);
			//	printf("数据查询成功\n");
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
			printf("顺序表排序成功......\n");
			break;
		case 14:
			//SeqListReverse(&list);
			DCListReverse(list);
			printf("转置完成\n");
			break;

		case 15:
			//SListClear(&slist);
			DCListClear(&list);
			printf("链表清空完成\n");
			break;
		case 16:
			//printf("表头元素为: %d\n", SeqListFront(&list));
			//printf("表头元素为: %d\n", SListFront(slist));
			printf("表头元素为: %d\n", DCListFront(list));

			break;
		case 17:
			//printf("表尾元素为: %d\n", SeqListBack(&list));
			//printf("表尾元素为: %d\n", SListBack(slist));
			printf("表尾元素为: %d\n", DCListBack(list));

			break;
		case 19:
			printf("请输入要删除的元素:>");
			scanf("%d", &item);
			//SeqListEraseAll(&list, item);
			//SeqListShow(&list);
			break;
		default:
			printf("命令出错,请重新输入......\n");
			break;
		}
	}
	return 0;
}

#endif
