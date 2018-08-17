#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100

typedef int ElemType;


//双亲存储
typedef struct {
	ElemType data;
	int parent;
}PTNode;

typedef struct{
	PTNode nodes[MaxSize];
	int root;// location of root node
	int numbers;// numbers of nodes
}*PTree;


//child representation
typedef struct CTNode{
	int child;//child's location
	struct CTNode *next;
};
typedef struct{
	ElemType data;
	struct CTNode *firstChild;
}CTBox;

typedef struct 
{
	CTBox nodes[MaxSize];
	int root;
	int numbers;
	
}*CTree;


//parent and child representation
typedef struct PCTNode{
	int child;
	struct PCTNode *next;
};
typedef struct 
{
	ElemType data;
	int parent;
	struct PCTNode *firstChild;
}PCTBox;
typedef struct 
{
	PCTBox nodes[MaxSize];
	int root;
	int numbers;
}*PCTree;


//child and sib representation

typedef struct CSNode
{
	ElemType data;
	struct CSNode *firstChild;
	struct CSNode *rightSib;
}*CSTree;

//function

int treeHeight(CSTree tree);