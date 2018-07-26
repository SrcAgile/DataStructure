#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define MaxSize 100

typedef int ElemType;

typedef struct 
{
	ElemType datas[MaxSize];
	int rear,front;
}SqQueue;

SqQueue *InitSqQueue(void);
void DestorySqQueue(SqQueue);
bool EnSqQueue(SqQueue *squeue,ElemType data);
bool DeSqQueue(SqQueue *squeue,ElemType *data);
bool IsSqQueueEmpty(SqQueue *squeue);