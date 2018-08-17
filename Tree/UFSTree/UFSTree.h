#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM 100

typedef struct{
	int data;
	int rank;//秩
	int parent;
}*UFSTree;

void InitUFSTree(UFSTree tree[NUM]);
int FindInUFS(UFSTree tree[NUM],int elem);
void UnionUFSTree(UFSTree tree[NUM],int one,int two);