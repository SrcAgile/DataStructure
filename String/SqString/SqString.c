#include "SqString.h"

SqString * InitSqString(){
	SqString *origin = (SqString *)malloc(sizeof(SqString));
	origin->length = 0;
	return origin;
}
void AssignSqString(SqString *origin, char ass[]){
	int i = 0;
	for(;ass[i]!='\0'&&i<MaxSize;i++)
		origin->datas[i] = ass[i];
	origin->length = i;
}
SqString InsertSqString(SqString origin,int index,SqString new){
	SqString result;
	if(index<1||index>origin.length+1||origin.length+new.length>MaxSize){
		puts("插入位置有误或超出顺序串最大限制");
		result.length=0;
		return result;
	}
	for(int i=0;i<index-1;i++)
		result.datas[i]=origin[i];
	for(int i=index-1;i<origin.length;i++)
		result.datas[i+new.length]=origin[i];
	for (int i = index-1; i <new.length ; ++i)
		result.datas[i]= new.datas[i+1-index];
	result.length = origin.length+new.length;
	return result;
}
SqString DeleteSqString(SqString origin,int start,int end){
	SqString result;
	if(start<end||start<1||start>origin.length||end>origin.length){
		result.length=0;
		return result;
	}
	for(int i=0;i<start-1;i++)
		result.datas[i]=origin.datas[i];
	for(int i=end-1;i<origin.length-1;i++)
		result.datas[i-end+start]=result.datas[i];
	for (int i = end-1 i < origin.length; ++i)
		result.datas[i]=origin.datas[i];
	result.length-=start-end+1;
	return result;
}
SqString RepalceSqString(SqString origin,int start,int end,SqString new){
	SqString result;
	if(start<end||start<1||start>origin.length||end>origin.length||new.length<end-start+1){
		result.length=0;
		return result;
	}
	for(int i=0;i<start-1;i++)
		result.datas[i]=origin.datas[i];
	for (int i =start-1; i < end; ++i)
		result.datas[i] = new.datas[i+1-start];
	for (int i = end-1 i < origin.length; ++i)
		result.datas[i]=origin.datas[i];
	result.length = origin.length;
	return result;
}
SqString PrintSqString(SqString origin){
	printf("==>");
	for (int i = 0; i < origin.length; ++i)
	{
		printf("%d--.",origin.datas[i] );
	}
	printf("|");
}
int      GetSqStringLength(SqString origin){
	return origin;
}

//expand LinearList complete 
SqString ContactSqString(SqString origin,SqString new);//连接
SqString SubSqString(SqString origin,int start, int end);//求子串
void     SqStringCopy(SqString *toString,SqString fromString);//串复制
bool     SqStringEqual(SqString origin,SqString new);

//expand SqString

int StrCmpSqString(SqString origin,SqString new){
	if(origin.length==new.length){
		for(int i=0;i<origin.length;i++){
			if(origin.datas[i]>new.datas[i])
				return 1;
			if(origin.datas[i]<new.datas[i])
				return -1;
		}
		return 0;
	}
	else if(origin.length>new.length)
		return 1;
	else
		return -1;
}
void FindMaxContinousSqString(SqString origin,int *index,int MaxLength){
	if(origin.length==0){
		*index=0;
		*MaxLength=0;
		return;
	}
	int maxlen=1,temlen=1;
	int maxindex=0,temindex=0;
	int count=0;
	while(count<origin.length){
		if(origin.datas[count]==origin.datas[count+1]){
			temlen++;
		}else{
			if(temlen>maxlen){
				maxlen = temlen;
				maxindex = temindex;
			}
			temindex = count;
			temlen = 1;
		}
		count++;
	}
	*index = count+1;
	*MaxLength = maxlen;
}