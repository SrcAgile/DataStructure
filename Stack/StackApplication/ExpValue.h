/**
 * 主要是为了表达栈锁应用的场景,本题只是解决整数表达式求值,不考虑浮点数的情况
 * 
 */
#include "../liststack/ListStack.h"
#include <ctype.h>

void ExpValueByStack(void);
ListStack InitListStack(void);
void DestoryListStack(ListStack lstack);
bool IsListStackEmpty(ListStack lstack);
bool PushListStack(ListStack lstack,ElemType data);
bool PopListStack(ListStack lstack,ElemType *data);
bool GetTopListStack(ListStack lstack,ElemType *top);