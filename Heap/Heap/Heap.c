

#include"Heap.h"



//数据交换
void Swap(HPDataType* x1,HPDataType* x2)
{
	HPDataType x = *x1;
	*x1 = *x2;
	*x2 = x;
}

/*
//构建小堆——>root的左右子树都必须是小堆
//向下调整
void AdjustDwon(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//选出小的那个孩子
		if (child+1 <n && a[child + 1] < a[child])
			++child;
		if (a[child] < a[parent])
		{
			Swap(&a[child],&a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//向上调整
void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
*/

//构建大堆——>root的左右子树都必须是小堆
//向下调整
void AdjustDwon(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//选出小的那个孩子
		if (child + 1 <n && a[child + 1] > a[child])
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
//向上调整
void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//打印堆
void HeapPrint(Heap* hp)
{
	for (size_t i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

// 堆的构建 
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;


	//构建堆的算法
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(hp->_a, hp->_size, i);
	}

}

// 堆的销毁 
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

// 堆的插入 
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a,sizeof(HPDataType) * hp->_capacity);  
	}

	hp->_a[hp->_size] = x;
	hp->_size++;

	//向上调整
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);
}

// 堆的删除 
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size-1]);
	--hp->_size;
	AdjustDwon(hp->_a, hp->_size, 0);

}

// 取堆顶的数据 
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

// 堆的数据个数 
int HeapSize(Heap* hp)
{
	return hp->_size;
}

// 堆的判空 
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}






