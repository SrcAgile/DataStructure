#include "SqList.h"

int main(){
	int a[7]={2,3,4,5,6,7,8};
	int ret;
	SqList *sql =  CreateSqList(a,7);
	PrintSqList(sql);
	puts("--------------");
	InsertSqElem(sql,3,11);
	PrintSqList(sql);
	puts("--------------");
	DeleteSqElem(sql,3,&ret);
	PrintSqList(sql);
	return 0;
}