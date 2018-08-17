#include <stdio.h>
#include "HuffmanTree.h"

#define CodeLength 10

typedef struct 
{
	ElemType code[CodeLength];
	int StartIndex;
}HuffmanCode;

void CreateHuffmanCode(HuffmanTree tree[],HuffmanCode code[], int numbers);