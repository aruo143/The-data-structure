//就比单链表多了一个尾指针
//含头节点和尾结点
#include<stdio.h>
#include<stdlib.h>

typedef struct QNode {
	int data;
	struct QNode* next;
}QNode,*QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//构造一个空队列
bool InitQueue(LinkQueue& Q) 
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) return false;
	Q.front->next=NULL;
	return true;
}

//插入元素
bool EnQueue(LinkQueue& Q, int e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p) return false;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return true;
}

//销毁队列
bool DEstroyQueue(LinkQueue& Q)
{
	while (Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front= Q.rear;
	}
	return true;
}

//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；
bool DEqueue(LinkQueue& Q, int& e)
{
	if (Q.front == Q.rear) return false;
	QueuePtr p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;  //
    free(p);
	return true;
}


int main()
{

}
