#include "ListStack.h"

int main(int argc, char const *argv[])
{
	int popdata;
	ListStack lstack = InitListStack();
	if(!PopListStack(lstack,&popdata))
		puts("栈为空,无法出栈");
	else
		printf("出栈成功,数据为%d\n",popdata);

	if(PushListStack(lstack,1)&&
	PushListStack(lstack,3)&&
	PushListStack(lstack,2)&&
	PushListStack(lstack,9))
		puts("入栈成功");
	int topdata;
	GetTopListStack(lstack,&topdata);
	printf("栈顶元素为%d\n",topdata);
	return 0;
}