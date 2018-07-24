#include "CLinkList.h"

int main(){
	int a[7]={2,3,4,5,6,7,8};
	int ret;
	CLinkList clist =  CreateCLinkListT(a,7);
	PrintCLinkList(clist);
	puts("--------------");
	printf("定位5的位置%d\n",LocateCLinkListElem(clist,5));
	puts("--------------");
	InsertCLinkList(clist,3,11);
	PrintCLinkList(clist);
	puts("--------------");
	DeleteCLinkList(clist,3,&ret);
	PrintCLinkList(clist);
	puts("--------------");
	DestroryCLinkList(clist);
	PrintCLinkList(clist);
	puts("--------------");
	if(InsertCLinkList(clist,1,5)&&InsertCLinkList(clist,1,4))
		PrintCLinkList(clist);
	puts("--------------");
	if(DeleteCLinkList(clist,1,&ret))
		PrintCLinkList(clist);
	puts("--------------");
	return 0;
}