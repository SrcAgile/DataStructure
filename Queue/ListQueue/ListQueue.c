#include "ListQueue.h"
ListQueue * InitListQueue(){
	ListQueue *listqueue = (ListQueue *)malloc(sizeof(ListQueue));//加头结点操作方便没必要专门为边界结点写代码
	listqueue->rear = NULL;
	listqueue->front = NULL;
	return listqueue;
};
LQNode    * InitLQNode(){
	LQNode *node = (LQNode *)malloc(sizeof(LQNode));
	node->next = NULL;
	return node;
}
void DestoryListQueue(ListQueue *listqueue){
	ElemType data;
	while(!IsListQueueEmpty(listqueue))
		DeListQueue(listqueue,&data);
}
bool EnListQueue(ListQueue *listqueue,ElemType data){
	//无判满条件
	LQNode *new = InitLQNode();
	new->data = data;
	if(listqueue->front==NULL){
		listqueue->front=new;
		listqueue->rear = new;
	}else{
		list->rear->next = new;
	}
	return true;
}
bool DeListQueue(ListQueue *listqueue,ElemType *data){
	if(IsListQueueEmpty(listqueue))
		return false;
	LQNode *wait = listqueue->front;
	*data = wait->data;
	listqueue->front = listqueue->front->next;
	return true;
}
bool IsListQueueEmpty(ListQueue *listqueue){
	if(listqueue->rear == listqueue->front)
		return true;
	return false;
}