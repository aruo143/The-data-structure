#include<stdio.h>
#include<stdlib.h>

#define MAXQSIZE 100
typedef struct
{
	int* base;
	int front;
	int rear;
}SqQueue;

//构造一个空队列
bool InitQueue(SqQueue& Q)
{
	Q.base = (int*)malloc(MAXQSIZE * sizeof(int));
	if (!Q.base) return false;
	Q.front = Q.rear = 0;
	return true;
}

//队列长度
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

//插入元素e为Q的新的队尾元素
bool EnQueue(SqQueue& Q, int e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front) return false;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return true;
}

//删除队头元素
bool DeQueue(SqQueue& Q, int& e)
{
	if (Q.front == Q.rear) return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return true;
}

int main()
{

}
