#include<stdio.h>
#include<stdlib.h>

typedef struct  BiTNode {
	char data;
	struct BiTNode* lchild, * rchild;
}BiTNode,* BiTree;

//创建二叉树
//void CreatBitree1(BiTree& root, char* str) //先序序列对应的字符串
//{
//	char ch = *str;
//	if (ch == ' ')
//		root = NULL;
//	else 
//	{
//		root = new BiTNode;
//		root->data= ch;
//		CreatBitree1(root->lchild, str++);
//		CreatBitree1(root->rchild, str++);
//	}
//}

void CreatBitree2(BiTree& root) //先序序列对应的字符串
{
	char ch;
	scanf_s("%c", &ch);
	if (ch == ' ')
		root = NULL;
	else
	{
		root = new BiTNode;
		root->data = ch;
		CreatBitree2(root->lchild);
		CreatBitree2(root->rchild);
	}
}

//从根开始，按层次遍历二叉树的算法，同层的结点按从左至右的次序访问
void LevelOrder(BiTree T)
{
	BiTree Queue[100];
	int front, rear;
	if (T == NULL) return;
	front = -1;
	rear = 0;
	Queue[rear] = T;
	while (front != rear)
	{
		front++;
		printf("%c", Queue[front]->data);
		if (Queue[front]->lchild != NULL)
		{
			rear++;
			Queue[rear] = Queue[front]->lchild;
		}
		if (Queue[front]->rchild != NULL)
		{
			rear++;
			Queue[rear] = Queue[front]->rchild;
		}

	}

}

int main()
{
	BiTree root;
	CreatBitree2(root);
	LevelOrder(root);
}
