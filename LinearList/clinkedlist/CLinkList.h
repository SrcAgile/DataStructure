#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int ElemType;
typedef struct  CLNode
{
	ElemType data;
	struct CLNode *next;
}*CLinkList,CLNode;
CLinkList InitCLinkList(void);
CLinkList CreateCLinkListH(ElemType numbers[], int count);
CLinkList CreateCLinkListT(ElemType numbers[], int count);
int      GetCLinkListLength(CLinkList clist);
int      LocateCLinkListElem(CLinkList clist,ElemType data);
bool     GetCLinkListElem(CLinkList clist, int location,ElemType *data);
bool     IsCLinkListEmpty(CLinkList clist);
bool     InsertCLinkList(CLinkList clist,int location,ElemType data);
bool     DeleteCLinkList(CLinkList clist,int location,ElemType *data);
void     PrintCLinkList(CLinkList clist);
void     DestroryCLinkList(CLinkList clist);