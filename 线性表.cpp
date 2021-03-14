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

void InitList(SqList &L) //构造一个空的线性表
{
	L.elem = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
	L.length = 0;
	L.listsize = INIT_SIZE;
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

void MergeList(SqList La, SqList Lb, SqList& Lc)  //非递减有序排列
{
	InitList(Lc);
	int i =1, j = 1,k=0;
	int La_len = Getlen(La);
	int Lb_len = Getlen(Lb);
	while ((i <= La_len) && (j <= Lb_len))
	{
		ElemType a = GetElem(La, i);
		ElemType b = GetElem(Lb, j);
		if (a <= b)
		{
			ListInsert(Lc, ++k, a);
			++i;
		}
		else
		{
			ListInsert(Lc, ++k, b);
			++j;
		}
	}
	while (i <= La_len) {
		ElemType a = GetElem(La, i++);
		ListInsert(Lc, ++k, a);
	}
	while (j <= Lb_len) {
		ElemType b = GetElem(Lb, j++);
		ListInsert(Lc, ++k, b);
	}
}

int main()
{
	SqList a,b,c;
	InitList(a);
	InitList(b);
	for (int i = 0;i < 10;i++)
		a.elem[i] = i;
	for (int i = 0;i <10;i++)
		b.elem[i] = i;
	a.length = b.length = 10;
	MergeList(a, b, c);

	for (int i = 0;i < a.length;i++)
		printf("%d\n", *(a.elem + i));
	printf("aaaaaaaaaaaaaaaaaaaaa\n");
	for (int i = 0;i < b.length;i++)
		printf("%d\n", *(b.elem + i));

	printf("aaaaaaaaaaaaaaaaaaaaa\n");
	for(int i = 0;i < c.length;i++)
		printf("%d\n", *(c.elem + i));

}
