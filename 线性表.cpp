#include<stdio.h>
#include<stdlib.h>
#define INIT_SIZE 100
#define LISTINCREMENT 10

//typedef struct
//{
//	char* xuehao;
//	int num;
//	char* name;
//}ElemType;

typedef int ElemType;

typedef struct
{
	ElemType* elem;
	int length;
	int listsize;
}SqList;

void InitList(SqList* L) //构造一个空的线性表
{
	L->elem = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
	L->length = 0;
	L->listsize = INIT_SIZE;
}

int Getlen(SqList L) //求表L的长度
{
	return L.length;
}

bool ListInsert(SqList& L, int i, ElemType e)  //插入元素
{
	if (i<1 || i>L.length + 1) return false;
	if (L.length > L.listsize)
	{
		ElemType* newbase = (ElemType*)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	ElemType*  q = &(L.elem[i - 1]);
	for (ElemType* p = &(L.elem[L.length - 1]);p >= q;--p)
		*(p + 1) = *p;
	*q = e;
	++L.length;
	return true;
}

bool ListDelete(SqList &L,int i,ElemType &e)  //删除元素
{
	if (i<1 || i>L.length) return false;
	ElemType* p = &(L.elem[i - 1]);
	e = *p;
	ElemType* q = L.elem + L.length - 1;
	for (++p;p <= q;++p)
		*(p - 1) = *p;
	--L.length;
	return true;
}

void DestroyList(SqList *&L)  //销毁顺序表     //SqList *&L  指针变量的引用
{
	free(L);
}

void ClearList(SqList& L)  //清空顺序表
{
	L.length = 0;
}

ElemType GetElem(SqList L, int i)   //按序号取元素
{
	return L.elem[i-1];
}

int Locate(SqList L, ElemType x)  //按值查找
{
	for (int i = 0;i < L.length;i++)
	{
		if (L.elem[i] == x) return i;
		else return 0;
	}
}

void GetElem(SqList L, int i, ElemType& e)  //用e返回第i个结点的值
{
	e = L.elem[i - 1];
}

int main()
{
	SqList a;
	ElemType e =0 ;
	InitList(&a);
	for (int i = 0;i < 10;i++) a.elem[i] = i;
	a.length = 10;
	ListInsert(a, 1, 1);
	for(int i=0;i<a.length;i++)
	    printf("%d\n", *(a.elem+i));

	ListDelete(a, 2, e);
	printf("删除的元素是%d\n", e);

	for (int i = 0;i < a.length;i++)
		printf("%d\n", *(a.elem + i));

}
