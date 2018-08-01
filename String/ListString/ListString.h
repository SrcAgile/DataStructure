#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemeType;
typedef struct LSNode
{
	ElemeType data;
	struct LSNode *next;
}ListString,LSNode;

ListString *InitListString();
void AssignListString(ListString *ls, char ass[]);
ListString *InsertListString(ListString *origin,int index,ListString *new);
ListString *DeleteListString(ListString *origin,int start, int end);
ListString *ReplaceListString(ListString *origin,int start,int end,ListString *new);
int       GetListStringLength(ListString *ls);
void      PrintListString(ListString *origin);

bool      EqualListString(ListString *origin,ListString *new);
ListString *SubListString(ListString *origin,int start,int end);
ListString *CopyListString(ListString *to,ListString *from);
