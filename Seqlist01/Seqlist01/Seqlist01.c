#include"Seqlist01.h"

// ������ɾ��Ľӿ� 
// ��̬˳����ʼ�� 
void SeqListInit(SeqList* ps)
{
	//ʹ��assert���ж��ԣ�ʹ�ö��Կ��Դ������ȶ�
	assert(ps);
	//��˳����е�������и�ֵ
	memset(ps->arr, 0, sizeof(SLDataType));
	//˳����е���ЧԪ�س�ʼΪ0
	ps->size = 0;
}

// ��̬˳������� 
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	//����ֻ��Ҫ����Ч��������Ϊ0
	ps->size = 0;
}

// ��̬˳����ӡ 
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	SLDataType i = 0;
	//ʹ��forѭ�����δ�ӡ������ЧԪ��
	for (i = 0; i < ps->size; i++)
	{
		printf("%d->", ps->arr[i]);
	}
	printf("\n");
}

// ��̬˳���β�� 
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	//�����жϲ���λ���Ƿ�Ϸ�    
	assert(ps->size < MAX);
	//������x���뵽ĩβ
	ps->arr[ps->size] = x;
	ps->size++;
}

// ��̬˳���βɾ 
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	//��Ҫɾ�����뱣֤������������һ��Ԫ��
	assert(ps->size > 0);
	//ɾ�����������Ч������1
	ps->size--;
}

// ��̬˳���ͷ�� 
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	//�����жϲ���λ���Ƿ�Ϸ�    
	assert(ps->size < MAX);
	SLDataType i = ps->size;
	for (; i>0; i--)
	{
		//ͷ���轫����Ԫ�����κ���һλ
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[i] = x;
	ps->size++;
}

// ��̬˳���ͷɾ 
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	//��Ҫɾ�����뱣֤������������һ��Ԫ��
	assert(ps->size > 0);
	for (int i = 1; i < ps->size; i++)
	{
		//����������Ч��������ǰ��һλ
		ps->arr[i - 1] = ps->arr[i];
	}
	ps->size--;
}

// ��̬˳������
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i+1;
		}
	}
	return -1;
}

// ��̬˳�����posλ�ò���x 
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	//�����жϲ���λ���Ƿ�Ϸ�    
	assert(ps->size < MAX);
	int i = ps->size;
	//ֻ�轫pos���Ԫ�����κ���һλ
	for (; i>pos; i--)
	{
		ps->arr[i] = ps->arr[i-1];
	}
	ps->arr[i] = x;
	ps->size++;
}

// ˳���ɾ��posλ�õ�ֵ 
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	//����������һ����Ч����
	assert(ps->size > 0);
	int i = pos;
    //��pos���Ԫ������ǰ��
	for (; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

// ��̬˳�������ݸ���
void SeqListUpdata(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	assert(ps->size > pos);
    //ָ��λ�����ݸ���
	ps->arr[pos] = x;
}

// ��̬˳����ð������
void SeqListBubbleSort(SeqList *ps)
{
	assert(ps);
	assert(ps->size > 0);
	int i, j, flag;
	for (i = 0; i < ps->size - 1; i++)
	{
		for (j = 0; j < ps->size - i - 1; j++)
		{
			if (ps->arr[j]>ps->arr[j + 1])
			{
				SLDataType tmp = ps->arr[j];
				ps->arr[j] = ps->arr[j + 1];
				ps->arr[j + 1] = tmp;
				flag = 1;
			}
		}
		flag = 0;
	}
}

