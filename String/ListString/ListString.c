#include "ListString.h"


ListString *InitListString(){
	ListString *ls = (ListString *)malloc(sizeof(LSNode));
	ls->next = NULL;
	return ls;
}
void AssignListString(ListString *ls, char ass[]){
	ListString tail=ls;
	for (int i = 0; ass[i]!='\0'; ++i)
	{
		ListString *data = InitListString();
		data->data = ass[i];
		tail->next = data;
		tail = data;
	}
}
ListString *InsertListString(ListString *origin,int index,ListString *new){
	ListString *retu=InitListString();
	ListString *tail = retu;
	if(index<1||index>GetListStringLength(origin)+1)
		return retu;
	ListString *front=origin->next;
	for(int i=0;i<index-1;i++){
		ListString *in = InitListString();
		in->data =  front->data;
		in->next = tail->next;
		tail->next = in;
		tail = in;
		front = front->next;
	}
	ListString *newf = new->next;
	while(newf!=NULL){
		ListString *in = InitListString();
		in->data =  newf->data;
		in->next = tail->next;
		tail->next = in;
		tail = in;
		fnewf = newf->next;
	}
	while(front!=NULL){
		ListString *in = InitListString();
		in->data =  front->data;
		in->next = tail->next;
		tail->next = in;
		tail = in;
		front = front->next;
	}
	return retu;
}
ListString *DeleteListString(ListString *origin,int start, int end){
	ListString *retu=InitListString();
	ListString *tail = retu;
	if(start<1||start>GetListStringLength(origin)||start<end||end>GetListStringLength(origin))
		return retu;
	ListString *next = orgin->next;
	for(int i=0;i<start-1;i++){
		ListString *new = InitListString();
		new->data = next->data;
		new->next = tail->next;
		tail->next = new;
		tail = new;
		next =  next->next;
	}
	for(int i=start;i<=end;i++;next = next->next);
	while(next!=NULL){
		ListString *new = InitListString();
		new->data = next->data;
		new->next = tail->next;
		tail->next = new;
		tail = new;
		next =  next->next;
	}
	return retu;

}
ListString *ReplaceListString(ListString *origin,int start,int end,ListString *new){
	//emit
}
int       GetListStringLength(ListString *ls){
	ListString next = ls->next;
	int count=0;
	while(next!=NULL){
		count++;
		next = next->next;
	}
	return count;
}
void      PrintListString(ListString *origin){
	//emit
}

bool      EqualListString(ListString *origin,ListString *new){
	//emit
}
ListString *SubListString(ListString *origin,int start,int end){
	//EMIT
}
ListString *CopyListString(ListString *to,ListString *from){
	//emit
}

