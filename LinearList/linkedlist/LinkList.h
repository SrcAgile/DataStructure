#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int  ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}*LinkList,LNode;

LinkList InitLinkList(void);
LinkList CreateLinkListH(ElemType numbers[], int count);
LinkList CreateLinkListT(ElemType numbers[], int count);
int      GetLinkListLength(LinkList list);
int      LocateLinkListElem(LinkList list,ElemType data);
bool     GetLinkListElem(LinkList list, int location,ElemType *data);
bool     IsLinkListEmpty(LinkList list);
bool     InsertLinkList(LinkList list,int location,ElemType data);
bool     DeleteLinkList(LinkList list,int location,ElemType *data);
void     PrintLinkList(LinkList list);
void     DestroryLinkList(LinkList list);
