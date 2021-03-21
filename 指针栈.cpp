#include<stdio.h>
#include<stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int SElemType;

typedef struct
{
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;


bool InitStack(SqStack& S) 
{
	S.base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base) return false;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return true;
}

bool Push(SqStack& S, SElemType& e)  //插入元素
{
	if (S.top - S.base >= S.stacksize)
	{
		S.base = (SElemType*)realloc(S.base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(SElemType));
        if (!S.base) return false;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return true;
}

SElemType GetTop(SqStack S)
{
	if (S.top == S.base) return 0;
	return *(S.top-1);
}

bool Pop(SqStack& S, SElemType& e)
{
	if (S.top == S.base) return false;
	e = *--S.top;
	return true;
}
	


int main()
{
	SqStack a;
	SElemType e = 12,q;
	InitStack(a);
	Push(a, e);
	Push(a, ++e);
	Push(a, ++e);
	Push(a, ++e);
	Pop(a, q);
	printf("删除了%d", q);
}
