#include "BTree.h"
#define MaxSize 100

//normal sequece stack
typedef struct {
	BTree data[MaxSize];
	int top;
}BTreeStack;

//circle sequence queue
typedef struct{
	BTree data[MaxSize];
	int front;
	int rear;
}BTreeCSQueue;

BTreeStack   *InitBTreeStack();
BTreeCSQueue *InitBTreeCSQueue();

void PreOrderTraverseNoRec(BTree tree);
void MidOrderTraverseNoRec(BTree tree);
void AftOrderTraverseNoRec(BTree tree);

//traverse tree in the view of layer of tree
void LayOrderTraverseNoRec(BTree tree);