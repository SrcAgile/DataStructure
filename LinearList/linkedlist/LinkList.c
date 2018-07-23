#include "LinkList.h"

LinkList InitLinkList(void){
	LinkList list = (LinkList)malloc(sizeof(LNode));
	list->next    = NULL;
	return list;
}
LinkList CreateLinkListH(ElemType numbers[], int count){
	LinkList head = InitLinkList();
	for(int i=0;i<count;i++){
		LinkList new = InitLinkList();
		new->data    = numbers[i];
		new->next    = head->next;
		head->next   = new;
	}
	return head;
}
LinkList CreateLinkListT(ElemType numbers[], int count){
	LinkList head = InitLinkList();
	LinkList tail = head;
	for(int i = 0;i<count;i++){
		LinkList new = InitLinkList();
		new->data = numbers[i];
		new->next    = tail->next;
		tail->next   = new;
		tail         = new;
	}
	return head;
}
int      GetLinkListLength(LinkList list){
	int i         = 0;
	LinkList look = list->next;
	for(;look!=NULL;i++,look = look->next);
	return i;
}
int      LocateLinkListElem(LinkList list,ElemType data){
	int i = 0;
	LinkList look = list->next;
	for(;look!=NULL;i++){
		if(look->next->data==data)
			return i;
		look = look->next;
	}
	return i;
}
bool     GetLinkListElem(LinkList list, int location,ElemType *data){
	if(location<1||location>GetLinkListLength(list))
		return false;
	int i = 0;
	LinkList look = list->next;
	for(;i<location;i++,look = look->next);
	*data = look->data;
	return true;
}
bool     IsLinkListEmpty(LinkList list){
	if(GetLinkListLength(list)==0)
		return true;
	return false;
}
bool     InsertLinkList(LinkList list,int location,ElemType data){
	if(location<1||location>GetLinkListLength(list)+1)
		return false;
	int i = 1;
	//LinkList look = list->next;这样做无法在第一个结点前插入数据
	LinkList look = list;
	for(;i<location;look=look->next,i++);
	LinkList new = InitLinkList();
	new->data = data;
	new->next = look->next;
	look->next = new;
	return true;
}
bool     DeleteLinkList(LinkList list,int location,ElemType *data){
	if(location<1||location>GetLinkListLength(list)+1)
		return false;
	int i = 1;
	//LinkList look = list->next;
	LinkList look = list;
	for(;i<location;look=look->next,i++);
	LinkList delete = look->next;
	look->next = delete->next;
	free(delete);
	return true;
}
void     PrintLinkList(LinkList list){
	if(GetLinkListLength(list)==0)
		puts("当前链表数据为空");
	else{
		LinkList look = list->next;
		for(int i=0;look!=NULL;i++){
			printf("第%d个节点的数值为%d\n",i+1,look->data);
			look = look->next;
		}
	}
}
void     DestroryLinkList(LinkList list){
	LinkList look = list->next;
	list->next = NULL;
	if(!look) exit(1);
	LinkList nex; //= list->next;
	while(look!=NULL){
		nex = look->next;
		free(look);
		look = nex;
	}
	free(look);
}