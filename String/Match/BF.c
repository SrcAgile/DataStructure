#include "BF.h"

int patternMatchBF(SqString target,SqString pattern){
	int i=0;j=0;
	for(;i<target.length;i++){
		for(int k=i;j<pattern.length;){
			if(target[k]==pattern[j]){k++;j++};
			else break;
		}
		if(j==pattern.length) return i;
	}
	return -1;
}