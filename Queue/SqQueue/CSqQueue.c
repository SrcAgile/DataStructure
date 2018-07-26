#include "CSqQueue.h"

CSqQueue * InitCSqQueue(){
	CSqQueue *csqueue = (CSqQueue *)malloc(sizeof(CSqQueue));
	csqueue->front = 0;
	csqueue->rear  = 0;
	return csqueue;
}
void DestoryCSqQueue(CSqQueue *csqueue){
	free(csqueue);
	csqueue = NULL;
}
bool EnCSqQueue(CSqQueue *csqueue,ElemType data){
	if((csqueue->rear+1)%MaxSize==csqueue->front)//这里竟然写错了
		return false;
	csqueue->rear = (csqueue->rear+1)%MaxSize;
	csqueue->datas[csqueue->rear] = data;
	return true;
}
bool DeCSqQueue(CSqQueue *csqueue,ElemType *data){
	if(csqueue->rear == csqueue->front)
		return false;
	*data = csqueue->datas[csqueue->front];
	csqueue->front = (csqueue->front+1)%MaxSize;

	return true;
}
bool IsCSqQueueEmpty(CSqQueue *csqueue){
	if(csqueue->rear == csqueue->front)
		return true;
	return false;
}
