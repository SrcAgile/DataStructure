#include "ListStack.h"
ListStack InitListStack(void){
	ListStack lstack = (ListStack)malloc(sizeof(LSNode));
	lstack->next = NULL;
	return lstack;
}
void DestoryListStack(ListStack lstack);
bool IsListStackEmpty(ListStack lstack){
	if (!lstack->next)
		return true;
	return false;
}
bool PushListStack(ListStack lstack,ElemType data){
	//不用考虑栈满情况
	ListStack new = InitListStack();
	new->data = data;
	new->next = lstack->next;
	lstack->next = new;
	return true;
}
bool PopListStack(ListStack lstack,ElemType *data){
	if(IsListStackEmpty(lstack))
		return false;
	ListStack next = lstack->next;
	lstack->next = next->next;
	free(next);
	return true;
}
bool GetTopListStack(ListStack lstack,ElemType *top){
	if(IsListStackEmpty(lstack))
		return false;
	*top = lstack->next->data;
	return true;
}