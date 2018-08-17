#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "BTree.h"

typedef struct TBNode
{
	ElemType data;
	int left_flag;
	int right_flag;
	struct TBNode *left;
	struct TBNode *right;
}*ThreadedBTree;

ThreadedBTree InitThreadedBTree(void);
ThreadedBTree CreateThreadedBTreeByBTree(BTree tree);