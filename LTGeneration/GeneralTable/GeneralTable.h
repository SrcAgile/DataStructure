#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
/**
 *accord to the input string to Create the generallist,such as
 *"(1,2,3),4,5,(6,7,8)"
 */
typedef int ElemType;

//链式线性表结点推广
typedef struct GNode
{
	int tag;
	union{
		ElemType data;
		struct GNode *Sublist;
	}value;
	struct GNode *next;
}GeneralTable;

GeneralTable *InitGeneralTable();
GeneralTable *CreateGeneralTable(char ass[]);



int GetGeneralTableLength(GeneralTable *gt);
int GetGeneralTableDepth(GeneralTable *gt);

void PrintGeneralTable(GeneralTable *gt);