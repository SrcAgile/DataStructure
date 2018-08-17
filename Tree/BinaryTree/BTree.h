#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100

typedef char ElemType;

typedef struct BNode{
	ElemType data;
	struct BNode *left;
	struct BNode *right;
}*BTree;

BTree InitBNode();
BTree CreateBTree();
BTree FindNodeInBTree(BTree tree,ElemType data);
BTree LocationLeftChildNode(BTree tree);
BTree LocationRightChildNode(BTree tree);
int   BTreeHeight(BTree tree);
void  PrintBTree(BTree tree);