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

void ListInsert(LinkList& L, int i, ElemType e)//在第i个位置插入元素e
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

void ListDelete(LinkList& L, int i, ElemType& e)//删除第i个元素
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

void display(LinkList L)//输出所有的值
{
	LNode* p = L;
	while (p->next != NULL)
	{
		p = p->next;
		printf("%d ", p->data);
	}
}

void InitList(LinkList& L)
{
	LNode* s = new LNode;
	L = s;
	s->next = NULL;
}

int main()
{
	LinkList L;
	InitList(L);
	ListInsert(L, 1, 0);
	ListInsert(L, 2, 1);
	ListInsert(L, 1, 2);
	ListInsert(L, 1, 3);
	display(L);

}
