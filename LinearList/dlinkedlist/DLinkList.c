#include "DLinkList.h"
DLinkList InitDLinkList(void){
	DLinkList dlist = (DLinkList) malloc(sizeof(DLNode));
	dlist->prior = NULL;
	dlist->next  = NULL;
	return dlist;
}
DLinkList CreateDLinkListH(ElemType numbers[], int count){
	DLinkList dlist = InitDLinkList();

	for(int i =1;i<=count;i++){
		DLinkList new = InitDLinkList();
		new->data     = numbers[i-1];
		new->next     = dlist->next;
		if(dlist->next) dlist->next->prior = new;
		new->prior  = dlist;
		dlist->next =new;
	}
	return dlist;
}
DLinkList CreateDLinkListT(ElemType numbers[], int count){
	DLinkList dlist = InitDLinkList();
	DLinkList dtail = dlist;
	for(int i=1;i<=count;i++){
		DLinkList new = InitDLinkList();
		new->data     = numbers[i-1];
		new->next     = dtail->next;
		new->prior    = dtail;
		dtail->next    = new;
		dtail          = new;
	}
	return dlist;
}
int      GetDLinkListLength(DLinkList dlist){
	int count=0;
	DLinkList dlook = dlist->next;
	for(;dlook!=NULL;count++,dlook=dlook->next);
	return count;
}
int      LocateDLinkListElem(DLinkList dlist,ElemType data){
	int counter=0;
	DLinkList dlook = dlist->next;
	for(;dlook!=NULL;dlook = dlook->next){
		counter++;
		if(dlist->data==data) return counter;
	}
	return counter;//不存在时返回末尾数值
}
bool     GetDLinkListElem(DLinkList dlist, int location,ElemType *data){
	if(location<1||location>GetDLinkListLength(dlist))
		return false;
	DLinkList dlook = dlist->next;
	for(int i=1;i<=location;i++,dlook=dlook->next);
	*data = dlook->data;
	return true;
}
bool     IsDLinkListEmpty(DLinkList dlist){
	if(GetDLinkListLength(dlist)==0)
		return true;
	return false;
}
bool     InsertDLinkList(DLinkList dlist,int location,ElemType data){
	if(location<1||location>GetDLinkListLength(dlist)+1)
		return false;
	DLinkList dlook = dlist->next;//和linklist不一样,不需要考虑第一个结点
	DLinkList new = InitDLinkList();
	new->data = data;
	if(!dlook){
		new->prior=dlist;
		dlist->next = new;
	}
	else{
		for(int i=1;i<location;dlook=dlook->next,i++);
		DLinkList pre = dlook->prior;
	
		new->next = dlook;
		dlook->prior = new;
		new->prior = pre;
		pre->next = new;
	}
	return true;
}
bool     DeleteDLinkList(DLinkList dlist,int location,ElemType *data){
	if(location<1||location>GetDLinkListLength(dlist))
		return false;
	DLinkList dlook = dlist->next;
	for(int i=1;i<location;i++,dlook = dlook->next);
	DLinkList pre = dlook->prior;
	pre->next = dlook->next;
	if(dlook->next)//出现了多级指针防止dlook->next为空
		dlook->next->prior = pre;
	free(dlook);
	return true;
}
void     PrintDLinkList(DLinkList dlist){
	DLinkList dlook = dlist->next;
	if(!dlook){
		puts("双链表为空");
		//exit(1);
	}
	else{for(int i=1;dlook!=NULL;i++,dlook=dlook->next)
		printf("第%d个结点的值为%d\n",i,dlook->data);
	}
}
void     DestroryDLinkList(DLinkList dlist){
	DLinkList go = dlist->next;
	dlist->next = NULL;
	while(go!=NULL){
		DLinkList next = go->next;
		free(go);
		go = next;
	}
}