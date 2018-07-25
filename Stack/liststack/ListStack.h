#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;
typedef struct LSNode
{
	ElemType data;
	struct LSNode *next;
}*ListStack,LSNode;

ListStack InitListStack(void);
void DestoryListStack(ListStack lstack);
bool IsListStackEmpty(ListStack lstack);
bool PushListStack(ListStack lstack,ElemType data);
bool PopListStack(ListStack lstack,ElemType *data);
bool GetTopListStack(ListStack lstack,ElemType *top);