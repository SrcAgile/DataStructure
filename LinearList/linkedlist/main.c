#include "LinkList.h"

int main(){
	int a[7]={2,3,4,5,6,7,8};
	int ret;
	LinkList list =  CreateLinkListT(a,7);
	PrintLinkList(list);
	puts("--------------");
	
	InsertLinkList(list,3,11);
	PrintLinkList(list);
	puts("--------------");
	DeleteLinkList(list,3,&ret);
	PrintLinkList(list);
	puts("--------------");
	DestroryLinkList(list);
	PrintLinkList(list);
	puts("--------------");
	if(InsertLinkList(list,1,5)&&InsertLinkList(list,1,4))
		PrintLinkList(list);
	puts("--------------");
	if(DeleteLinkList(list,1,&ret))
		PrintLinkList(list);
	puts("--------------");
	return 0;
}