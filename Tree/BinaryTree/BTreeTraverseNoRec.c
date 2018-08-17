#include "BTreeTraverseNoRec.h"

BTreeStack   *InitBTreeStack(){
	BTreeStack *stack = (BTreeStack *)malloc(sizeof(BTreeStack));
	stack->top = -1;
	return stack;
}
BTreeCSQueue *InitBTreeCSQueue(){
	BTreeCSQueue *queue = (BTreeCSQueue *)malloc(sizeof(BTreeCSQueue));
	queue->rear = 0;
	queue->front = 0;
	return queue;
}

void PreOrderTraverseNoRec(BTree tree){
	if(tree == NULL)
		return ;
	BTreeStack *stack = InitBTreeStack();
	stack->data[stack->top] = tree;
	while(stack->top != -1){
		BTree topNode = stack->data[stack->top--];
		printf("%c",topNode->data);
		if(topNode->right != NULL)
			stack->data[++stack->top]=topNode->right;
		if(topNode->left  != NULL)
			stack->data[++stack->top]=topNode->left;
	}
}
void MidOrderTraverseNoRec(BTree tree){
	if(tree == NULL)
		return ;

	BTreeStack *stack = InitBTreeStack();
	stack->data[++stack->top]=tree;
	BTree topNode = stack->data[stack->top];
	while(stack->top != -1){
		while(topNode != NULL && topNode->left != NULL){
			stack->data[++stack->top]=topNode->left;
			topNode = topNode->left;
		}
		topNode = stack->data[stack->top--];
		printf("%c",topNode->data);
		if(topNode->right != NULL){
			stack->data[++stack->top]=topNode->right;
			topNode = topNode->right;
		}else
			topNode = NULL;
	}
}
void AftOrderTraverseNoRec(BTree tree){
	if(tree == NULL)
		return ;
	BTreeStack *stack = InitBTreeStack();
	stack->data[++stack->top]=tree;
	BTree topNode = stack->data[stack->top];
	BTree temp = NULL;
	while(stack->top != -1){
		while(topNode != NULL && topNode->left != NULL){
			stack->data[++stack->top]=topNode->left;
			topNode = topNode->left;
		}
		topNode = stack->data[stack->top];
		//如果上次没有访问了右子树并且右子树不为空才进行插入
		if(temp != topNode->right && topNode->right!= NULL){
			stack->data[++stack->top]=topNode->right;
			topNode = topNode->right;
		}else{//回溯
			printf("%c",topNode->data);
			stack->top--;
			temp = topNode;
			topNode = NULL;
		}
	}
}

void LayOrderTraverseNoRec(BTree tree){
	BTreeCSQueue *queue = InitBTreeCSQueue();
	queue->rear = (queue->rear + 1)%MaxSize;
	queue->data[queue->rear] = tree;
	while(queue->front != queue->rear){
		queue->front = (queue->front+1)%MaxSize;
		BTree topNode = queue->data[queue->front];
		printf("%c",topNode->data);
		if(topNode->left != NULL){
			queue->rear = (queue->rear + 1) % MaxSize;
			queue->data[queue->rear] = topNode->left;
		}
		if(topNode->right != NULL){
			queue->rear = (queue->rear + 1) % MaxSize;
			queue->data[queue->rear] = topNode->right;
		}
	}
}