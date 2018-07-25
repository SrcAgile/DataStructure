#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxSize 100

typedef int ElemType;
typedef struct
{
	ElemType datas[MaxSize];
	int top;
}SqStack;

SqStack *InitSqStack(void);
void DestorySqStack(SqStack *stack);
bool IsSqStackEmpty(SqStack *stack);
bool PushSqStack(SqStack *stack,ElemType data);
bool PopSqStack(SqStack *stack,ElemType *data);
bool GetTopSqStack(SqStack *stack,ElemType *top);