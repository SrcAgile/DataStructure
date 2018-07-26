#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int ElemType;
typedef struct LQNode
{
	ElemType data;
	struct LQNode *next;
}LQNode;

typedef struct
{
	LQNode *rear;
	LQNode *front;
} ListQueue;

ListQueue * InitListQueue();
LQNode    * InitLQNode();
void DestoryListQueue(ListQueue *listqueue);
bool EnListQueue(ListQueue *listqueue,ElemType data);
bool DeListQueue(ListQueue *listqueue,ElemType *data);
bool IsListQueueEmpty(ListQueue *listqueue);