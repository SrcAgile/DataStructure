#include "reverseSqString.h"
SqString reverseSqString(SqString string){
	if(string.length==1||string.length==0)
		return string;
	SqString result;
	result.datas[0] = string[string.length-1];
	result.length = 1;
	SqString sub = DeleteSqString(string,string.length,string.length);
	return ConcatSqString(result,reverseSqString(sub));
}