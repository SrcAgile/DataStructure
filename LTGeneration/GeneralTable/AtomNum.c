#include "AtomNum.h"

int GetAtomNumber(GeneralTable *gt){
	int numbers = 0;
	GeneralTable *next = gt;
	while(next != NULL){
		if(next->flag==1)
			numbers+=GetAtomNumber(next);
		else
			numbers++;
		next=next->next;
	}
	return numbers;
}