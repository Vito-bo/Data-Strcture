#include "Seqlist.h"

//基本增删查改接口
//初始化顺序表
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->_a = NULL;
	//初始化时有效数据个数为0
	ps->_size = 0;
	ps->_capacity = 0;
}

//销毁顺序表
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->_a);
	//free掉这段空间之后_a就变成了一个野指针，因此最好将该指针指向空
	ps->_a = NULL;
	ps->_size = ps->_capacity = 0;
}

//打印数据
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; ++i)
	{
		printf("%d->", ps->_a[i]);
	}
	printf("NULL\n");
}

//检查空间是否够用
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	//当空间不足时就将空间扩充到原来的2倍
	if (ps->_size >= ps->_capacity)
	{
		size_t newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a=realloc(ps->_a, newcapacity * sizeof(SLDataType));
		//将新的空间给_a
		ps->_capacity = newcapacity;
	}
}

//尾插
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	//将数据插入表尾
	ps->_a[ps->_size] = x;
	//有效数据元素加1
	ps->_size++;
}

//尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps && ps->_size>0);
	//ps->_a[ps->_size - 1] = 0;
	ps->_size--;
}

//头插
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	//先考虑空间不足问题
	SeqListCheckCapacity(ps);
	//移动数据
	int end = ps->_size - 1;
	for (; end >= 0; end--)
	{
		//将当前数据依次后移
		ps->_a[end + 1] = ps->_a[end];
	}
	//留下第一个空间进行头插
	ps->_a[0] = x;
	ps->_size++;

}

//头删
void SeqListPopFront(SeqList* ps)
{
	assert(ps && ps->_size>0);
	
	for (size_t i = 1; i < ps->_size - 1; ++i)
	{
		ps->_a[i - 1] = ps->_a[i];
	}
	ps->_size--;
}

//查找
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


//中间某处插入
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
		//将指定位置之后的元素依次后移一个单位，留出pos位置
		ps->_a[end] = ps->_a[end-1];
		--end;
	}
	//指定位置插入数据
	ps->_a[pos] = x;
	ps->_size++;

}

//指定位置删除
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps && pos < ps->_size);

	size_t i = pos + 1;
	while (i<ps->_size)
	{
		//pos位置后的数据依次前移一个单元
		ps->_a[i-1] = ps->_a[i];
		++i;
	}
	ps->_size--;
}

//指定元素删除
void SeqListRemove(SeqList* ps, SLDataType x)
{
	assert(ps);
	int pos = SeqListFind(ps, x);
	if (pos >= 0)
	{
		SeqListErase(ps, pos);
	}
}

//修改某个位置的值
void SeqListModify(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps && (pos > 0 && pos < ps->_size));
	ps->_a[pos - 1] = x;
}

// 扩展面试题实现

//冒泡排序
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

//二分查找
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

// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
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