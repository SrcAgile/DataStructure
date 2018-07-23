/**
 * @author meta
 * @date   2018-7-20  
 */
#ifndef SQLIST_H
#define SQLIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MaxSize 100

typedef int ElemType;
typedef struct
{
	ElemType datas[MaxSize];
	int length;

} SqList;
/**
 * 初始化sqlist
 * @param  sql [传入sql指针]
 * @return     [description]
 */
SqList * InitSqList(void);
SqList * CreateSqList(ElemType datas[], int count);
void DestorySqList(SqList *sql);
/**
 * 输出顺序表的值
 * @param sql [description]
 */
void PrintSqList(SqList *sql);


bool InsertSqElem(SqList *sql,int location,ElemType data);
bool DeleteSqElem(SqList *sql,int location,ElemType *data);
bool getSqElem(SqList *sql,int location,ElemType *data);
/*
	不存在返回最后一个位置
 */
int locateSqElem(SqList *sql,ElemType data);
int GetSqLength(SqList *sql);
bool IsSqEmpty(SqList *sql);



#endif