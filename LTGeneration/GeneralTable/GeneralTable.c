#include "GeneralTable.h"
GeneralTable *CreateGeneralTableByRecursive(char ass[],int *count);



GeneralTable *InitGeneralTable(){
	GeneralTable *gt = (GeneralTable *)malloc(sizeof(GNode));
	gt->next = NULL;
	gt->flag = 1;//list flag
	gt->value.Sublist = NULL;
	return list;
}
GeneralTable *CreateGeneralTable(char ass[]){
	int count = 0;
	return CreateGeneralTableByRecursive(ass,&count);
}

GeneralTable *CreateGeneralTableByRecursive(char ass[],int *count){
	GeneralTable *node   = InitGeneralTable();
	GeneralTable *next = node;
	while(ass[i]!='\0'){//scan string
		if(ass[*count]=='('){//遇见'('递归展开
			next->tag = 1;
			*count +=1;
			next->value.Sublist = CreateGeneralTableByRecursive(ass,count);
		}else if(ass[*count]==')'){
			next->next = NULL;
			return node;
		}else if(ass[*count]==','){
			GeneralTable *data = InitGeneralTable();
			next->next = data;
			next->next = next;
		}else if(ass[*count] == '#'){
			*count+=1;
			return NULL;//空集
		}else{
			next.tag = 0;
			next->value.data = ass[*count]-'0';
		}
		*count+=1;
	}
	return node;
}


int GetGeneralTableLength(GeneralTable *gt){
	GeneralTable *Sublist = gt->value.Sublist;
	int count = 0;
	while(Sublist != NULL){
		count++;
		Sublist = Sublist->next;
	}
	return count;
}
int GetGeneralTableDepth(GeneralTable *gt){
	int max=-1;
	GeneralTable *next = gt;
	while(next != NULL){
		if(next->tag == 1){
			int deep = GetGeneralTableDepth(next->value.Sublist);
			if(deep > max)
				max = deep;
		}
		next = next->next;
	}
	return max+1;
}

void PrintGeneralTable(GeneralTable *gt){
	GeneralTable *next = gt;
	if(gt == NULL)
		printf("#\n");
	while(next!=NULL){
		if(next->tag == 0){
			printf("%c",next->value.data);
		}else{
			printf("(");
			PrintGeneralTable(next->value.Sublist);
			printf(")");
		}
		next = next->next;
		if(next!=NULL){
			printf(",");
		}
	}
}