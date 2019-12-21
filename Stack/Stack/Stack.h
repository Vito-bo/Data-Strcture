


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

// ��̬������ջ 
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;       // ջ��    
	int _capacity;  // ���� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_top = ps->_capacity = 0;
}

// ��ջ 
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		ps->_a = (STDataType*)realloc(ps->_a, newcapacity*sizeof(STDataType));
		ps->_capacity = newcapacity;
	}

	ps->_a[ps->_top] = x;
	ps->_top++;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps&&ps->_top>0);
	--ps->_top;
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ���1�������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}

