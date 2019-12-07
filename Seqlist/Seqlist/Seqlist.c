#include "Seqlist.h"

//������ɾ��Ľӿ�
//��ʼ��˳���
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->_a = NULL;
	//��ʼ��ʱ��Ч���ݸ���Ϊ0
	ps->_size = 0;
	ps->_capacity = 0;
}

//����˳���
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->_a);
	//free����οռ�֮��_a�ͱ����һ��Ұָ�룬�����ý���ָ��ָ���
	ps->_a = NULL;
	ps->_size = ps->_capacity = 0;
}

//��ӡ����
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		printf("%d->", ps->_a[i]);
	}
	printf("NULL\n");
}

//���ռ��Ƿ���
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	//���ռ䲻��ʱ�ͽ��ռ����䵽ԭ����2��
	if (ps->_size >= ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a=realloc(ps->_a, newcapacity * sizeof(SLDataType));
		//���µĿռ��_a
		ps->_capacity = newcapacity;
	}
}

//β��
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	//�����ݲ����β
	ps->_a[ps->_size] = x;
	//��Ч����Ԫ�ؼ�1
	ps->_size++;
}

//βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps && ps->_size>0);
	//ps->_a[ps->_size - 1] = 0;
	ps->_size--;
}

//ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	//�ȿ��ǿռ䲻������
	SeqListCheckCapacity(ps);
	//�ƶ�����
	int end = ps->_size - 1;
	for (; end >= 0; end--)
	{
		//����ǰ�������κ���
		ps->_a[end + 1] = ps->_a[end];
	}
	//���µ�һ���ռ����ͷ��
	ps->_a[0] = x;
	ps->_size++;

}

//ͷɾ
void SeqListPopFront(SeqList* ps)
{
	assert(ps && ps->_size>0);
	
	for (size_t i = 1; i < ps->_size - 1; ++i)
	{
		ps->_a[i - 1] = ps->_a[i];
	}
	ps->_size--;
}

//����
int SeqListFind(SeqList* ps, SLDataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		if (ps->_a[i] == x)
		{
			return i;
		}
	}
	return -1;
}


//�м�ĳ������
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps && pos< ps->_size);
	/*SeqListCheckCapacity(ps);

	int end = ps->_size;
	while (end >= (int)pos)
	{
		ps->_a[end + 1] = ps->_a[end];
		--end;
	}*/

	size_t end = ps->_size+1;
	while (end > pos)
	{
		//��ָ��λ��֮���Ԫ�����κ���һ����λ������posλ��
		ps->_a[end] = ps->_a[end-1];
		--end;
	}
	//ָ��λ�ò�������
	ps->_a[pos] = x;
	ps->_size++;

}

//ָ��λ��ɾ��
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps && pos < ps->_size);

	size_t i = pos + 1;
	while (i<ps->_size)
	{
		//posλ�ú����������ǰ��һ����Ԫ
		ps->_a[i-1] = ps->_a[i];
		++i;
	}
	ps->_size--;
}

//ָ��Ԫ��ɾ��
void SeqListRemove(SeqList* ps, SLDataType x)
{
	assert(ps);
	int pos = SeqListFind(ps, x);
	if (pos >= 0)
	{
		SeqListErase(ps, pos);
	}
}

//�޸�ĳ��λ�õ�ֵ
void SeqListModify(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps && (pos > 0 && pos < ps->_size));
	ps->_a[pos - 1] = x;
}

// ��չ������ʵ��

//ð������
void SeqListBubbleSort(SeqList* ps)
{
	assert(ps);

	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < ps->_size - 1; i++)
	{
		for (j = 0; j < ps->_size - i - 1; j++)
		{
			if (ps->_a[j]>ps->_a[j + 1])
			{
				SLDataType tmp = ps->_a[j];
				ps->_a[j] = ps->_a[j + 1];
				ps->_a[j + 1] = tmp;
			}
		}
	}
}

//���ֲ���
int SeqListBinaryFind(SeqList* ps, SLDataType x)
{
	assert(ps);

	int left = 0;
	int right = (int)ps->_size;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (ps->_a[mid] == x)
		{
			return mid + 1;
		}
		else if (ps->_a[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return -1;
}

// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
void SeqListRemoveAll(SeqList* ps, SLDataType x)
{
	assert(ps);
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < ps->_size; i++)
	{
		if (ps->_a[i] != x)
		{
			ps->_a[j] = ps->_a[i];
			j++;
		}
	}
	ps->_size = j;
}