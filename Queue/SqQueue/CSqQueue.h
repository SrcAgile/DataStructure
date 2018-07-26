#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define MaxSize 100

typedef ElemType int;
typedef struct  
{
	ElemType datas[MaxSize];
	int rear,front;
}CSqQueue;

CSqQueue * InitCSqQueue();
void DestoryCSqQueue(CSqQueue *csqueue);
bool EnCSqQueue(CSqQueue *csqueue,ElemType data);
bool DeCSqQueue(CSqQueue *csqueue,ElemType *data);
bool IsCSqQueueEmpty(CSqQueue *csqueue);