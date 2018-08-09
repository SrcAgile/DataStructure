#include "TriadSparseMatrix.h"

void createTSMatrix(TSMatrix *matrix,ElemType data[Row][Col],int row,int col){
	matrix->cols = col;
	matrix->rows = row;
	for(int i = 0;i<row; i++){
		for(int j = 0;i<col; j++){
			if(data[i][j]!=0){
				TupNode node = {i,j,data[i][j]};
				matrix->data[matrix->numbers++] = data;
			}
		}
	}
}
bool AssignValueTSMatrix(TSMatrix *matrix,ElemType element,int row,int col){
	//此函数等同insert函数,row取0-matrix->rows-1
	if(row>=matrix->rows||col>=matrix->cols ||row<0||col<0)
		return false;
	int location = 0;
	while(location<matrix->numbers&&matrix->data[location].row<row){
		location++;//自加到第row行初始位置
	}
	//疑问:以下两种'或条件'不是子集关系吗?
	//解决:三元组的最后一个结点
	if(location == matrix->numbers || matrix->data[location].row>row){
		for(int i = matrix->numbers; i>= location+1;i--){
			matrix->data[i] = matrix->data[i-1];
		}
		TupNode dataNode = {row,col,element};
		matrix->data[location] = dataNode;
		matrix->numbers++;
		return true;
	}else {
        while (location < matrix->numbers && matrix->data[location].row == row && matrix->data[location].col < col) {
            location ++ ;
        }
        if (location < matrix->numbers && matrix->data[location].row == row && matrix->data[location].col == col) {
            matrix->data[location].data = element ;
            return true ;
        }else{
            for (int i = matrix->numbers ; i>= location + 1; i--) {
                matrix->data[i] = matrix->data[i-1] ;
            }
            TupNode dataNode = {row,col,element};
            matrix->data[location] =  dataNode ;
            matrix->numbers ++ ;
            return true ;
        }
    }

}
bool AssignToElement(TSMatrix matrix,ElemType *element,int row,int col);
void PrintTSMatrix(TSMatrix matrix){
	printf("%d行 %d列 %d个元素\n",matrix.rows,matrix.cols,matrix.numbers) ;
    for (int i = 0; i<matrix.numbers; i++) {
        if (i != 0 && matrix.data[i].row != matrix.data[i - 1].row) {
            printf("\n") ;
        }
        printf("(%d,%d,%d)  ",matrix.data[i].row,matrix.data[i].col,matrix.data[i].data);
    }
    printf("\n") ;
}
void TranTSMatrix(TSMatrix matrix,TSMatrix *matrixResult)
{
	 matrixResult->numbers = 0;
    matrixResult->cols = matrix.rows;
    matrixResult->rows = matrix.cols;
    for (int i = 0; i<matrix.cols; i++) {
        for (int j = 0;j<matrix.numbers; j++) {
            if (matrix.data[j].col == i) {
                matrixResult->numbers ++ ;
                TupNode dataNode = {matrix.data[j].col,matrix.data[j].row,matrix.data[j].data};
                matrixResult->data[matrixResult->numbers - 1] = dataNode ;
            }
        }
    }
}
