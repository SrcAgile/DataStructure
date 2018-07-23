/**
 * 相比于linklist的优势:
 * 在linklist中操作一个结点需要找到它的前驱结点,虽然看起来似乎在扫描过程中直接-1即可,但是对于
 * 边界的问题不方便处理,像第一个结点就没有前驱结点,当然如果你引入头结点的话当另当别论,再怎么说
 * linklist的缺点描述起来不明确还不如说dlinklist的优点
 *
 *  重点看如下信息
 * 优点:操作每一个元素结点的时候不需要考虑其前驱或后继结点的信息,因为其前驱或后继结点的信息都存储在其自身节点中
 * 这样每个结点在操作时是独立的,不依赖前驱或后继结点,所有的结点的操作是等同的,不存在边界结点的不同处理方案
 * 需要注意的是,虽然操作结点包含前后结点的信息,但是有一种特殊的结点叫做NULL
 *
 * pre->current->null
 * 则当使用current->next->prior时会出现错误
 * 由此看来,头结点的引入就是为了让所有结点操作起来具有等同性
 *
 *
 * 

 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int  ElemType;
typedef struct DLNode{
	ElemType data;
	struct DLNode *prior;
	struct DLNode *next;
}*DLinkList,DLNode;

DLinkList InitDLinkList(void);
DLinkList CreateDLinkListH(ElemType numbers[], int count);
DLinkList CreateDLinkListT(ElemType numbers[], int count);
int      GetDLinkListLength(DLinkList dlist);
int      LocateDLinkListElem(DLinkList dlist,ElemType data);
bool     GetDLinkListElem(DLinkList dlist, int location,ElemType *data);
bool     IsDLinkListEmpty(DLinkList dlist);
bool     InsertDLinkList(DLinkList dlist,int location,ElemType data);
bool     DeleteDLinkList(DLinkList dlist,int location,ElemType *data);
void     PrintDLinkList(DLinkList dlist);
void     DestroryDLinkList(DLinkList dlist);
