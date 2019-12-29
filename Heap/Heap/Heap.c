

#include"Heap.h"



//���ݽ���
void Swap(HPDataType* x1,HPDataType* x2)
{
	HPDataType x = *x1;
	*x1 = *x2;
	*x2 = x;
}

/*
//����С�ѡ���>root������������������С��
//���µ���
void AdjustDwon(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//ѡ��С���Ǹ�����
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

//���ϵ���
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

//������ѡ���>root������������������С��
//���µ���
void AdjustDwon(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < n)
	{
		//ѡ��С���Ǹ�����
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
//���ϵ���
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

//��ӡ��
void HeapPrint(Heap* hp)
{
	for (size_t i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

// �ѵĹ��� 
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;


	//�����ѵ��㷨
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(hp->_a, hp->_size, i);
	}

}

// �ѵ����� 
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}

// �ѵĲ��� 
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a,sizeof(HPDataType) * hp->_capacity);  
	}

	hp->_a[hp->_size] = x;
	hp->_size++;

	//���ϵ���
	AdjustUp(hp->_a, hp->_size, hp->_size - 1);
}

// �ѵ�ɾ�� 
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size-1]);
	--hp->_size;
	AdjustDwon(hp->_a, hp->_size, 0);

}

// ȡ�Ѷ������� 
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

// �ѵ����ݸ��� 
int HeapSize(Heap* hp)
{
	return hp->_size;
}

// �ѵ��п� 
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}






