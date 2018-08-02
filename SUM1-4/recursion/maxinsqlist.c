#include "maxinsqlist.h"
#define max(a,b) (((a) > (b)) ? (a) : (b))

int MaxInSqList(SqList list,int start,int end){
	if(start==end)
		return list[start];
	return max(MaxInSqList(list,start,(end-start)/2),MaxInSqList(list,(end-start)/2)+1,end));
}