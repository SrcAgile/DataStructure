#include "CLinkList.h"

CLinkList InitCLinkList(void){
	CLinkList clist = (CLinkList)malloc(sizeof(CLNode));
	clist->next=NULL;
	return clist;
}
CLinkList CreateCLinkListH(ElemType numbers[], int count){
	CLinkList clist = InitCLinkList();
	clist->next = clist;//构造初始环
	for(int i=0;i<count;i++){
		CLinkList new = InitCLinkList();
		new->data = numbers[i];
		new->next = clist->next;
		clist->next = new;
	}
	return clist;

}
CLinkList CreateCLinkListT(ElemType numbers[], int count){
	CLinkList clist = InitCLinkList();
	//构造初始化环
	CLinkList ctail = clist;
	ctail->next = clist;
	for(int i=0;i<count;i++){
		CLinkList new = InitCLinkList();
		new->data = numbers[i];
		new->next = ctail->next;
		ctail->next = new;
		ctail = new;
	}
	return clist;

}
int      GetCLinkListLength(CLinkList clist){
	CLinkList clook = clist->next;
	int count=0;
	for(;clook!=clist;count++,clook=clook->next);
	return count;
}
int      LocateCLinkListElem(CLinkList clist,ElemType data){
	CLinkList clook = clist->next;
	int count=0;
	for(;clook!=clist;clook=clook->next){
		count++;
		if (clook->data == data)
			return count;
	}
	return count;//不存在则返回队尾数值
}
bool     GetCLinkListElem(CLinkList clist, int location,ElemType *data){
	if(location<1||location>GetCLinkListLength(clist))
		return false;
	CLinkList clook = clist->next;
	int count=1;
	for(;count<location;clook=clook->next);
	*data = clook->data;
	return true;
}
bool     IsCLinkListEmpty(CLinkList clist){
	if(GetCLinkListLength(clist)==0)
		return true;
	return false;
}
bool     InsertCLinkList(CLinkList clist,int location,ElemType data){
	if(location<1||location>GetCLinkListLength(clist)+1)
		return false;
	CLinkList clook = clist;
	for(int i=1;i<location;i++,clook=clook->next);
	CLinkList new = InitCLinkList();
	new->data = data;
	new->next = clook->next;
	clook->next = new;
	return true;
}
bool     DeleteCLinkList(CLinkList clist,int location,ElemType *data){
	if(location<1||location>GetCLinkListLength(clist))
		return false;
	CLinkList clook = clist;
	for(int i=1;i<location;i++,clook=clook->next);
	CLinkList cnext = clook->next;
	clook->next = cnext->next;
	free(cnext);
	return true;
}
void     PrintCLinkList(CLinkList clist){
	CLinkList clook = clist->next;
	if(!clook) return;
	for(int i=1;clook!=clist;i++,clook = clook->next)
		printf("第%d个结点的值为%d\n",i,clook->data);
}
void     DestroryCLinkList(CLinkList clist){
	CLinkList cnext = clist->next;
	clist->next = clist;
	while(cnext!=clist){
		CLinkList nnext = cnext->next;
		free(cnext);
		cnext = nnext;
	}
}