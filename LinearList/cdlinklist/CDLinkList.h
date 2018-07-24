#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int ElemType;
typedef struct  CDLNode
{
	ElemType data;
	struct CDLNode *prior;
	struct CDLNode *next;
}*CDLinkList,CDLNode;
CDLinkList InitCDLinkList(void);
CDLinkList CreateCDLinkListH(ElemType numbers[], int count);
CDLinkList CreateCDLinkListT(ElemType numbers[], int count);
int      GetCDLinkListLength(CDLinkList cdlist);
int      LocateCDLinkListElem(CDLinkList cdlist,ElemType data);
bool     GetCDLinkListElem(CDLinkList cdlist, int location,ElemType *data);
bool     IsCDLinkListEmpty(CDLinkList cdlist);
bool     InsertCDLinkList(CDLinkList cdlist,int location,ElemType data);
bool     DeleteCDLinkList(CDLinkList cdlist,int location,ElemType *data);
void     PrintCDLinkList(CDLinkList cdlist);
void     DestroryCDLinkList(CDLinkList cdlist);