#include "DLinkList.h"

int main(){
	int a[7]={2,3,4,5,6,7,8};
	int ret;
	DLinkList list =  CreateDLinkListT(a,7);
	PrintDLinkList(list);
	puts("--------------");
	
	InsertDLinkList(list,3,11);
	PrintDLinkList(list);
	puts("--------------");
	DeleteDLinkList(list,3,&ret);
	PrintDLinkList(list);
	puts("--------------");
	DestroryDLinkList(list);
	PrintDLinkList(list);
	puts("--------------");
	if(InsertDLinkList(list,1,5)&&InsertDLinkList(list,1,4))
		PrintDLinkList(list);
	puts("--------------");
	if(DeleteDLinkList(list,1,&ret))
		PrintDLinkList(list);
	puts("--------------");
	if(DeleteDLinkList(list,1,&ret))
		PrintDLinkList(list);
	puts("--------------");
	return 0;
}