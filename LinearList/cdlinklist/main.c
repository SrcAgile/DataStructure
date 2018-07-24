#include "CDLinkList.h"

int main(){
	int a[7]={2,3,4,5,6,7,8};
	int ret;
	CDLinkList cdlist =  CreateCDLinkListT(a,7);
	PrintCDLinkList(cdlist);
	puts("--------------");
	printf("定位5的位置%d\n",LocateCDLinkListElem(cdlist,5));
	puts("--------------");
	InsertCDLinkList(cdlist,3,11);
	PrintCDLinkList(cdlist);
	puts("--------------");
	DeleteCDLinkList(cdlist,3,&ret);
	PrintCDLinkList(cdlist);
	puts("--------------");
	DestroryCDLinkList(cdlist);
	PrintCDLinkList(cdlist);
	puts("--------------");
	if(InsertCDLinkList(cdlist,1,5)&&InsertCDLinkList(cdlist,1,4))
		PrintCDLinkList(cdlist);
	puts("--------------");
	if(DeleteCDLinkList(cdlist,1,&ret))
		PrintCDLinkList(cdlist);
	puts("--------------");
	return 0;
}