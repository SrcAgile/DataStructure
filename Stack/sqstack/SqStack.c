#include "SqStack.h"

SqStack *InitSqStack(void){
	SqStack *stack = (SqStack *)malloc(sizeof(SqStack));
	stack->top = -1;//要了解为什么设置为-1,毕竟是线性表的推广,起始位置为0
	return stack;
}
void DestorySqStack(SqStack *stack){
	free(stack);
	stack =NULL;//忘了写这一行了
}
bool IsSqStackEmpty(SqStack *stack){
	return stack->top==-1;
}
bool PushSqStack(SqStack *stack,ElemType data){
	if(stack->top==MaxSize-1)
		return false;
	stack->datas[++stack->top]=data;
	return true;
}
bool PopSqStack(SqStack *stack,ElemType *data){
	if(stack->top==-1)
		return false;
	*data = stack->datas[stack->top--];
	return true;
}
bool GetTopSqStack(SqStack *stack,ElemType *top){
	if(stack->top==-1)
		return false;
	*top = stack->datas[stack->top];
	return true;
}