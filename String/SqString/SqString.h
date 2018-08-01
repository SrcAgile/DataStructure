/**
 * 无非是线性表的操作拓展,修改点方法,
 * 还要注意的是很多操作都不是原地操作,前边的改动性操作都使用bool当做返回类型,原因是基于原地操作的
 * 所以我们不适用bool了
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MaxSize 100
typedef int Elemtype;
typedef struct 
{
	Elemtype datas[MaxSize];
	int length;
}SqString;

//base
SqString * InitSqString();
void AssignSqString(SqString *origin, char ass[]);
SqString InsertSqString(SqString origin,int index,SqString new);
SqString DeleteSqString(SqString origin,int start,int end);
SqString RepalceSqString(SqString origin,int start,int end,SqString new);
SqString PrintSqString(SqString origin);
int      GetSqStringLength(SqString);

//expand LinearList
SqString ContactSqString(SqString origin,SqString new);//连接
SqString SubSqString(SqString origin,int start, int end);//求子串
void     SqStringCopy(SqString *toString,SqString fromString);//串复制
bool     SqStringEqual(SqString origin,SqString new);

//expand SqString

int StrCmpSqString(SqString origin,SqString new);
void FindMaxContinousSqString(SqString origin,int *index,int MaxLength);
//设计一个算法，求串s中出现的第一个最长的连续相同字符构成的平台,返回所在位置和最大长度