#include "SqStack.h"

int main(int argc, char const *argv[])
{
	int popdata;
	SqStack *stack = InitSqStack();
	if(!PopSqStack(stack,&popdata))
		puts("栈为空,无法出栈");
	else
		printf("出栈成功,数据为%d\n",popdata);

	if(PushSqStack(stack,1)&&
	PushSqStack(stack,3)&&
	PushSqStack(stack,2)&&
	PushSqStack(stack,9))
		puts("入栈成功");
	int topdata;
	GetTopSqStack(stack,&topdata);
	printf("栈顶元素为%d\n",topdata);
	return 0;
}