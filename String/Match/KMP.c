#include "KMP.h"
void getNext(SqString pattern,int next[]);
void getNextVal(SqString pattern,int next[]);

void getNext(SqString pattern,int next[]){
	next[0] = -1;
	int i=-1;
	int j=0;
	while(j<pattern.length){
		if(i==-1 || pattern.datas[j] == pattern.datas[i]){
			i++;
			j++;
			next[j]=i;
		}else
			i = next[i];
	}
}

void getNextVal(SqString pattern,int next[]){
	nextVal[0] = -1;
	int i=-1;
	int j=0;
	while(j<pattern.length){
		if(i==-1 || pattern.datas[j] == pattern.datas[i]){
			i++;
			j++;
			if(pattern.datas[j] == pattern.datas[i])
				nextVal[j]=nextVal[i];
			else next[j]=i;
		}else
			i = next[i];
	}
}

int patternMatchKMP(SqString target,SqString pattern){
	int next[];
	getNext(pattern,next);
	int tlen = target.length;
	int plen = pattern.length;
	for (int index = 0; index < plen; index++)
        printf("%d",next[index]);
    int i = 0 ;
    int j = 0 ;
    while (i < tlen && j < plen ) {
        if (j == -1 || target.datas[i] == pattern.datas[j]) {
            i ++ ;
            j ++ ;
        }else j = next[j] ;
    }
    if (j == plen) {
        return i - j  ;
    }else{
        return -1;
    }
}