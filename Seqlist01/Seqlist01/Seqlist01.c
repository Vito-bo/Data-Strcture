#include"Seqlist01.h"

// 基本增删查改接口 
// 静态顺序表初始化 
void SeqListInit(SeqList* ps)
{
	//使用assert进行断言，使用断言可以创建更稳定
	assert(ps);
	//将顺序表中的数组进行赋值
	memset(ps->arr, 0, sizeof(SLDataType));
	//顺序表中的有效元素初始为0
	ps->size = 0;
}

// 静态顺序表销毁 
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	//销毁只需要将有效个数设置为0
	ps->size = 0;
}

// 静态顺序表打印 
void SeqListPrint(SeqList* ps)
{
	assert(ps);
	SLDataType i = 0;
	//使用for循环依次打印所有有效元素
	for (i = 0; i < ps->size; i++)
	{
		printf("%d->", ps->arr[i]);
	}
	printf("\n");
}

// 静态顺序表尾插 
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	//首先判断插入位置是否合法    
	assert(ps->size < MAX);
	//将数据x插入到末尾
	ps->arr[ps->size] = x;
	ps->size++;
}

// 静态顺序表尾删 
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	//想要删除必须保证数组中至少有一个元素
	assert(ps->size > 0);
	//删除后数组的有效个数减1
	ps->size--;
}

// 静态顺序表头插 
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	//首先判断插入位置是否合法    
	assert(ps->size < MAX);
	SLDataType i = ps->size;
	for (; i>0; i--)
	{
		//头插需将数据元素依次后移一位
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[i] = x;
	ps->size++;
}

// 静态顺序表头删 
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	//想要删除必须保证数组中至少有一个元素
	assert(ps->size > 0);
	for (int i = 1; i < ps->size; i++)
	{
		//将数组中有效数据依次前移一位
		ps->arr[i - 1] = ps->arr[i];
	}
	ps->size--;
}

// 静态顺序表查找
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

// 静态顺序表在pos位置插入x 
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	//首先判断插入位置是否合法    
	assert(ps->size < MAX);
	int i = ps->size;
	//只需将pos后的元素依次后移一位
	for (; i>pos; i--)
	{
		ps->arr[i] = ps->arr[i-1];
	}
	ps->arr[i] = x;
	ps->size++;
}

// 顺序表删除pos位置的值 
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps);
	//数组至少有一个有效数据
	assert(ps->size > 0);
	int i = pos;
    //将pos后的元素依次前移
	for (; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

// 静态顺序表的数据更新
void SeqListUpdata(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps);
	assert(ps->size > pos);
    //指定位置数据更新
	ps->arr[pos] = x;
}

// 静态顺序表的冒泡排序
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

