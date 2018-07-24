#include "CDLinkList.h"

CDLinkList InitCDLinkList(void){
	CDLinkList cdlist = (CDLinkList)malloc(sizeof(CDLNode));
	cdlist->prior = cdlist;
	cdlist->next = cdlist;
	return cdlist;
}
CDLinkList CreateCDLinkListH(ElemType numbers[], int count){
	CDLinkList cdlist = InitCDLinkList();
	for(int i=0;i<count;i++){
		CDLinkList new  = InitCDLinkList();
		new->data = numbers[i];
		new->next = cdlist->next;
		cdlist->next->prior = new;//解决了DLinkList中cdlist->next出现NULL->next的问题
		new->prior = cdlist;
		cdlist->next = new;
	}
	return cdlist;
}
CDLinkList CreateCDLinkListT(ElemType numbers[], int count){
	CDLinkList cdlist = InitCDLinkList();
	//the following codes could be writted with  
	//'cdlist->next = cdlist;cdlist->prior=cdlist;cdlinklist cdtail=cdlist'
	//as for why didn't i write code like this because i want express the meaning of tail pointer...
	CDLinkList cdtail = cdlist;
	cdtail->prior = cdlist;
	cdlist->next = cdtail;

	for(int i=0;i<count;i++){
		CDLinkList new = InitCDLinkList();
		new->data = numbers[i];
		new->next = cdtail->next;
		cdtail->next->prior = new;//摆脱dlinklist的困境
		new->prior = cdtail;
		cdtail->next = new;
		cdtail = new;
	}
	return cdlist;
}
int      GetCDLinkListLength(CDLinkList cdlist){
	CDLinkList cdlook = cdlist->next;
	int i=0;
	for(;cdlook!=cdlist;i++,cdlook=cdlook->next);
	return i;
}
int      LocateCDLinkListElem(CDLinkList cdlist,ElemType data){
	CDLinkList cdlook = cdlist->next;
	int i=0;
	for(;cdlook!=cdlist;cdlook=cdlook->next){
		i++;
		if(cdlook->data==data)
			return i;
	}
	return i;//不存在返回最后一个值
}
bool     GetCDLinkListElem(CDLinkList cdlist, int location,ElemType *data){
	if(location<1||location>GetCDLinkListLength(cdlist))
		return false;

	CDLinkList cdlook = cdlist->next;
	for(int i=1;i<location;i++,cdlook=cdlook->next);
	*data = cdlook->data;
	return true;
}
bool     IsCDLinkListEmpty(CDLinkList cdlist){
	if(GetCDLinkListLength(cdlist)==0)
		return true;
	return false;
}
bool     InsertCDLinkList(CDLinkList cdlist,int location,ElemType data){
	if(location<1||location>GetCDLinkListLength(cdlist)+1)
		return false;
	CDLinkList cdlook = cdlist;
	for(int i=1;i<location;i++,cdlook=cdlook->next);
	//不用担心->next==NULL这种情况,大胆写吧
	CDLinkList new = InitCDLinkList();
	new->data = data;
	new->next = cdlook->next;
	cdlook->next->prior = new;
	new->prior=cdlook;
	cdlook->next = new;
	return true;
}
bool     DeleteCDLinkList(CDLinkList cdlist,int location,ElemType *data){
	if(location<1||location>GetCDLinkListLength(cdlist))
		return false;
	CDLinkList cdlook = cdlist;
	for(int i=1;i<location;i++,cdlook=cdlook->next);
	CDLinkList cdnext = cdlook->next;
	cdnext->next->prior = cdlook;
	cdlook->next = cdnext->next;
	free(cdnext);
	return true;
}
void     PrintCDLinkList(CDLinkList cdlist){
	int i=1;
	CDLinkList cdlook = cdlist->next;
	for(;cdlook!=cdlist;i++,cdlook=cdlook->next)
		printf("第%d个数值为%d\n",i,cdlook->data);
}
void     DestroryCDLinkList(CDLinkList cdlist){
	CDLinkList next = cdlist->next;
	cdlist->next = cdlist;
	cdlist->prior= cdlist;
	while(next!=cdlist){
		CDLinkList nnext = next->next;
		free(next);
		next = nnext;
	}
}