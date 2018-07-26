#include "ExpValue.h"
/**
 * 功能模块划分:
 * 通用方法:1.获得中缀表达式 2.中缀表达式转化为后缀表达式 3.对后缀表达式进行求值计算 4.返回数据
 * 合并2,3步,不用输出后缀表达式了,直接在栈中形成数据
 * 1.使用stdin即可
 * 2.从stdin读入,对每一个字符进行判断是操作符还是数字,利用栈根据优先级表形成关于后缀表达式两个栈分别为操作数栈和操作符栈
 */

/**
 * 执行步骤
 * 初始化必要的数据结构
 * 扫描输入字符串首字符判断是字符还是操作符
 * 若是字符则进行放入字符栈
 * 若是操作符,则与当前栈顶元素进行优先级比较,如果优先级高于栈顶元素则
 */
//构造运算符优先级表,(虽然现实操作优先级高,但是在计算机运算中只有遇到)才开始回溯
char pre[7][7] ={                  
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','0','>','>'},
        {'<','<','<','<','<','0','='},
};

// a为栈顶元素,b为当前所取字符
bool compare(int a,int b,int *result);//比较两个运算符优先级
int operatevalue(int,int,int);//根据操作符种类进行运算返回结果
int  GetNext(int *n);//获取输入字符串的下一个操作符或者数据
int CalculExp();//计算表达式的主方法



bool compare(int a,int b,int *result){
	int i,j;
	switch(a){
		case '+': i = 0; break;
        case '-': i = 1; break;
        case '*': i = 2; break;
        case '/': i = 3; break;
        case '(': i = 4; break;
        case ')': i = 5; break;
        case '#': i = 6; break;
        default : i =-1; break;
	}
	switch(b){
		case '+': j = 0; break;
        case '-': j = 1; break;
        case '*': j = 2; break;
        case '/': j = 3; break;
        case '(': j = 4; break;
        case ')': j = 5; break;
        case '#': j = 6; break;
        default : j =-1; break;
	}
	//printf("top is %c,currentChar is %c\n",a,b);
	if(i==-1||j==-1) return false;
	*result = pre[i][j];
	return true;
}
int operatevalue(int a,int b,int oper){
	//char op = (char)oper;
	switch(oper){
		case '+':return a+b;
		case '-':return b-a;
		case '*':return a*b;
		case '/':
			if(a==0){
				puts("除数不能为0,运算终止");
				exit(-1);
			} else return b/a;
	}
}
int  GetNext(int *n){
	char c;
	*n = 0;
	while((c=getchar())==' ');
	if(!isdigit(c)){
		*n = c;
		return 1;//操作符flag=1
	}
	else
	do{
		*n = *n*10+(c-'0');
		c = getchar();
	}while(isdigit(c));
	ungetc(c,stdin);
	return 0;//数据返回0
}
int CalculExp(){
	ListStack exdata;//表达式数据栈
	ListStack exoper;//表达式运算符栈
	int currentChar;//存储当前被扫描表达式字符串的首字符
	int flag;
	int top;
	int leftoper,rightoper,oper;
	exdata = InitListStack();
	exoper = InitListStack();
	PushListStack(exoper,'#');
	//PushListStack(exdata,0);
	flag = GetNext(&currentChar);
	int result;//优先级比较结果
	if(!GetTopListStack(exoper,&top)){
		puts("操作符栈空,出错退出");
		exit(-1) ;
	}
	while((char)currentChar!='#' || (char)top!= '#'){

		if(flag){
			printf("取符%c,\n",currentChar);
			if(!compare(top,currentChar,&result)){
				printf("非法运算符%c\n",currentChar);
				puts("程序出现非法运算符,退出");
				exit(-1);
			}
			switch((char)result){
				case '<':
					PushListStack(exoper,currentChar);
					flag = GetNext(&currentChar);
					break;
				case '>':
					PopListStack(exdata,&leftoper);
					PopListStack(exdata,&rightoper);
					PopListStack(exoper,&oper);
					printf("取出栈顶%d\n取出栈顶%d\n",leftoper, rightoper);
					PushListStack(exdata,operatevalue(leftoper,rightoper,oper));

					//printf("计算%d+%d装入栈中%d\n", leftoper,rightoper,operatevalue(leftoper,rightoper,oper));
					break;
				case '=':
					PopListStack(exoper,&oper);
					flag = GetNext(&currentChar);
					break;
				case '0':
					puts("运算规则错误");
					exit(-1);
				default : break;
			}

			PrintStack(exdata);
		}else{
			printf("取数%d,\n",currentChar);
			PushListStack(exdata,currentChar);
			PrintStack(exdata);
			flag = GetNext(&currentChar);
		}
		GetTopListStack(exoper,&top);
	}
	int ret;//获取返回值最终结果
	GetTopListStack(exdata,&ret);
	return ret;
}


void ExpValueByStack(void){
	puts("请输入合乎规范的算术表达式");
	int ret =CalculExp();
	//getchar();
	printf("运算结果为%d\n",ret);
}