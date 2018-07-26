#include "SqQueue.h"

//设置rear指向队尾元素,front指向队首元素的前一个元素
//为什么不让rear指向队尾元素,front指向队首元素元素?
//大概是判空时存在rear==front但是只具有一个元素时也是rear==front
//自我认为这样保持了操作的简洁性,否则的话EnQQueue还需要对边界条件进行判断,即还需要对第一个结点进行squeue->front++;
SqQueue *InitSqQueue(void){
	SqQueue *squeue = (SqQueue *)malloc(sizeof(SqQueue));
	squeue->front = -1;
	squeue->rear  = -1;
	return squeue;
}
void DestorySqQueue(SqQueue squeue){
	free(squeue);
	squeue = NULL;
}
bool EnSqQueue(SqQueue *squeue,ElemType data){
	if(squeue->rear == MaxSize-1)
		return false;
	squeue->datas[++squeue->rear] = data;
	return true;
}
bool DeSqQueue(SqQueue *squeue,ElemType *data){
	if(squeue->rear==squeue->front)
		return false;//栈空返回错误
	*data = squeue->datas[++squeue->front];
	return true;
}
bool IsSqQueueEmpty(SqQueue *squeue);
	if(squeue->rear == squeue->front)
		return true;
	return false;
i