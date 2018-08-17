#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct 
{
	ElemType data;
	double weight;
	int parent;
	int left;
	int right;
	
}HuffmanTree;

void CreateHuffmanTree(HuffmanTree tree[],int numbers);