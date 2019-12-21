

#include"Stack.h"


void TestStack()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	while (StackEmpty(&st) == 0)
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	printf("\n");
}

int main()
{
	TestStack();

	return 0;
}