#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

bool GetElem(LinkList L, int i, ElemType& e) //查找第i个元素，并赋值给e
{
	LNode* p = L->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return false;
	e = p->data;
	return true;
}

void ListInsert(LinkList& L, int i, ElemType e)
{
	LNode* p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return;
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
}

void ListDelete(LinkList& L, int i, ElemType& e)
{
	LNode* p = L;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i - 1) return;
	LNode* q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
}

int main()
{

}
