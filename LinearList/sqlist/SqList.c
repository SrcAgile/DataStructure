#include "SqList.h"

SqList * InitSqList(void){
	SqList *sql;
	while(!(sql = (SqList *)malloc(sizeof(SqList))));
	sql->length=0;
	return sql;
}
void DestorySqList(SqList *sql){
	free(sql);
}

SqList * CreateSqList(ElemType datas[], int count){
	SqList*sql = InitSqList();
	for(int i = 0;i<count;i++)
		sql->datas[i] = datas[i];
	sql->length+=count;
}

void PrintSqList(SqList *sql){
	for(int i =0;i<sql->length;i++)
		printf("第%d个是%d\n",i+1,sql->datas[i]);
}

/*
	这里的参数合法性判断老是出错
 */
bool InsertSqElem(SqList *sql,int location,ElemType data){
	int i;
	if(location<1||location>GetSqLength(sql)+1)
		return false;
	else if(GetSqLength(sql)==MaxSize)
		return false;
	else{
		for(i=GetSqLength(sql);i>=location;i--)
			sql->datas[i]=sql->datas[i-1];
		sql->datas[i]=data;
		sql->length++;
		return true;
	}

}
bool DeleteSqElem(SqList *sql,int location,ElemType *data){
	if(location<1||location>GetSqLength(sql))
		return false;
	*data = sql->datas[location-1];
	for(int i=location;i<GetSqLength(sql);i++)
		sql->datas[i-1]=sql->datas[i];
	sql->length--;
	return true;
}
bool getSqElem(SqList *sql,int location,ElemType *data){
	if(location<1||location>GetSqLength(sql))
		return false;
	*data = sql->datas[location-1];
	return true;
}

int locateSqElem(SqList *sql,ElemType data){
	for(int i =0;i<GetSqLength(sql);i++)
		if(sql->datas[i]==data)
			return i+1;
	return GetSqLength(sql);

}
int GetSqLength(SqList *sql){
	return sql->length;
}
bool IsSqEmpty(SqList *sql){
	if(GetSqLength(sql)==0)
		return true;
	else
		return false;
}