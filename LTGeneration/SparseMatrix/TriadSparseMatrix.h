#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MaxSize 500
#define Row 20
#define Col 20

typedef int ElemType;

typedef struct{
	int row;
	int col;
	ElemType data;
}TupNode;//三元组结点

typedef struct{
	int rows;
	int cols;
	int numbers;
	TupNode data[MaxSize];
}TSMatrix;//定义三角稀疏矩阵整体

void createTSMatrix(TSMatrix *matrix,ElemType data[Row][Col],int row,int col);
bool AssignValueTSMatrix(TSMatrix *matrix,ElemType element,int row,int col);
bool AssignToElement(TSMatrix matrix,ElemType *element,int row,int col);
void PrintTSMatrix(TSMatrix matrix);
void TranTSMatrix(TSMatrix matrix,TSMatrix *matrixResult);


